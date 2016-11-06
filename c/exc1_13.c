#include<stdio.h>
#define OUT 0
#define IN 1
/*
   exc 1-13 pagee24
 */
void histogram(int array[], int length)
{
	int max = 0;
	int i;
	int j;
	for(i = 0; i < length; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	for(i = max; i>=0; --i)
	{
	  for(j = 0; j < length; j++)
	  {
		  if(array[j] >= i)
		  {
			  printf("| ");
		  }
		  else
		  {
			  printf("  ");
		  }

	  }
	  printf("\n");
	}
}
main()
{
	int list[20];
	int i, c, length,state;
	length = 0;
	state = OUT;
	for(i = 0; i < 20; ++i)
	{
		list[i] = 0;
	}
	while((c = getchar()) != EOF)
	{
		if(c == ' ' || c == '\n' || c=='\t')
		{
			if(state == IN)
			{
				++list[length];
				length = 0;
				state = OUT;
			}
		}
		else
		{
			if(state == OUT)
				state = IN;
			++length;

		}
	}

	for(i = 0; i < 20; ++i)
	{
		printf("%d ", list[i]);
	}
	printf("\n");

	histogram(list, 20);

}

