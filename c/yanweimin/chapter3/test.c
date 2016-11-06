#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a;
}*stru;

int main(void)
{
	stru s;
	s->a = 1;
	return 0;
}
