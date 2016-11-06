#include<stdio.h>

#define IN 1 /*在单词内*/
#define OUT 0 /*在单词外*/
/*
	统计行数、单词数与字符数
	这段程序是UNIX系统中wc程序的骨干成分
 */

main()
{
	int c, n1, nw, nc, state;

	state = OUT;
	n1 = nw = nc = 0;
	while((c = getchar()) != EOF)
	{
		++nc;
		if(c == '\n')
			++n1;
		if(c == ' ' || c == '\n' || c == '\t')
		  state = OUT;
		else if (state == OUT) //wk:若实际已在单词内了，但是state还是OUT，则单词加1
		{
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d \n", n1, nw, nc);
}
