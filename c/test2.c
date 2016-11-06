#include<stdio.h>
#include<string.h>

main()
{

	void test1();
	void test2();

	test1();
	test2();
	
	return 0;
}

void test1()
{
	struct point{
		int x;
		int y;
	} point1= {
		1,1
	};

	printf("%d\n", point1.x);
}

void test2()
{
	char line[5] = {'1','2','3','4','5'};
	printf("%s\n", line);
	char *pline = line;
	char line2[] = pline+1;
	printf("%s\n", line2);

}
