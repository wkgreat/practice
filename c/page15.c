#include<stdio.h>
/*�����븴�Ƶ������:�汾1
 EOF linux ���ն˿���̨����ctrl+d����
     windows ������ctrl+z         */

main()
{
	int c;
	printf("Please enter string:\n");
	c = getchar();
	while(c != EOF)
	{
		putchar(c);
		c = getchar();
	}

}
