
//typedef
#define OK 1
#define ERROR 0
typedef int Status

//bitree
typedef union
{
	int t_int;
	double t_double;
	char t_char;
}Telemtype;

typedef struct BiTNode
{
	Telemtype data;
	struct BiTNode *lchild,  *rchild;
}BiTNode, *Bitree;
//stack
typedef union
{
	int t_int;
	char t_char;
	double t_double;
	BiTNode *t_pbinode;
}Elemtype;

typedef struct
{
	Elemtype *base;
	Elemtype *top;
	int size;
}*SqStack;

//queue
typedef union 
{
	int t_int;
	double t_double;
	char t_char;
	BiTNode *t_pbinode;
}QElemtype, *Pelemtype;

typedef struct
{
	QElemtype *base;
	int head;
	int tail;
}Queue, *Pqueue;

//bi thread tree
typedef enum PointerTag{Link, Thread}; //Link==0 pointer //Thread==1 thread
typedef struct BiThrNode
{
	Telemtype data;
	struct BiThrNode *lchild, *rchild;
	PointerTag ltag, rtag;
}BiThrNode, *BiThrTree;
