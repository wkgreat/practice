#include<stdio.h>

/*µÚÒ»ÕÂ Ï°Ìâ5*/
int main(void)
{
	int print_starline(int n);
	print_starline(30);
	printf("Very good!\n");
	print_starline(30);
	return 0;
}

int print_starline(int n)
{
	for(int i=0; i<n; ++i)
		printf("*");

	printf("\n");

	return 0;
}
