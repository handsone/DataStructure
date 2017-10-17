# include"Linklist.h"
int main (){
	LinkList La =  NULL ;
	LinkList Lb =  NULL ;
	LinkList Lc =  NULL ;
	CreateList_L(&La, 5);
	CreateList_L(&Lb, 5);
	MergeList_L(&La, &Lb, &Lc);
	return 0 ;
}
