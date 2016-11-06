/*
 *author: Wang Ke
 *date: 2014.4.13
 */
#include<stdio.h>
#define PI 3.1415926

int main(void)
{
	float d;
	float volumn;
	printf("Please enter the diameter of the ball>>>");
	scanf("%f", &d);
	volumn = 4.0f/3.0f*PI*(d*d*d);
	printf("The volum of the ball is %f\n", volumn);
	return 0;
}
