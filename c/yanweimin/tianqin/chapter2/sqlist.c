#include<stdio.h>

#define MAXSIZE 1024

typedef struct Sqlist
{
	int data[MAXSIZE];
	int length;
}Sqlist;

int initsqlist(Sqlist*);
int insert(Sqlist*, int index, int elem);
int delete(Sqlist*, int index, int* e);
int printng(int *, int);
int main(void);

int initsqlist(Sqlist *plist)
{
	plist->length=0;
}

int insert(Sqlist *plist, int index, int elem)
{
	int i;
	if(index<1 || index > plist->length+1 || plist->length == MAXSIZE) return 0;
	for(i=plist->length; i>=index; --i)
	{
		plist->data[i+1] = plist->data[i];
	}
	plist->data[index] = elem;
	++(plist->length);
	return 1;
}

int delete(Sqlist *plist, int index, int *e)
{
	int i;
	if(index<1 || index>(plist->length)) return 0;
	*e = plist->data[index];
	for(i=index; i<plist->length; ++i)
	{
		plist->data[i] = plist->data[i+1];
	}
	--(plist->length);
	return 1;     
}

int printng(int *a, int n)
{
	int i;
	for(i=1; i<=n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 1;
}

int main(void)
{
	Sqlist list;
	initsqlist(&list);
	insert(&list, 1, 1);
	insert(&list, 2, 2);
	printng(list.data, list.length);
	int e;
	delete(&list, 1, &e);
	printng(list.data, list.length);
	return 0;
}
