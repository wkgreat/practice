#include<stdio.h>

/*����һ����д��ĸ������ת����Сд��ĸ*/
/*
   ͬһ����ĸ��Сд��ĸ�ȴ�д��ĸ��32
   �磺a��97��A��65
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
