# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>

# define OVERFLOW  -2 
# define LISTINCREMENT 10 
# define TRUE 1
# define FALSE 0
# define OK   1
# define LIST_INIT_SIZE 100 
# define ERROR 0  
typedef struct {
	int * elem ;
	int length ;
	int sizeoflist ;
} Sqlist ;
typedef int Status ;
typedef int ElemType ;

int  ListLength(Sqlist la);
void GetElem(Sqlist la , int i , int * e);
void unionlist (Sqlist  * la, Sqlist lb);
Status equal(int a , int b);
Status   LocateList(Sqlist  la, int e , int (* p)(int a, int b));
Status InsertList(Sqlist * la, int i  , int e);
void print(Sqlist la);

int main(){
	Sqlist la ;
	Sqlist lb ;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10] = {3,4,5,0,7,8,9,0,12,23};
	la.elem = a ;
	lb.elem = b ;
	la.length = 10 ;
	lb.length = 10 ;
	la.sizeoflist = LIST_INIT_SIZE ;
	lb.sizeoflist = LIST_INIT_SIZE ;
	unionlist(&la, lb);
	print(la);
	return 0 ;
}

void unionlist (Sqlist  * la, Sqlist lb){
	int la_len = ListLength(*la);
	int lb_len = ListLength(lb);
	int i  ;
	int e  ;
	for (i = 1 ; i <= lb_len ; i ++){
		GetElem(lb, i, &e);
		if(!LocateList(*la, e, equal)){
			InsertList(la, ++la_len , e);
		}
	}
}
int ListLength(Sqlist la){
	return la.length ;
}
void GetElem(Sqlist la, int i , int *e ){
	*e = la.elem[i-1];
}
Status equal(int a , int b){
	if ( a == b  ){
		return OK;
	}
	return FALSE ;
}
Status   LocateList(Sqlist  la, int e , int (* p)(int a, int b)){
	int i = 1 ;
	int flag = FALSE ;
	for (; i <= la.length ; i ++){
		if( p(la.elem[i-1], e) ){
			flag = TRUE;
		}
	}
	return flag ;
}

Status  InsertList(Sqlist * la, int i , int e){
	if(i < 1 || i > la->length + 1){
		return ERROR;
	}
	if(la->length >= la->sizeoflist){
		ElemType * newbase = (ElemType *)realloc(la->elem, (la->sizeoflist + LISTINCREMENT) * sizeof(ElemType));	
		if(!newbase){
			exit(OVERFLOW);
		}
		la->elem = newbase ;
		la->sizeoflist += LISTINCREMENT ;
	}
	ElemType * q = &(la->elem[i-1]);
	ElemType * p  ;
	for (p = &(la->elem[la->length -1]); p >= q ;--p){
		*(p + 1) = * p ;
	}
	*q = e ;
	++ la->length ;
	return OK ;
}
void print(Sqlist la){
	int i = 0 ;
	for (  ; i < la.length ; i ++ ){
		printf("%d\n", la.elem[i]);
	}
}
