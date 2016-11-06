#include<stdio.h>

/*打印1到127的所有字符*/

int main(void)
{
//	test1();
	test2();
	return 0;
}

int test1(void)
{/*打印1到127的所有字符*/

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
{/*检查扩展字符 及ASCII代码128到255*/
	unsigned char c = 128;
	for(c=128; c<130; ++c)
		printf("%d:%c\n", c, c);
	printf("\n");
	return 0;
}
