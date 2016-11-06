#include<stdio.h>
#include<string.h>

main()
{
	void test1(void);

	test1();

	return 0;
}

void test1(void)
{
	FILE *fp;

	if((fp = fopen("test.txt", "w+")) == NULL)
	{
		printf("error when open file!\n");
		exit(0);
	}

	int i;

	for(i=0; i<100; ++i)
	{
		fputc(i, fp); //how to convert a integer to a char??
	}

	fclose(fp);
}


