#include<stdio.h>
#include<math.h>

double get_distance(double x, double y, double x0, double y0);

int main(void)
{
	double x, y;
	double height;
	printf("Please enter the coordinate>>>");
	scanf("%lf,%lf", &x, &y);
	if(get_distance(x,y,2,2)<=1 || get_distance(x,y,-2,2)<=1 || get_distance(x,y,-2,-2)<=1 || get_distance(x,y,2,-2)<=1)
	  height = 10;
	else
	  height = 0;

	printf("The height is: %lf", height);
	return 0;
}

double get_distance(double x, double y, double x0, double y0)
{
	double distance;
	distance = sqrt(pow(x-x0,2) + pow(y-y0,2));
	return distance;
}


