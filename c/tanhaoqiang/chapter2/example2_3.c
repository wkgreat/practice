#include<stdio.h>

/*第二章 例子2.3*/
/* 打印闰年 */
int is_leap(int year);

int main(void)
{
	for(int y=0; y<10000; ++y)
		if(is_leap(y))
		  printf("%d\n", y);
	return 0;
}

int is_leap(int year)
{
	if(year%4 == 0 && (year%100 != 0 || year%400 == 0))return 1;
	else return 0;
}
