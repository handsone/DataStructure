# include "Stack.h"
int main(){
	SqStack S ;
	int i  , e ; 
	char flag ;
	char  String[10];
	printf("请输入括号表达式:\n");
	scanf("%s", String);
	InitStack(&S);
	Push(&S, *String);
	for (i = 0  ; String[i] != '\0' ; i ++){
		GetTop(S, &e);
		flag = SeachMach(e);
		if(!String[i+1]){
			break;
		}
		if(String [i+1] == flag  ){
			Pop(&S, &e);
		}
		else{
			Push(&S,String[i+1]);
		}
	}
	if(!StackEmpty(S)){
		printf("括号匹配成功");
	}
	else {
		printf("括号匹配失败");
	}
	return  0 ;
}
