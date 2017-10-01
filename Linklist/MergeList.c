# include"Linklist.h"
int main (){
	LinkList La = CreatLink();
	LinkList Lb = CreatLink();
	LinkList Lc  = (LinkList)malloc(sizeof(LNode))  ; 
	Lc ->next = NULL ;
	MergeList_L(La, Lb, Lc);
	return 0 ;
}
