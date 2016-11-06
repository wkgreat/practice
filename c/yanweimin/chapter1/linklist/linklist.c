#include<stdio.h>
#include<stdlib.h>
#define ERROR 1
#define OK 0

typedef int Status;

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}*Link, *Position;

typedef struct
{
	Link head, tail;
	int len;
}LinkList;

Status MakeNode(Link &p, ElemType e);
void FreeNode(Link &p);

Status InitList(LinkList &L);
Status DestroyList(LinkList& L);
Status ClearList(LinkList &L);
Status InsFirst(Link h,Link s);
Status DelFist(Link h,Link& q);
Status Append(LinkList &L, Link s);
Status Remove(LinkList &L, Link &q);
Status InsBefore(LinkList &L, Link &p, Link s);
Status InsAfter(LinkList &L, Link &p, Link s);
Status SetCurElem(Link &p, ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L, Link p);
Position NextPos(LinkList L, Link p);
Status LocatePos(LinkList L, int i, Link &p);
Position LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L, Status (*visit)());

int main()
{
	return 0;

