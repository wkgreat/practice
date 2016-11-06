#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char *name[5] = {"C","Python","FORTRAN","JAVA","LISP"};
	char **p;
	p = name;
	int i;
	for(i=0;i<5;i++)
	  printf("%s\n", *p++);
	return 0;
}
