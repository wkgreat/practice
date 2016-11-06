#include<stdio.h>
/*删除字符串中出现的指定字符*/
void squeeze( char s[], int c);

main()
{
	return 0;
}

void squeeze( char s[], int c )
{
	int i, j;

	for(i = j = 0; s[i] != '\0'; i++)
	  if (s[i] != c)
		s[j++] = s[i];
	s[j] = '\0';
}
