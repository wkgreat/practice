#include<stdio.h>

int main(void)
{
	int h, m;
	printf("Enter a 24-hour time(hh:mm): ");
	scanf("%d:%d", &h, &m);
	printf("Equivalent 12-hour time: %d:%d PM\n", h>12?h-12:h, m);
	return 0;
}
