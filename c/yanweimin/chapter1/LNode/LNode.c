#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

LinkList initLink(int n);
int print_link(LinkList link);

LinkList initLink(int n)
{
	LinkList head,p;
	int i;
	if(n<0) return NULL;
	head = (LinkList)malloc(sizeof(LNode));
	head->next = NULL;
	p = head;
	for(i=1;i<=n;++i)
	{
		p->next = (LinkList)malloc(sizeof(LNode));
		p = p->next;
		p->data = 0;
	}
	p->next = NULL;
	return head;
}

int print_link(LinkList link)
{
	LinkList head = link;
	LinkList node = head;
	while(node = (node->next))
	  printf("%d ", node->data);
	printf("\n");
	return 0;
}


int main(void)
{
	LinkList mylink = initLink(5);
	print_link(mylink);
	return 0;
}
