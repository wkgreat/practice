#include<stdio.h>
/*
   ��ϰ1-12 ��дһ��������ÿ��һ�����ʵ���ʽ��ӡ�����
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
