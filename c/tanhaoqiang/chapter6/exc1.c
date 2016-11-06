#include<stdio.h>
#include<math.h>

int mine(void);
int is_prime(int);
int my_printf(int,int);

int main(void)
{
	mine();
	printf("\n");
	return 0;
}

int mine(void)
{
	int i;
	for(i=3;i<=100;i+=2)
	  if(is_prime(i))
		my_printf(5,i);
}

int is_prime(int n)
{
	int i;
	for(i=2; i<=sqrt(n); ++i)
		if(n%i == 0)
		  break;
	if(i>sqrt(n))
	  return 1;
	return 0;

}

int my_printf(int n, int number)
{
	static int i=-1;
	if(++i%n == 0)
	  printf("\n");
	printf("%-5d", number);
}

