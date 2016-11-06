#include<stdio.h>
#include<math.h>

/* chapter2 example2.5 */
int is_prime(int n);

int main(void)
{
	int i;
	for(i=3; i<100; ++i)
	  if(is_prime(i))
		printf("%d\n", i);
	return 0;
}

int is_prime(int n)
{
	int i;
	double threshold = sqrt(n);
	//printf("%d/%f\n", n, threshold);
	for(i=2; i<=threshold; ++i) //仅仅到n的开方即可
	  if(n%i == 0) break;
	if(i >= threshold)
	  return 1;
	else 
	  return 0;
}
