#include<stdio.h>

int main(void)
{
	char a[8] = "Come on!";
	printf("%s\n", a);
	int i=0;
	while(a[i])
	  printf("%c\n",a[i++]);
	return 0;
}
