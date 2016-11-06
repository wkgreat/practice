#include<stdio.h>

/* page15 t6 */

main(void)
{
	int a, b, c;
	printf("Please enter three integer number,split by space:\n");
	scanf("%d %d %d", &a, &b, &c);

	printf("\nthe maximum number is: ");
	if(a > b)
	{
		if(a > c)
		  printf("%d", a);
		else
		  printf("%d", c);
	}
	else
	{
		if(b > c)
		  printf("%d", b);
		else
		  printf("%d", c);
	}

	printf("\n");

	return 0;
}

