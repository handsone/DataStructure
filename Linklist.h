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
