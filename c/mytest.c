#include<stdio.h>
/* print integer range from 1 to 1000 */
/*but exit a problem */

int f(int i, int n);

int f(int i, int n)
{
	printf("%d\n, i");
	i++;
	(n-i)&&f(i, n);
	return 0;
}

int main()
{
	f(1, 1001);
	return 0;
}
