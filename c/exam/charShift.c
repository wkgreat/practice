#define MAX 1000
#include<stdio.h>
void exchangeIndex(char*, int, int);
void sinkChar(char*, int);
int isCapital(char);

int main(argc, argv)
{
	char *s;
	scanf("%s", s);
	char *ps = s;
	int flag = 0;
	int ach = MAX;
	int length = 0;
	int i;
	for(i=0; ps[i]; ++i)
	{
		if(isCapital(ps[i]))
		{
			flag = 1;
		}
	}

	length=i;
	if(!flag)
	{
		printf("No A-Z\n");
		return 0;
	}

	
	for(i=0; ps[i]; ++i)
	{
//		printf("%d", i);
		if(i==ach) break;
		if(isCapital(ps[i]))
		{
			sinkChar(ps,i);
			--i;
			if(ach==MAX) ach=length-1;
			else ach-=1;
		}
	}

	printf("%s\n", s);

	exchangeIndex(s, 1, 2);
	printf("%s", s);
	return 0;
}

int isCapital(char c)
{
	if(c>='A' && c<='Z') return 1;
	else return 0;
}

void exchangeIndex(char* s, int i, int j)
{
	s[j] += s[i];
	s[i] = s[j]-s[i];
	s[j] -= s[i];
}

void sinkChar(char*s, int i)
{
	int j;
	for(j=i+1; s[j]; ++j) exchangeIndex(s,j-1,j);
}
