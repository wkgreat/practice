#include<stdio.h>

int main(void)
{
	double score;
	char grade;
	printf("Please enter your score>>>");
	scanf("%lf", &score);
	if(score>=90)
	  grade = 'A';
	else if(score>=80)
	  grade = 'B';
	else if(score>=70)
	  grade = 'C';
	else if(score>=60)
	  grade = 'D';
	else
	  grade = 'E';
	printf("Your grade is: %c\n", grade);
	return 0;
}
