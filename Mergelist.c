# include "Sqlist.h"

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
