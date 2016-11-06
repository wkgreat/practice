#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE	15

#define OK 1
#define ERROR 0

typedef int Status;

typedef union 
{
	int t_int;
	double t_double;
	char t_char;
}Elemtype, *Pelemtype;

typedef struct
{
	Elemtype *base;
	int head;
	int tail;
}Queue, *Pqueue;

int initqueue(Pqueue);
int queuelength(Pqueue);
int enqueue(Pqueue, Elemtype);
Status dequeue(Pqueue, Pelemtype);
int reversequeue(Pqueue);
int print_int_queue(Pqueue);
int print_char_queue(Pqueue);
int print_double_queue(Pqueue);

int main(void)
{
	printf("Initqueue:\n");
	Queue queue;
	initqueue(&queue);
	printf("enqueue 1\n");
	Elemtype e;
	int i;
	for(i=1;i<=10;i++)
	{
		e.t_int = i;
		enqueue(&queue, e);
	}
	print_int_queue(&queue);
	printf("reverse:\n");
	reversequeue(&queue);
	print_int_queue(&queue);
	printf("dequeue:\n");
	Elemtype de;
	while(dequeue(&queue, &de))
	{
		printf("%d\t", de.t_int);
		print_int_queue(&queue);
	}
	i=0;
	while(i++<10)
	{
		e.t_int = i*2;
		printf("~~%d\n", e.t_int);
		enqueue(&queue, e);
	}
	print_int_queue(&queue);
	printf("reverse:\n");
	reversequeue(&queue);
	print_int_queue(&queue);
}

int initqueue(Pqueue queue)
{
	//Pqueue queue = (Pqueue)malloc(sizeof(Queue));
	queue->base = (Elemtype*)malloc(sizeof(Elemtype)*MAXSIZE);
	if(!queue->base) {printf("initiate queue failed!\n"); return ERROR;}
	queue->head = queue->tail = 0;
	return OK;
}

int queuelength(Pqueue queue)
{
	return (queue->tail - queue->head + MAXSIZE) % MAXSIZE;
}

int enqueue(Pqueue queue, Elemtype e)
{
	if((queue->tail+1) % MAXSIZE - queue->head == 0) {printf("The queue has been overflow!\n"); return 1;}
	queue->base[queue->tail] = e;
	queue->tail = (queue->tail+1) % MAXSIZE;
	return 0;
}

Status dequeue(Pqueue queue, Pelemtype pe)
{
	if(queue->head == queue->tail) {printf("The queue is empty!\n"); return ERROR;}
	*pe = queue->base[queue->head];
	queue->head = (queue->head+1) % MAXSIZE;
	return OK;
}

int reversequeue(Pqueue queue)
{
	if(queue->head == queue->tail){printf("The queue is EMPTY!\n"); return ERROR;}
	int head = queue->head;
	int tail = queue->tail;
	if (tail<head) tail+=MAXSIZE;
	Elemtype e;
	for(;head<tail-1;head++,tail--)
	{
		e = queue->base[head%MAXSIZE];
		queue->base[head%MAXSIZE] = queue->base[(tail-1)%MAXSIZE];
		queue->base[(tail-1)%MAXSIZE] = e;
	}
	return OK;
}

int print_int_queue(Pqueue queue)
{
	int cur = queue->head;
	if(cur == queue->tail) {printf("EMPTY!\n"); return OK;}
	while(cur != queue->tail)
	{
		printf(" %d ->", (queue->base[cur]).t_int);
		cur = (cur+1) % MAXSIZE;
	}
	printf("\b\b  \n");
	return OK;
}


int print_char_queue(Pqueue queue)
{
	int cur = queue->head;
	if(cur == queue->tail) {printf("EMPTY!\n"); return OK;}
	while(cur != queue->tail)
	{
		printf("%c", (queue->base[cur]).t_char);
		cur = (cur+1) % MAXSIZE;
	}
	printf("\n");
	return OK;
}


int print_double_queue(Pqueue queue)
{
	int cur = queue->head;
	if(cur == queue->tail) {printf("EMPTY!\n"); return OK;}
	while(cur != queue->tail)
	{
		printf(" %.4lf ->", (queue->base[cur]).t_double);
		cur = (cur+1) % MAXSIZE;
	}
	printf("\b\b  \n");
	return OK;
}


