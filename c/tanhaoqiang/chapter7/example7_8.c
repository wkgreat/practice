#include<stdio.h>

int hanoi(int n);
void move(int n,char start, char mid, char end);

int main(void)
{
	int n;
	scanf("%d",&n);
	hanoi(n);
	printf("\n");return 0;
}

int hanoi(int n)
{
	move(n,'A','B','C');
}

void move(int n, char start, char mid, char end)
{
	if(n==2)
	{
		printf("%c->%c\n",start, mid);
		printf("%c->%c\n",start, end);
		printf("%c->%c\n",mid, end);
	}	
	else
	{
		move(n-1,start,end,mid);
		printf("%c->%c\n",start,end);
		move(n-1,mid,start,end);
	}
}
