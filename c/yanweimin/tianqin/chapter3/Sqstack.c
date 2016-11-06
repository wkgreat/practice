#include<stdio.h>
#define MAXSIZE 1024
typedef struct
{
	int data[MAXSIZE];
	int top;
}Sqstack;

int initsqstack(Sqstack *);
int push(Sqstack *, int);
int pop(Sqstack*, int *);
int isempty(Sqstack);
int printng(int *a, int n);
int main(void);

int initsqstack(Sqstack *stack)
{
	stack->top = -1;
	return 1;
}

int push(Sqstack *stack, int e)
{
	if(stack->top == MAXSIZE-1) return 0;
	stack->data[++(stack->top)] = e;
	return 1;
}

int pop(Sqstack *stack, int *e)
{
	if(stack->top==-1) return 0;
	*e = stack->data[(stack->top)--];
	return 1;
}

int isempty(Sqstack stack)
{
	if(stack.top<=-1) return 1;
	return 0;
}

int printng(int *a, int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 1;
}

int main(void)
{
	Sqstack s;
	initsqstack(&s);
	push(&s, 1);
	push(&s, 2);
	printng(s.data,s.top+1);
	int e;
	pop(&s, &e);
	printng(s.data, s.top+1);printf("%d\n",e);
}


