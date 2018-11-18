#include<stdio.h>
#include<stdlib.h>
#include "DS_lib.h"
int main()
{
	node *headLL = NULL;
	node *headDLL = NULL;
	stack *S = NULL;
	S = stackinit(S);
	int data = 5;
	printf("Data = 5\nInserting into SLL..\n");
	headLL = insertbeg(headLL,data);
	printf("Inserting Data into DLL..\n");	
	insertbegDLL(data);
	printf("Inserting Data onto stack..\n");
	push(S,data);
	printf("SLL: \n");	
	display(headLL);
	printf("DLL: \n"); 	
	displayDLL(headDLL);
	printf("TOS = %d\n",TOS(S));
	return 0;
}
