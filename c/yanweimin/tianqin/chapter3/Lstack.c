#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode;

LNode* initStack();
int isempty(LNode);
int push(LNode *lst, int x);
int pop(LNode *, int *e);
int printstack(LNode*);

LNode* initStack()
{
	LNode *lst;
	if(!(lst=(LNode*)malloc(sizeof(LNode)))) return NULL;
	lst->next = 0;
	return lst;
}

int isempty(LNode lst)
{
	if(lst.next) return 0;
	return 1 ;
}

int push(LNode *lst, int x)
{
	LNode *e;
	if(!(e=(LNode*)malloc(sizeof(LNode)))) return 0;
	e->data = x;
	e->next = 0;
	e->next = lst->next;
	lst->next = e;
	return 1;
}

int pop(LNode *lst, int *e)
{
	if(isempty(*lst)) return 0;
	LNode *p;
	p = lst->next;
	*e = p->data;
	lst->next = p->next;
	free(p);
	return 1;
}

int printstack(LNode *lst)
{
	LNode *p = lst;
	while(p->next)
	{
		p=p->next;
		printf("%d -> ", p->data);
	}
	printf("\n");
	return 1;
}

int main(void)
{
	LNode* stack = initStack();
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	printstack(stack);
	int e;
	pop(stack, &e);printf("e:%d\n",e);
	printstack(stack);
	return 1;
}
