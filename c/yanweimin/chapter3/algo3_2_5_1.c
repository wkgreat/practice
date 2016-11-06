#include<stdio.h>
#include"./stack.h"
#include<stdlib.h>

char* convert(char *);
int rank(char);
int chartype(char);
int main(void)
{
	char ex[50] = "1+2+(3+4*5)*6+7";
	printf("exression: %s\n\n", ex);
	printf("###CONVERT###\n");
	char *result;
	result = convert(ex);
	printf("\n\n");
	printf("result: %s\n", result);
	return 0;
}

char* convert(char *expression)
{
	char *current_ch = expression;
	char *result1, *result2;
	result1 = (char*)malloc(sizeof(char)*100);
	result2 = result1;
	SqStack oper = initstack();
	SqStack resu = initstack();
	Elemtype e_temp;
	Elemtype e_cur;
	Elemtype *p_e_cur;
	e_temp.t_char = '#'; push(oper, e_temp);
	e_temp.t_char = *current_ch;
	int i=0;char ch;
	while(1)
	{
		e_temp.t_char = *current_ch++;

		printf("%d\n", ++i);
		printf("oper: "); print_char_stack(oper);
		printf("\t<<< %c\n", e_temp.t_char);
		printf("resu: "); print_char_stack(resu);

		switch(chartype(e_temp.t_char))
		{
			case 0://end
				e_cur = pop(oper);
				while(e_cur.t_char != '#')
				{
					push(resu, e_cur);
					e_cur = pop(oper);
				}
				printf("resu: ");print_char_stack(resu);
				p_e_cur = resu->base;
				i=0;
				while(p_e_cur != resu->top)
				{
					*result2++ = (*p_e_cur++).t_char;
				}
				*result2 = '\0';
				printf("~~~ %s\n", result1);
				return result1;

			case 1://number
				push(resu, e_temp);
				break;
			case 2://operator
				while(rank(e_temp.t_char) <= rank(gettop(oper).t_char))
				{
					push(resu, pop(oper));
				}
				push(oper, e_temp);
				break;
			case 3://left
				push(oper, e_temp);
				break;
			case 4://right
				while( gettop(oper).t_char != '(' ) 
					push(resu, pop(oper));	
				pop(oper);
				break;
			default:
					 printf("inlegel charactor!!");
					 exit(0);
					 break;
		}
		
		printseparat(50, '_');


	}
}

int rank(char c)
{
	if(c == '+' || c == '-')
		return 1;
	if( c == '#' || c== '(' ) return 0;
	return 2;
}

int chartype(char c)
{
	if( !c ) return 0; //end sign
	if( c>= '0' && c<= '9' ) return 1; // number
	if( c=='+' || c=='-' || c=='*' || c=='/' ) return 2; //operator
	if( c=='(' ) return 3; // left
	if( c==')' ) return 4; // right
}
