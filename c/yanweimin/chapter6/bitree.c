#include<stdio.h>
#include<stdlib.h>
#include"./stack.h"
#define OK 1
#define ERROR 0
typedef int Status;
//typedef please look the ./stack.h

Status createBitree(Bitree, char**);
Status preOrderTranverse(Bitree, Status(*)(Telemtype));
Status inOrderTranverse(Bitree, Status(*)(Telemtype));
Status postOrderTranverse(Bitree, Status(*)(Telemtype));
Status levelOrderTranverse(Bitree, Status(*)(Telemtype));
int bitreeEmpty(Bitree);
int bitreeDepth(Bitree);
//BiTNode *root(Bitree);
BiTNode *gofarleft(Bitree, SqStack);
Status print_char_elem(Telemtype);
char *getstring(void);
int main(void)
{
	Bitree tree = (Bitree)malloc(sizeof(BiTNode));
	char *a = getstring();
	createBitree(tree,&a);
	printf("\n\n");
	preOrderTranverse(tree, print_char_elem); printf("\n");
	inOrderTranverse(tree, print_char_elem); printf("\n");
	postOrderTranverse(tree, print_char_elem); printf("\n");
	levelOrderTranverse(tree, print_char_elem); printf("\n");
	printf("depth: %d\n", bitreeDepth(tree)); printf("\n");
	return 0;
}

Status createBitree(Bitree tree, char **string)
{	printf("create\n");
	printf("%s\n", *string);
	if(!string || !(*string)){printf("the string is NULL;"); return ERROR;}
	if(!**string) return 3; 
	else if(**string == ' ') { *string++; return OK; }
	else
	{
		(tree->data).t_char = **string;
		(*string)++;
		if(!**string) return 3;
		if(**string != ' ')
		{
			tree->lchild = (Bitree)malloc(sizeof(BiTNode));
			if((createBitree(tree->lchild, string))==3) return 3;
		}else { (*string)++; tree->lchild = NULL;}
		if(!**string) return 3;
		if(**string != ' ')
		{
			tree->rchild = (Bitree)malloc(sizeof(BiTNode));
			if((createBitree(tree->rchild, string))==3) return 3;
		}else {(*string)++; tree->rchild = NULL;}
	}
	return OK;
}

Status preOrderTranverse(Bitree tree, Status (*visit)(Telemtype e))
{
	if(tree == NULL) return OK;
	else
	{
		visit(tree->data);
		preOrderTranverse(tree->lchild,visit);//printf("\t");
		preOrderTranverse(tree->rchild,visit);//printf("\n");
	}
	return OK;
}

Status inOrderTranverse(Bitree tree, Status(*visit)(Telemtype e))
{
	SqStack s = initstack();
	BiTNode *pnode = gofarleft(tree, s);
	while(pnode)
	{
		visit(pnode->data);
		if(pnode->rchild)
		{
			pnode = gofarleft(pnode->rchild, s);
		}
		else if(!stackempty(s))
		{
			pnode = pop(s).t_pbinode;
		}
		else pnode = NULL;
	}
}

Status levelOrderTranverse(Bitree tree, Status(*visit)(Telemtype e))
{	printf("levelOrderTranverse:\n");
	Queue queue;
	initqueue(&queue);
	Telemtype te;
	QElemtype qe;
	BiTNode *pbinode;
	qe.t_pbinode = tree;
	int n=0;
//	printf("#head:%d, tail:%d", queue.head, queue.tail);
	enqueue(&queue, qe);
	while(!queueempty(&queue))
	{
		dequeue(&queue, &qe);
		pbinode = (qe.t_pbinode);
		visit(pbinode->data);

		if(pbinode->lchild)
		{
			qe.t_pbinode = pbinode->lchild;
			enqueue(&queue, qe);
		}
		if(pbinode->rchild)
		{
			qe.t_pbinode = pbinode->rchild;
			enqueue(&queue, qe);
		}
	}
	return OK;
}

int bitreeEmpty(Bitree tree)
{
	if(!tree) return 1;
	return 0;
}

int bitreeDepth(Bitree tree)
{
	int ldepth, rdepth;
	if(!tree) return 0;
	else
	{
		ldepth = bitreeDepth(tree->lchild);
		rdepth = bitreeDepth(tree->rchild);
		return (1 + (ldepth>rdepth?ldepth:rdepth));
	}
}

Status postOrderTranverse(Bitree tree, Status(*visit)(Telemtype e))
{
	if(tree == NULL) return OK;
	{
		postOrderTranverse(tree->lchild, visit);
		postOrderTranverse(tree->rchild, visit);
		visit(tree->data);
	}
	return OK;
}

BiTNode *gofarleft(Bitree tree, SqStack stack)
{
	if(!tree) return NULL;
	BiTNode *pnode = tree;
	Elemtype temp;
	while(pnode->lchild)
	{
		temp.t_pbinode = pnode;
		push(stack, temp);
		pnode = pnode->lchild;
	}
	return pnode;
}

Status print_char_elem(Telemtype e)
{
	printf("%c", e.t_char);
}


char *getstring(void)
{
	int initsize = 20, increment = 10;
	int size = initsize;
	printf("(string)>>>");
	char *string = (char *)malloc(sizeof(char)*initsize);
	char *cur = string;
	char ch;
	while((ch=getchar()) != '\n')
	{
		*cur++ = ch;
		if(cur-string >= size)
		{
		  string = (char *)realloc(string, size+increment);
		  cur = string + size;
		  size += increment;
		}
	}
	*cur = '\0';
	return string;
}
