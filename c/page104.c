#include<stdio.h>
/* strcpy函数 将指针t指向的字符串复制到指针s指向的位置*/

void strcpy1(char *s, char *t);

main()
{
	char a[] = "abcde";
	char b[10];
	char *s;
	char *t = a;
	s = &b[0];
	strcpy1(s, t);

	while(*s)
	{
		printf("%c",*s);
		s++;
	}

	printf("\n");
}

void strcpy1(char *s, char *t)
{
	while(*s++ = *t++)
	  ;
}

