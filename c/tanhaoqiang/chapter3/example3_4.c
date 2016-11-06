#include<stdio.h>
#include<math.h>
/*给定三个边的长度，求三角形面积*/

int triangle_area(double a, double b, double c);

int main(void)
{
	double a, b, c, area;
	printf("Please enter the length of the three sides\na b c>>>");
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("%lf %lf %lf\n", a, b, c);
	area = triangle_area(a, b, c);
	printf("The area of this triangle is %f\n", area);
	return 0;
}

int triangle_area(double a, double b, double c)
{
	double s = (a+b+c)/2.0;
	double area = sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}
