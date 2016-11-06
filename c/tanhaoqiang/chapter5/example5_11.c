#include<stdio.h>

int mine(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char c;
	while((c=getchar()) != '\n')
	{
		if(c>='a' && c<='z' || c>='A' && c<='Z')
			if(c>='w' && c<='z' || c>='W' && c<='Z') c-=22;
			else c+=4;
		putchar(c);
	}
	putchar('\n');
}
