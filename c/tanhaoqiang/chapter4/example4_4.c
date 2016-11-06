#include<stdio.h>

int main(void);
int book(void);
int main(void)
{
	book();
	return 0;
}

int mine(void)
{
	char c;
	c = getchar();
	(c >= 'A' && c <= 'Z') ? (c = c+32) : c;
	printf("the result is: %c\n", c);
	return 0;
}

int book(void)
{
	char ch;
	scanf("%c", &ch);
	ch=(ch>='A' && ch<='Z') ? (ch+32) : ch;
	printf("%c\n", ch);
	return 0;
}
