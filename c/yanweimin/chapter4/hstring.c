#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;

typedef struct _hstring
{
	char *base;
	int length;
}Hstring, *Phstring;

Status strassign(Phstring, char *);
Status strcopy(Phstring, Hstring);
int strempty(Hstring);
int strcompare(Hstring, Hstring);
int strlength(Hstring);
Status clearstring(Phstring);
Status concat(Phstring, Hstring, Hstring);
Status substring(Phstring, Hstring, int pos, int len);
//int index(Hstring, Hstring, int pos);
//Status replace(Phstring, hstring, hstring);
//Status strinsert(Phstring, int pos, Hstring);
//Status strdelete(Phstring, int pos, int len);
//Status destroystring(Phstring);

int printseparate(int, char);
char *getstring(void);

int main(void)
{
	Hstring string1 = {0,0};
	Hstring string2 = {0,0};
	Hstring string3 = {0,0};
	printf("please enter two string>>>\n");
	char *a = getstring();
	char *b = getstring();
	strassign(&string1, a);
	strassign(&string2, b);
	printf("string1: %s\tlength: %d\n", string1.base, strlength(string1));
	printf("string2: %s\tlength: %d\n", string2.base, strlength(string2));
	printf("string1 vs string2: %d\n", strcompare(string1, string2));
	concat(&string3, string1, string2);
	printf("string3: %s\tlength: %d\n", string3.base, strlength(string3));
	substring(&string1, string3, 3, 5);
	printf("substring(&string1, string3, 3, 5) - string1: %s\n", string1.base);
	return 0;
}

int printseparate(int n, char ch)
{
	int i;
	for(i=1;i<=n;i++) putchar(ch);putchar('\n');
}

char *getstring(void)
{
	int initsize = 20, increment = 10;
	int size = initsize;
	printf("(string)>>>");
	char *string = (char *)malloc(sizeof(char)*initsize);
	char *cur = string;
	char ch;
	while((ch=getchar()) != '\n')
	{
		*cur++ = ch;
		if(cur-string >= size)
		{
		  string = (char *)realloc(string, size+increment);
		  cur = string + size;
		  size += increment;
		}
	}
	*cur = '\0';
	return string;
}

Status strassign(Phstring string, char *chars)
{
	if(string->base) free(string->base); ////
	
	int len=1, i;
	if(!chars)
	{
		string->base = 0; string->length = 0;
	}
	for(len=0; *(chars+len); len++);
	if(!len) { string->base = NULL; string->length = 0; return OK;}
	
	string->base = (char*)malloc(sizeof(char)*(len+1));
	if(!string->base) {printf("Create string failed!\n"); return ERROR;}
	for(i=0; i<len; i++)
	{
		*(string->base+i) = *(chars+i);
	}
	*(string->base+len) = '\0';
	string->length = len;
	return OK;
}

Status strcopy(Phstring t, Hstring s)
{
	if(!s.base) {t->base=0; t->length=0; return OK;}
	if(!strassign(t, s.base)) return ERROR;
	return OK;
}

int strempty(Hstring s)
{
	return (!s.length);
}

int strcompare(Hstring s1, Hstring s2)
{
	int minlen = (s1.length < s2.length)?s1.length:s2.length;
	int i;
	for(i=0;i<minlen;i++)
	{
		if(s1.base[i] == s2.base[i] ) continue;
		if(s1.base[i] > s2.base[i]) return 1;
		else return -1;
	}
	if(s1.length == s2.length) return 0;
	if(s1.length > s2.length) return 1;
	else return -1;
}

int strlength(Hstring string)
{
	return string.length;
}

int clearstring(Phstring string)
{
	if(string->length)
	{
		free(string->base);
		string->base = NULL;
	}
	string->length = 0;
	return OK;
}


Status concat(Phstring new, Hstring s, Hstring t)
{
	int len = s.length + t.length;
	if(len==0) {printf("yes");new->base=NULL; new->length=0; return OK;}
	if(new->base) free(new->base); //free
	new->base = (char *)malloc(sizeof(char)*(len+1));
	char *s_cur = s.base;
	char *t_cur = t.base;
	char *cur = new->base;
	while(s_cur && *s_cur)
	  *cur++ = *s_cur++;
	while(t_cur && *t_cur)
	  *cur++ = *t_cur++;
	*cur = '\0';
	new->length = len;
	return OK;

}

Status substring(Phstring new, Hstring s, int pos, int len)
{//0 <= pos <= length-1 ; 0 <= len <= length - pos
	if(!(pos>=0 && pos<=s.length-1 && len>=0 && len<=s.length-pos)) 
		{ printf("######the index is overflow. substring is failed!\n");return ERROR;}
	if(new->base) free(new->base); // free
	if(!len){new->base = NULL; new->length = 0; return OK;} // empty string
	if(!(new->base=(char*)malloc(sizeof(char)*(len+1)))) return ERROR;
	char *cur = s.base+pos;
	int i;
	for(i=0;i<len;i++)
	{
		*(new->base+i) = *(cur+i);
	}
	new->length = len;
	*(new->base+len) = '\0';
	return OK;
}

