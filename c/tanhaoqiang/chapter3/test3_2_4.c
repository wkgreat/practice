#include<stdio.h>

/*��ӡ1��127�������ַ�*/

int main(void)
{
//	test1();
	test2();
	return 0;
}

int test1(void)
{/*��ӡ1��127�������ַ�*/

	int i=0;
	char c;
	for(i=0; i<128; ++i)
	{
		c = i;
		printf("%3d:%c ", i, c);
		if(i%10==0) printf("\n");
	}
	printf("\n");
	return 0;
}

int test2(void)
{/*�����չ�ַ� ��ASCII����128��255*/
	unsigned char c = 128;
	for(c=128; c<130; ++c)
		printf("%d:%c\n", c, c);
	printf("\n");
	return 0;
}
