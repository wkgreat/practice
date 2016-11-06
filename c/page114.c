#include<stdio.h>

/* 回显程序命令行参数，版本1*/
main(int argc, char *argv[])
{
	int i;

	for(i = 1; i < argc; i++)
	{
		printf("%s%s", argv[i], (i<argc-1) ? " " : "");//wk:在单词没打完时，每打完一个单词，打印一个空格；而当单词打完时，不再打印空格了
	}
	printf("\n");

	return 0;
}
