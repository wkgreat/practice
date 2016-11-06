#include<stdio.h>

int main(void)
{
	char c;
	short state = 1;
	while((c=getchar()) != EOF)
	{
		if(c != ' ')
		{
			state = 0;
			putchar(c);
		}
		else if(state==0)
		{
			state = 1;
			putchar(c);
		}

	}

	return 0;
}
