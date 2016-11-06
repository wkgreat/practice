#include<stdio.h>
/*
   练习1-12 编写一个程序，以每行一个单词的形式打印其输出
 */

main()
{
	int c;
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
		{
			putchar('\n');
			continue;
		}
		putchar(c);
	}
}
