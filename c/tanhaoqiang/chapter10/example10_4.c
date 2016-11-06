#include<stdio.h>
#include<stdlib.h>

struct Student
{
	int no;
	char name[10];
	int age;
}stu={0,"Wangke",22};
struct Student stu2;

int mine(void);
int main(void)
{
	mine();
	return 0;
}

int mine(void)
{
	char filename[10], filename2[10];
	FILE *fp;
	FILE *fp2;
	printf("Please enter a filename: ");
	scanf("%s", filename);getchar();

	if(!(fp=fopen(filename,"wb")))
	{
		printf("Open file error!");
		exit(0);
	}

	fwrite(&stu,sizeof(struct Student),1,fp);
	fclose(fp);
	if(!(fp2=fopen(filename,"rb")))
	{
		printf("open file error!");
		exit(0);
	}
	fread(&stu2,sizeof(struct Student),1,fp2);
	printf("%d,%s,%d\n", stu2.no, stu2.name, stu2.age);
	fclose(fp2);

}
