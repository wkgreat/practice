#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define frand() ( (double) rand() / (RAND_MAX+1.0))

main()
{
	void test1();
	void test2();
	void test3();
	void test4();
	void test5();
	void test6();
	void test7();

	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();
	return 0;
}

void test1()
{

	int a, b, c;
	char line[] = "1 2 3";
	sscanf(line, "%d %d %d", &a, &b, &c);
	printf("%d %d %d", a, b, c);
}

void test2()
{
	int a[5] = {1,2,3,4,5};
	
	int n = 5;
	
	int *pa = a;

	while(*pa++ && --n)
	{
		printf("%d", *a);
	}

}

void test3()
{
	FILE *fp = fopen("test.txt", "r");

	char c;

	while((c=getc(fp)))
	{
		printf("%c", c);
	}

	fclose(fp);

}

void test4()
{
	/*
	   use the functions : fgets() fputs()
	 */

	FILE *fp = fopen("test.txt", "r");

	//fputs("abcd\n", fp);
	//fputs("1234\n", fp);

	printf("Please enter a centense:\n");

	char line[1000];
	while(fgets(line,1000, fp))
	  printf("%s", line);

	fclose(fp);


}

void test5()
{
	/*
	   two string is same?
	 */

	char line1[100];
	char line2[100];
	
	printf("Please enter a line:\n");
	gets(line1);
	printf("\nPlease enter another line:\n");
	gets(line2);

	if(!strcmp(line1, line2))
	{
		printf("\nthe two line is same!\n");
	}
	else
	{
		printf("\nthe two string is not same!\n");
	}
}

void test6()
{
	/*
	   rand
	 */
	printf("%d\n", RAND_MAX);
	printf("%f\n", (double)RAND_MAX+1);
	printf("rand() : %d\n", rand());

	double r = frand();
	printf("the random number range in 0 to 1 :%f\n", r);


}

void test7()
{
	//unlink("test.txt");
}

