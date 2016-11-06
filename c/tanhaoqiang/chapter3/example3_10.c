#include<stdio.h>

int book(void);
int mine(void);

int main(void)
{
	mine();
//	book();
	return 0;
}

int mine(void)
{
	char c;
	printf("Please enter a capital>>>");
	while(((c=getchar()) > 'Z') || (c < 'A'))
	{
		printf("The character is not a capital!\nPlease enter a capital>>>\n");
	}

	printf("the lower character is: %c\n",(c+32));
	return 0;
}

int book(void)
{
	char c1, c2;
	c1 = getchar();
	c2 = c1+32;
	putchar(c1);
	putchar(c2);
	putchar('\n');
	return 0;
}
