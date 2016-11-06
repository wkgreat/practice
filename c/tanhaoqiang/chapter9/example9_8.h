#include<stdio.h>
#include<stdlib.h>
/* 
   1)link the index start from 1
 */
//---type---
typedef struct Student
{
	int no;
	char name[20];
}stu;

typedef stu Elemtype;

typedef struct Node
{
	Elemtype data;
	struct Node *next;
}Node, *pNode;

//---function prototype---
int mine(void);
int printfengexian(int n);

pNode makeNode(Elemtype e);
void freeNode(pNode);
stu inputStuInfo(void); // not conpelte;

pNode initlink(int length, Elemtype e);
int destroyList(pNode);
int clearList(pNode);
int printlink(pNode);
int insFirst(pNode head, pNode node);
pNode delFirst(pNode head);
int append(pNode head, pNode node);
pNode linkRemove(pNode head);
int insBefore(pNode head, int index, Elemtype e);
int insAfter(pNode head, int index, Elemtype e);
Elemtype getElem(pNode head, int index);
int listEmpty(pNode head);
int listTranverse(pNode head, int(*)()); int visit();

//---main---
/*
int main(void)
{
	mine();
	printf("\n");
	return 0;
}*/

int mine(void)
{
	stu s0 = {0,"Wangke"};
	pNode thelink = initlink(3, s0);
//	printf("%s", (thelink->next->data).name);
	printf("\n---the link is:---\n");
	printlink(thelink);
//	clearList(thelink);
	printf("\n---insFirst---");
	stu s1 = {1,"Tianye"};
	pNode node1 = makeNode(s1);
	insFirst(thelink,node1);
	printlink(thelink);
	printf("delFirst");
	pNode thedelnode = delFirst(thelink);
	printf("the delet node is:no:%d,name:%s\n", thedelnode->data.no, thedelnode->data.name);
	printlink(thelink);
	printf("append");//append
	stu s2 = {2,"Gaoshupeng"};
	pNode node2 = makeNode(s2);
	stu s3 = {3,"Duliang"};
	append(thelink, node2);
	printlink(thelink);
	printf("linkRemove\n");//linkRemove
	thedelnode = linkRemove(thelink);	
	printf("the delete node is: no:%d, name:%s\n", thedelnode->data.no, thedelnode->data.name);
	printlink(thelink);
	printf("insBefore(thelink, 2,...)\n");//insBefore
	insBefore(thelink, 2, s2);
	printlink(thelink);
	printf("insAfter(thelink,2,...)\n");//insAfter
	insAfter(thelink, 4, s3);
	printlink(thelink);
	printf("getElem(2)\n");//getElem
	Elemtype theelem = getElem(thelink, 2);
	printf("the 2th node is: no:%d, name:%s\n", theelem.no, theelem.name);
	printf("the link is empty:1yes,0no:, %d\n", listEmpty(thelink));//listEmpty
	listTranverse(thelink, visit); // listTranverse;
	return 0;
}

int printfengexian(int n)
{
	int i;
	for(i=0;i<n;i++)
	  printf("-");
	printf("\n");
}

stu inputStuInfo(void)
{
	stu s;
	printf("please enter the student's infomation:\n");
	printf("no:");scanf("%d",&s.no);
	printf("name:");scanf("%s",s.name);
	return s;
}

pNode makeNode(Elemtype e)
{
	pNode pnode = (pNode)malloc(sizeof(Node));
	pnode->data = e;
	pnode->next = 0;
	return pnode;
}

void freeNode(pNode pnode)
{
	free(pnode);
}

int destroyList(pNode head)
{
	pNode cur=head, thenext=head;
	while(cur)
	{
		thenext = cur->next;
		free(cur);
		cur = thenext;
	}
	return 0;
}

int clearList(pNode head)
{
	pNode cur=head->next, thenext=head->next;
	while(cur)
	{
		thenext = cur->next;
		free(cur);
		cur = thenext;
	}
	head->next = 0;
	return 0;
}

