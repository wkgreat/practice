#include<stdio.h>
/* not successful */

/*´ÓÃüÁîĞĞÊäÈë¾ØÕó*/
void getmatrix( int a[]); /* version 1*/
void getmatrix2( int a[]); /* version 2*/

main()
{

	int a[20];
	getmatrix2(a);

	printf("get the matrix:\n");
	int *pa = a;
	int n = 0;
	while(*pa != '\0' && n++ < 10)
	{
		printf("%d ", *pa);
		pa++;
	}
	printf("\n");

	return 0;
}

void getmatrix( int a[])
{
	int c;
	char number[10];
	int i = 0;
	int *pa = a;
	char *pnumber = number;
	int enterline = 0;

	while(c = getchar())
	{
		if(c == ' ')
		{
			*pnumber++ = '\0';
			*pa++ = atoi(number);
			pnumber = number;
		}
		else if( c == '\n' )
		{
			if( !enterline )
			{
				enterline = 1;
				*pnumber++ = '\0';
				*pa++ = atoi(number);
				pnumber = number;
			}
			else
			{
				*pa++ = '\0';
				break;
			}
		}
		else
		{
			enterline = 0;
			*pnumber++ = c;
		}
	}


}

void getmatrix2( int a[])
{
	/*
	   the char have 4 types;
	   1. space or tab ' ' or '\t'
	   2. enter '\n'
	   3. digit '0' ~ '9'
	   4. other invalid
	 */

	int state = 2;
	char number[20];
	char *pnumber = number;
	int *pa = a;
	int height = 0, width = 0;
	char c;

	while(c = getchar())
	{
		if ( c >= 48 && c <= 57)
		{
			state = 0;
			*pnumber++ = c;
			continue;
		}
		else if( c == ' ' || c == '\t' || c == '\n')
		{
			if(state)
			{
				if( c == '\n')
				{
					if( state == 2)
					{
						*pa++ = '\0';
						break;
					}else
					{
						state = 2;
						continue;
					}
				}
				else
				{
					state = 1;
					continue;
				}
			}
			*pnumber++ = '\0';
			pnumber = number;
			*pa++ = atoi(number);
			(c == ' ') ? (state = 1) : (state = 2);

		}

	}



}
