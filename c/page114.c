#include<stdio.h>

/* ���Գ��������в������汾1*/
main(int argc, char *argv[])
{
	int i;

	for(i = 1; i < argc; i++)
	{
		printf("%s%s", argv[i], (i<argc-1) ? " " : "");//wk:�ڵ���û����ʱ��ÿ����һ�����ʣ���ӡһ���ո񣻶������ʴ���ʱ�����ٴ�ӡ�ո���
	}
	printf("\n");

	return 0;
}
