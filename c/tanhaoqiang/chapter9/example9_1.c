#include<stdio.h>

int mine(void);
int book(void);

int main(void)
{
	printf("BOOK:\n");
	book();
	return 0;
}

int mine(void)
{
	struct students
	{
		int no;
		char name[10];
		char sex;
		char addr[20];
	}stu[5],*stup;
	int i;
	char temp;
	stup = stu;
	for(i=0;i<5;i++)
	{
		printf("no:");
		scanf("%d",&((stup+i)->no));
		printf("name:");
		scanf("%s",(stup+i)->name);
		printf("sex:");scanf("%c",&temp);
		scanf("%c",&((stup+i)->sex));
		printf("addr:");
		scanf("%s",(stup+i)->addr);
	}
	for(i=0;i<5;i++)
	{
		printf("\nno:%d ",(stup+i)->no);
		printf("name:%s ",(stup+i)->name);
		printf("sex:%c ",(stup+i)->sex);
		printf("addr:%s ",(stup+i)->addr);
	}
	return 0;
}

int book(void)
{
	struct Student
	{
		long int num;
		char name[20];
		char sex;
		char addr[20];
	}a = {10101,"Li lin",'M',"123 Beijing Road"};
	printf("NO.:%ld\nname:%s\nsex:%c\naddr:%s\n",a.num,a.name,a.sex,a.addr);
	return 0;
}
