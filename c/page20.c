#include<stdio.h>

#define IN 1 /*�ڵ�����*/
#define OUT 0 /*�ڵ�����*/
/*
	ͳ�����������������ַ���
	��γ�����UNIXϵͳ��wc����ĹǸɳɷ�
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
		else if (state == OUT) //wk:��ʵ�����ڵ������ˣ�����state����OUT���򵥴ʼ�1
		{
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d \n", n1, nw, nc);
}
