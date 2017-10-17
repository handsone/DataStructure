# include "Linklist.h"
int main (){

	LinkList La;
	LinkList Lb;
	CreateList_L(&La, 5);
	CreateList_L(&Lb, 5);
	Union(&La, Lb);
	Print(La);
	return 0 ;
}
