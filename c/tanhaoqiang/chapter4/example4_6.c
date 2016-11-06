#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char grade;
	scanf("%c", &grade);
	printf("your score:");
	switch(grade)
	{
		case'A':printf("85~100\n");break;
		case'B':printf("70~84\n");break;
		case'C':printf("60~69\n");break;
		case'D':printf("<60\n");break;
		default:printf("enter data error!");
	}
	return 0;
}
