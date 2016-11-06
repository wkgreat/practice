#include<stdio.h>
/*将输入复制到输出的:版本1
 EOF linux 在终端控制台输入ctrl+d结束
     windows 中输入ctrl+z         */

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
