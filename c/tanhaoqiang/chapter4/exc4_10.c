#include<stdio.h>

int main(void)
{
	double profit, bonus;
	int d;
	printf("Please enter the profit>>>");
	scanf("%lf", &profit);
	if(profit>=1e6)
	  d = 10;
	else d = (profit-1)/1e5;
	switch(d)
	{
		case 0:
			bonus = profit*0.1;
			break;
		case 1:
			bonus = 1e5*0.1+(profit-1e5)*0.075;
			break;
		case 2:
		case 3:
			bonus = 1e5*0.1+1e5*0.075+(profit-2e5)*0.05;
			break;
		case 4:
		case 5:
			bonus = 1e5*0.1+1e5*0.075+2e5*0.05+(profit-4e5)*0.03;
			break;
		case 6:
		case 7:
		case 8:
		case 9:
			bonus = 1e5*0.1+1e5*0.075+2e5*0.05+2e5*0.03+(profit-6e5)*0.015;
			break;
		case 10:
			bonus = 1e5*0.1+1e5*0.075+2e5*0.05+2e5*0.03+4e5*0.015+(profit-1e6)*0.01;
			break;
		default:
			break;
	}

	printf("The bonus is: %lf\n", bonus);
	return 0;
}
