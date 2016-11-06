#include<stdio.h>

/*给定一个大写字母，将其转换成小写字母*/
/*
   同一个字母，小写字母比大写字母打32
   如：a：97；A：65
 */

int main(void)
{
	char upper;
	printf("Please enter a capital>>>");
	scanf("%c", &upper);
	char lower = upper + 32;
	printf("The lower case is:%c\n\n", lower);
	return 0;
}
