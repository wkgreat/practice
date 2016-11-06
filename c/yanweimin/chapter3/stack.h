#include<stdio.h>
#include<stdlib.h>
//define
#define STACK_INIT_SIZE 100
#define	STACKINCREMENT 10
//typedef
typedef union
{
	int t_int;
	char t_char;
	double t_double;
}Elemtype;

typedef struct
{
	Elemtype *base;
	Elemtype *top;
	int size;
}*SqStack;

//function prototype
SqStack initstack(void);
int destroystack(SqStack);
int clearstack(SqStack);
int stackempty(SqStack);
int stacklength(SqStack);
Elemtype gettop(SqStack);
int push(SqStack, Elemtype);
Elemtype pop(SqStack);
//int stacktranverse(Sqstack);
int mine(void);
int print_int_stack(SqStack);
int print_char_stack(SqStack);
int print_double_stack(SqStack);

int printseparat(int, char);

//main
/*
int main(void)
{
	mine();
	return 0;
}
//function declaration
*/
/*
int mine(void)
{
	int i;
	SqStack stack = initstack();
	for(i=0;i<5;i++)
	{
		push(stack, i);
	}
	printstack(stack);
	printf("Push,2\n");
	push(stack, 255);
	printstack(stack);
	printf("gettop");
	int gettop1 = gettop(stack);
	printf("the gettop value is: %d\n", gettop1);
	printstack(stack);
	printf("pop");
	int pop1 = pop(stack);
	printf("The pop value%d\n", pop1);
	printstack(stack);
	printf("The stack is empty?%d\n", stackempty(stack));
	printf("clearstack\n");
	clearstack(stack);
	printstack(stack);
	printf("destroy\n");
	destroystack(stack);
	printstack(stack);
	return 0;
}
*/
int printseparat(int n, char c)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%c", c);
	}
	printf("\n");
	return 0;
}

SqStack initstack()
{
	SqStack stack = (SqStack)malloc(sizeof(SqStack));
	stack->base = (Elemtype*)malloc(STACK_INIT_SIZE*sizeof(Elemtype));
	if(!stack->base) exit(0);
	stack->top = stack->base;
	stack->size = STACK_INIT_SIZE;
	return stack;
}

int destroystack(SqStack stack)
{
	free(stack->base);
	free(stack);
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
		stack->top = stack->base + stack->size;
		stack->size += STACKINCREMENT;
	}
	*(stack->top) = e;
	stack->top+=1;
	return 0;
}

int print_int_stack(SqStack stack)
{
	Elemtype *cur = stack->base;
	if(!stack){printf("(NULL!)\n"); return 1;}
	if(stack->base == stack->top){printf("(empty!)\n"); return 1;}
	while(cur != stack->top)
	{
		printf("%d\t", (*cur++).t_int);
	}
	printf("\n");
	return 0;
}


int print_char_stack(SqStack stack)
{
	Elemtype *cur = stack->base;
	if(!stack){printf("(NULL!)\n"); return 1;}
	if(stack->base == stack->top){printf("(empty!)\n"); return 1;}
	while(cur != stack->top)
	{
		printf("%c", (*cur++).t_char);
	}
	printf("\n");
	return 0;
}


int print_double_stack(SqStack stack)
{
	Elemtype *cur = stack->base;
	if(!stack){printf("(NULL!)\n"); return 1;}
	if(stack->base == stack->top){printf("(empty!)\n"); return 1;}
	while(cur != stack->top)
	{
		printf("%.4lf\t", (*cur++).t_double);
	}
	printf("\n");
	return 0;
}

Elemtype pop(SqStack stack)
{
	Elemtype e;e.t_int = 0;
	if(stack->top == stack->base){printf("(EMPTY!)"); return e;}
	return *--stack->top;
}

Elemtype gettop(SqStack stack)
{
	return *(stack->top-1);
}



int stackempty(SqStack stack)
{
	if(stack->base == stack->top)
	  return 1;
	return 0;
}


int clearstack(SqStack stack)
{
	stack->top = stack->base;
	return 0;
}
