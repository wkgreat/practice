#include<stdio.h>
#include<stdlib.h>
//define
#define STACK_INIT_SIZE 100
#define	STACKINCREMENT 10
//typedef
typedef int Elemtype;

typedef struct
{
	Elemtype *base;
	Elemtype *top;
	int size;
}*SqStack;

//function prototype
SqStack initstack(void);
int destroystack(SqStack);
//int clearstack(Sqstack);
//int stackempty(Sqstack);
int stacklength(SqStack);
//int gettop(Sqstack);
int push(SqStack, Elemtype);
//int pop(Sqstack);
//int stacktranverse(Sqstack);
int mine(void);
int printstack(SqStack);

//main
int main(void)
{
	mine();
	return 0;
}
//function declaration

int mine(void)
{
	return 0;
}

SqStack initstack()
{
	return 0;
}
int destroystack(SqStack stack)
{
	return 0;
}
int stacklength(SqStack stack)
{
	return stack->size;
}

int push(SqStack stack, Elemtype e)
{
	if(stack->top - stack->base >= stack->size)
	{
		stack->base = (Elemtype *)realloc(stack->base, sizeof(Elemtype)*(STACK_INIT_SIZE+STACKINCREMENT));
		if(!stack->base) exit(0);
		stack->top = stack->base+stack->size;
		stack->size += STACKINCREMENT;
	}
	*stack->top = e;
	stack->top+=1;
	printf("top:%d\n", stack->top);
	return 0;
}

int printstack(SqStack stack)
{
	Elemtype *cur = stack->base;
	int i=0;
	printf("|%d|%d|\n", cur, stack->top);
	while(cur != stack->top)
	{
		printf("|%d|%3d|\n", ++i, *cur++);
	}
	return 0;
}
