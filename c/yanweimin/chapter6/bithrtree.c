#include<stdio.h>
#include<stdlib.h>
#include"./bitreehead.h"

//function prototype
Status createBiThrTree(BiThrTree, char**);

int main(void)
{
	printf("Not Complelte!!!");
}

Status createBiThrTree(BiThrTree tree, char **string)
{
	if(!string || !*string) return ERROR;
	if(!(**string)) {tree = NULL; return OK;}
	if(**string == " ") return NULL;
	else
	{
		if(!tree=(BiThrNode*)malloc(sizeof(BiThrNode))) return ERROR;
		(*string)++;
		createBiThrTree(tree->lchild, string);
		(*string)++;
		createBiThrTree(tree->rchild, string);
	}

}
