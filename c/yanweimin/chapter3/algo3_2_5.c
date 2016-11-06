#include<stdio.h>
#include<stdlib.h>
#include"./stack.h"

char *inputexpression();
double calculate(char *);
char *convertexpression(char *);
int chartype(char c);
int operank(char c);

int main(void)
{
	char *express1 = inputexpression();
	printf("start expression: %s\n@@@Converting...@@@\n", express1);
	char *express2 = convertexpression(express1);
	printf("The convert expression: %s\n", express2);
	printf("@@@calculating...@@@\n");
	double result = calculate(express2);
	printf("The result is: %lf", result);
	return 0;
}

char *inputexpression()
{
	printf("Please enter a expression>>>\n");
	char ch;
	char *expression = (char *)malloc(sizeof(char)*100);
	char *pexp = expression;
	while((ch=getchar()) != '\n')
	{
		*pexp++ = ch;
	}
	*pexp = '\0';
	printf("%s\n", expression);
	return expression;
}

double calculate(char *ex)
{
	SqStack number = initstack();
	printf("Calculating: %s\n",ex);
	char *pc = ex;
	double temp;
	Elemtype a, b, r;
	while(*pc)
	{
		printf("c:%c\n", *pc);
		switch(*pc)
		{
			case '+':
				b = pop(number);
				a = pop(number);
				//printf("%lf + %lf\n",a.t_double,b.t_double);
				r.t_double = a.t_double+b.t_double;
				push(number, r);
				break;
			case '-':
				b = pop(number);
				a = pop(number);
				//printf("%lf - %lf\n",a.t_double,b.t_double);
				r.t_double = a.t_double-b.t_double;
				push(number, r);
				break;
			case '*':
				b = pop(number);
				a = pop(number);
				//printf("%lf * %lf\n",a.t_double,b.t_double);
				r.t_double = a.t_double*b.t_double;
				push(number, r);
				break;
			case '/':
				b = pop(number);
				a = pop(number);
				//printf("%lf / %lf\n",a.t_double,b.t_double);
				r.t_double = a.t_double*1.0/b.t_double;
				push(number, r);
				break;
			default:
				temp = (double)(*pc)-48;
				//printf("%lf\n", temp);
				r.t_double = temp;
				push(number, r);
				break;
		}
		pc++;
	}
	return gettop(number).t_double;
}

int chartype(char c)
{
	if(c>=48 && c<= 57)
	  return 1;//number
	if(c==42 || c==43 || c==45 || c==47)
	  return 2;//operator
	if(c==40) return 3;//left
	if(c==41) return 4;//right
	if(c=='\0') return 0;//#
	return -1;
}

char *convertexpression(char *ex)
{
	char *pcur = ex;
	char *resultstring = (char*)malloc(sizeof(char)*50);
	int i;
	SqStack oper = initstack();
	SqStack resultex = initstack();
	Elemtype ch, temp;
	Elemtype e;
	Elemtype *cur, *pe = resultex->base;
	temp.t_char = '#';
	push(oper, temp);
	while(1)
	{

		e.t_char = *pcur;


		printseparat(50, '_');
		cur = oper->base;
		printf("oper: ");
		print_char_stack(oper);
		printf("\t\t<<< %c\n", e.t_char);
		printf("resu: ");
		print_char_stack(resultex);
		printseparat(50, '_');

		switch (chartype(e.t_char))
		{
			case 1: push(resultex, e);break; //number
			case 2://oper
				printf("%c|%c\n", *pcur, gettop(oper).t_char);
				while(operank(e.t_char) <= operank(gettop(oper).t_char))
				{
					push(resultex, pop(oper));
				}
				push(oper, e);
				break;
			case 3: push(oper, e);break; //left
			case 4://right
					printf("OK");
					ch = pop(oper);
					while(chartype(ch.t_char) != 3)
					{
						push(resultex, ch);
						ch = pop(oper);
					}
					break;

			case 0://'\0'
					ch = pop(oper);
					printf("ch: %c\n", ch.t_char);
					while(ch.t_char != '#')
					{
						push(resultex, ch);
						ch = pop(oper);
					}
					temp.t_char = '\0';
					push(resultex, temp);

					
					cur = resultex->base;
					printf("^^^^^^^^^^^^^^^\n");
					i=0;
					while(cur != resultex->top)
					{
						printf("%c", (*cur).t_char);
						resultstring[i] = (*cur).t_char;
						cur++;i++;
					}
					resultstring[i] = '\0';
					printf("resultstring: %s\n", resultstring);
					printf("^^^^^^^^^^^^^^^^\n");

					return resultstring;
					break;
			default:
					printf("Exits inlegal character in inputed expression!!!");
					exit(0);
		
		}

		pcur++;
	}
}

int operank(char c)
{
	switch(c)
	{
		case '#': return 0;
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return -1;
}








