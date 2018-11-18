#include<stdlib.h>
#include<stdio.h>

//SLL functions
struct node
{
  int val;
  struct node *next;
};
typedef struct node node;
void display(node* head);
node *reverse(node *head);
node* insertbeg(node* head,int data);
node* insertend(node* head,int data);
node* insertbetween(node* head,int data,int pos);
node* deletebeg(node* head);
node* deleteend(node* head);
node* deletebetween(node* head,int data);

//DLL functions
struct nodeDLL
{
  int val;
  struct nodeDLL *nextDLL,*previous;
};
typedef struct nodeDLL nodeDLL;

void displayrev();
void displayDLL();
void insertbegDLL(int data);
void insertendDLL(int data);
void insertbetweenDLL(int data,int pos);
void deletebegDLL();
void deleteendDLL();
void deletebetweenDLL(int data);

//stack functions
int pop_data;
struct stack
{
  int *arr,size,top,capacity;
};
typedef struct stack stack;
stack *stackinit(stack *S);
unsigned short IsEmpty(stack *S);
unsigned short IsFull(stack *S);
stack *push(stack *S,int val);
stack *pop(stack *S);
int TOS(stack *S);
void displaystack(stack *S);
