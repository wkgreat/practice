#include<stdio.h>
#include"./linklist.h"

int main(void)
{
	printf("not complete!");
	pNode thelink;
	thelink = initlink(0,0);
	int i;
	for(i=1;i<=13;i++)
	{
		insAfter(thelink, i-1, i);
	}

	printlink(thelink);
	return 0;
}
