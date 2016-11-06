#include<stdio.h>
#include<math.h>

int main(void)
{
	int a, c;
	double b;
	do
	{
		printf("Please enter a number that be small than 1000\n");
		scanf("%d", &a);
	}while(a>1000 || a<0);
	
	b = sqrt(a);
	c = (int)b;
	printf("The result is: %d\n", c);
	//printf("The result is: %.0lf\n", b);

	return 0;
}