pNode initlink(int length, Elemtype e)
{
	if(length<0) return 0;

	pNode head;
	pNode cur;
	int i;

	head = (pNode)malloc(sizeof(Node));
	if(!head) return 0;
	cur = head;

	head->next = 0;
	for(i=0;i<length;i++)
	{
		cur->next = makeNode(e);
		cur = cur->next;
	}
	cur->next = 0;
	return head;
}

int printlink(pNode head)
{
	int i=0;
	pNode cur = head;
	printf("---The information of link---\n");
	if(!cur){printf("ERROR!The list is NULL!"); return 0;}
	if(!cur->next){printf("The list is empty!"); return 0;}
	while(cur=(cur->next))
	{
		printf("|%d|\t%d:%s\n", ++i, cur->data.no, cur->data.name);
	}
	printfengexian(30);
	return 0;
}

int insFirst(pNode head, pNode node)
{
	pNode thenext = head->next;
	head->next = node;
	node->next = thenext;
	return 0;
}

pNode delFirst(pNode head)
{
	if(!head){printf("ERROR!The link is NULL!"); return 0;}

	pNode theDelNode = head->next;
	if(!theDelNode){printf("The link has been empty!"); return 0;}
	head->next = head->next->next;
	return theDelNode;
}

int append(pNode head, pNode node)
{
	if(!head) {printf("ERROR!The list is NULL!"); return 0;}

	pNode tail = head;
	while(tail->next)
		tail = tail->next;
	tail->next = node;
	return 0;
}

pNode linkRemove(pNode head)
{
	if(!head){printf("ERROR!The list is NULL!"); return 0;}
	if(!head->next){printf("The list is already empty!"); return 0;}
	pNode tail = head;
	pNode theDelNode = 0;
	while(tail->next->next)
	  tail = tail->next;
	theDelNode = tail->next;
	tail->next = 0;
	return theDelNode;
}

int insBefore(pNode head, int index, Elemtype e)
{	
	if(!head){printf("ERROR!The list is NULL!"); return 1;}
	int i;
	pNode cur = head;
	pNode theinsnode, thenext;
	for(i=1;i<index;i++)
	{
		cur = cur->next;
		if(!cur){printf("The input index is overflow!insBefore is failed!"); return 1;}
	}
	thenext = cur->next;
	theinsnode = makeNode(e);
	cur->next = theinsnode;
	theinsnode->next = thenext;
	return 0;
}

int insAfter(pNode head, int index, Elemtype e)
{
	if(!head){printf("ERROR!The list is NULL!"); return 1;}
	int i;
	pNode cur = head;
	pNode theinsnode, thenext;
	for(i=1;i<=index;i++)
	{
		cur = cur->next;
		if(!cur){printf("The input index is overflow!insAfter is failed!"); return 1;}
	}
	thenext = cur->next;
	theinsnode = makeNode(e);
	cur->next = theinsnode;
	theinsnode->next = thenext;
	return 0;

}

Elemtype getElem(pNode head, int index)
{
	Elemtype enull = {0,"NULL"};
	if(!head){printf("ERROR!The list is NULL!"); return enull;}
	int i=0;
	pNode cur = head;
	while(cur=cur->next)
	{
		i++;
		if(i==index) return cur->data;
	}
	if(!cur){printf("The input index is overflow!getElem is failed!"); return enull;}

	
}

int listEmpty(pNode head)
{
	if(!head){printf("ERROR!The list is NULL!"); return 1;}
	if(head->next) return 0;
	return 1;
}

int listTranverse(pNode head, int(*visit)())
{
	if(!head){printf("ERROR!The list is NULL!"); return 1;}
	int i;
	pNode current = head;
	while(current=current->next)
	{
		visit();
	}
	return 0;
}

int visit()
{
	printf("visit\n");
	return 0;
}

















