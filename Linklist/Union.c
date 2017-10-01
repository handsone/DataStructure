# include "Linklist.h"
int main (){

	LinkList La = CreatLink();
	LinkList Lb = CreatLink();
	//Print(La);
	//Print(Lb);
	Union(La, *Lb);
	Print(La);
	return 0 ;
}
