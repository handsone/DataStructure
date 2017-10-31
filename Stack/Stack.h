# include <stdio.h>
# include <stdlib.h>
# include <malloc.h>

# define OVERFLOW -2 
# define TRUE      1
# define FALSE     0
# define OK        1
# define ERROR     0
# define INFEASIBLE -1
# define STACK_INIT_SIZE 100
# define STACKINCREMENT  10 

typedef int Status     ;
typedef int SElemType  ;
typedef struct {
	SElemType * base ;
	SElemType * top  ;
	int stacksize ;
}SqStack;

char   SeachMach(int e);
Status Pop(SqStack *S, SElemType *e);
Status InitStack(SqStack * S);
Status Push(SqStack *S, SElemType e);
Status StackEmpty(SqStack S);

Status StackEmpty(SqStack S){
	if(S.top == S.base ){
		return FALSE ;
	}
	else{
		return TRUE ;
	}
}
Status Pop(SqStack *S, SElemType *e){
	if((*S).top == (*S).base){
		return ERROR;
	}
	*e = *--(*S).top;
	return 	OK ;
}
Status InitStack(SqStack * S){
	// 构造一个空栈
	(*S).base = (SElemType *)malloc( STACK_INIT_SIZE * sizeof(SElemType) );
	if(!(*S).base){
		exit(OVERFLOW);
	}
	(*S).top = (*S).base ;
	(*S).stacksize = STACK_INIT_SIZE ;
	return OK ;
}
Status Push(SqStack *S, SElemType e)
{
// 插入元素e为新的栈顶元素
	if( (*S).top -(*S).base >= (*S).stacksize){
	(*S).base = (SElemType *) realloc( (*S).base, (*S).stacksize + 
				STACKINCREMENT  * sizeof(SElemType));
	if(!(*S).base){
		exit(OVERFLOW);
	}
	(*S).top = (*S).base + (*S).stacksize;
	(*S).stacksize += STACKINCREMENT;
	}
	*(*S).top ++ = e ;
	return OK ;
}
Status GetTop(SqStack S, SElemType * e){
	if(S.top == S.base){
		return ERROR ;
	}
	*e = *(S.top -1) ;
		return OK;
}

char   SeachMach(int e){
	char flag ;
	if( e == '[' ){
		flag = ']';	
	}
	else if( e == '{' ){
		flag = '}';
	}
	else {
		flag = ')';
	}
	return flag ;
}

