# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

# define TURE 1 
# define FALSE 0 
# define LIST_INIT_SIZE 100
# define OK 1 
# define OVERFLOW -2 

typedef struct {
	int * elem ;
	int length ;
	int listsize ;
} Sqlist ;

typedef int Status ;
typedef int ElemType ;

int ListLength(Sqlist la);
void GetElem(Sqlist la, int i , int * e);
void ListInsert(Sqlist * la, int i , int e );
void MergeList(Sqlist la, Sqlist lb, Sqlist * lc);
void print(Sqlist lc);
Status InitList_Sq(Sqlist *la);
int main (){
	Sqlist la, lb, lc ;
	int a[10] = {1,3,5,7,9,11,13,15,17,19};
	int b[10] = {2,4,6,8,10,12,14,16,18,20};
	la.elem  = a;
	lb.elem  = b ;
	la.length = 10 ;
	lb.length = 10 ;
	MergeList(la, lb, &lc);
	print(lc);
	return 0 ;
}

void MergeList(Sqlist la, Sqlist lb, Sqlist * lc){
	InitList_Sq(lc);
	int i , j , k, ai, bj;
	i = j = 1 ;
	k = 0 ;
	int la_len = ListLength(la);
	int lb_len = ListLength(lb);
	while( i <= la_len  && j <= lb_len ){
		GetElem(la, i , &ai);
		GetElem(lb, j , &bj);
		if(ai <= bj){
			ListInsert(lc, ++k, ai);
			i ++;
		}
		else {
			ListInsert(lc, ++k ,bj);
			j ++;
		}
	}
	while(i <= la_len){
		GetElem(la, i, &ai);
		ListInsert(lc , ++k, ai);
		i ++ ;
	}
	while( j <= lb_len ){
		GetElem(lb, j , &bj);
		ListInsert(lc, ++k, bj);
		j ++ ;
	}
}

Status InitList_Sq(Sqlist * la){
	la->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (! la->elem){
		exit(OVERFLOW);
	}
	la->length = 0 ;
	la->listsize = LIST_INIT_SIZE ;
	return OK;

}

int ListLength(Sqlist la){
	return la.length ;
}

void GetElem(Sqlist la, int i , int * e){
	*e = la.elem[i-1];
}

void ListInsert(Sqlist * la, int i , int e ){
	la->elem[i-1] = e ;
	la->length ++ 	  ;
}
void print(Sqlist lc){
	int i = 0 ;
	for (; i < lc.length ; i ++){
		printf("%d\n", lc.elem[i]);
	}
}
