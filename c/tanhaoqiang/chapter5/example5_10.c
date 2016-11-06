#include<stdio.h>
#include<math.h>

int mine(void);
int is_prime(int n);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	int i;
	for(i=101;i<200;i+=2)
	  if(is_prime(i)) printf("%d\n", i);
	return 0;
}

int is_prime(int n)
{
	int i;
	double t=sqrt(n);
	for(i=2;i<t;i+=1)
	  if(n%i==0) break;
	if(i<=t) return 0;
	else return 1;
}
