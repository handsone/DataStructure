# include<stdio.h>
# include<malloc.h>

# define OVERFLOW  -2 
# define LISTINCREMENT 10 
# define TRUE 1
# define FALSE 0
# define OK   1
# define LIST_INIT_SIZE 100 
# define ERROR 0  

typedef int ElemType ;
typedef struct LNode{
	ElemType data;
	struct LNode  * next;
}LNode, *LinkList;
typedef int Status ;
/*
 * 函数声明
 */
int LinkListLength(LinkList La);
void Union(LinkList *  La, LinkList Lb);
void Print(LinkList La);
void MergeList_L(LinkList *  La, LinkList *  Lb, LinkList *  Lc);
Status GetElem(LinkList l, int i, ElemType *e);
Status ListInsert_L(LinkList L, int i, ElemType e);
Status ListDelete_L(LinkList L, int i, ElemType * e);
void CreateList_L(LinkList * L, int n);
Status LocateElem(LinkList L, ElemType e , int (*p )(int i , int j));
/*
 * 函数实现
 */
int compare(int i ,int j ){
	if (i == j){
		return TRUE;
	}
	else {
		return FALSE ;
	}
}
Status LocateElem(LinkList L, ElemType e , int (*p )(int i , int j)){
	int i = 0 ;
	while(L ->next ){
		i ++ ;
		L = L->next ;
		if(p(L->data , e)){
			return i ;
		}
	}
	return 0  ; 
}
int LinkListLength(LinkList La){
	int i = 0 ;
	while(La->next){
		La = La->next ;
		i ++ ;
	}
	return i ;
}
void Union(LinkList * La, LinkList Lb){
	int La_len =  LinkListLength(*La);
	int Lb_len =  LinkListLength(Lb);
	int i  , e ;
	for(i = 1 ;  i <= Lb_len ; i ++){
		GetElem(Lb, i , &e);
		if(!LocateElem(*La, e,compare)){
			ListInsert_L(*La, ++La_len , e);
		}
	}
}
void Print(LinkList La){
	while(La ->next ){
		La = La->next ;
		printf("%d\t", La->data);
	}
}
void CreateList_L(LinkList * L, int n ){
	*L = (LinkList)malloc(sizeof(LNode));
	int i = 0 ;
	LinkList p ; 
	(*L) ->next = NULL ;
	for ( i = n ; i > 0 ; --i ){
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p ->data);
		p->next = (*L) ->next ;
		(*L)->next = p        ;
	}
}

void MergeList_L(LinkList *  La, LinkList  * Lb, LinkList *  Lc){
	//已知单链表La,Lb的元素按值非递减排序
	//归并La,Lb得到新的单链表Lc,Lc的元素也按值非递减排序
	LinkList pa = (*La)->next ;
	LinkList pb = (*Lb)->next ;
	LinkList pc  ;
	 *Lc =  pc = *La  ;
	while (pa && pb){
		if(pa ->data <= pb->data){
			pc ->next = pa ;
			pc = pa ;
			pa = pa ->next ;
		}
		else {
			pc -> next = pb ;
			pc = pb ;
			pb = pb ->next ;
		}
	}
	pc -> next = pa? pa : pb ;
	free(*Lb);
	Print(*Lc);
}
Status ListDelete_L(LinkList L, int i, ElemType * e){
	LinkList p = L ;
	LinkList q ;
	int j  = 0 ;
	while (p -> next && j < i -1){
		p = p ->next ;
		++ j;
	}
	if(!(p ->next && j > i - 1)){
		return ERROR ;
	}
	q = p ->next ;
	p ->next = q ->next ;
	* e = q -> data ;
	free(q);
	return OK ;
}
Status ListInsert_L(LinkList L, int i, ElemType e){
	LinkList p = L ;
	LinkList s     ;
	int j = 0 ;
	while( p && j < i - 1 ){
		p = p -> next ;
		++ j;
	}
	if ( !p || j > i - 1 ){
		return ERROR ;
	}
	s = (LinkList )malloc(sizeof(LNode));
	s -> data = e ;
	s -> next = p -> next ;
	p -> next = s ;
	return OK;
}
Status GetElem(LinkList l, int i, ElemType *e){
	//L为带头结点的单链表的头指针
	//当第i个元素存在时，其值赋给e并返回OK，否则返回FALSE
	LinkList p = l->next; //初始化p，并将头结点赋给p
	int 	 j = 1;
	while(p && j < i){    //当p为空，或者
		p = p->next;
		++j;
	}
	if(!p||j>i){
		return ERROR;
	}
	*e = p->data ;
	return OK;
}
