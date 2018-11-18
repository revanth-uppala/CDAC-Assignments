#include<stdio.h>
#include<stdlib.h>
struct nodeDLL
{
  int val;
  struct nodeDLL *nextDLL,*previous;
};
typedef struct nodeDLL nodeDLL;
nodeDLL *headDLL = NULL;
nodeDLL *lastDLL = NULL;

void displayrev()
{
  if(lastDLL == NULL)
  {
    printf("\nLinked List is empty\n");
    return;
  }
  nodeDLL *temp = lastDLL;
  while(temp != NULL)
  {
    printf("%d->",temp->val);
    temp = temp->previous;
  }
  printf("\n");
  return;

}
void displayDLL()
{
  if(headDLL == NULL)
  {
    printf("\nLinked List is empty\n");
    return;
  }
  nodeDLL *temp = headDLL;
  printf("\n");
  while(temp->nextDLL != NULL)
  {
    printf("%d->",temp->val);
    temp = temp->nextDLL;
  }
  printf("%d->",temp->val);
  printf("\n");
  return;
}
void insertbegDLL(int data)
{
  nodeDLL *new;
  new = malloc(sizeof(nodeDLL));
  if(new == NULL)
  {
    printf("Overflow.Cannot insert\n");
    return;
  }
  new->val = data;
  if(headDLL == NULL)
  {
    headDLL = new;
    lastDLL = new;
    new->nextDLL = NULL;
    new->previous = NULL;
    return;
  }
  new->nextDLL = headDLL;
  headDLL->previous = new;
  new->previous = NULL;
  headDLL = new;
  return;

}
void insertendDLL(int data)
{
  nodeDLL *new;
  new = malloc(sizeof(nodeDLL));
  if(new == NULL)
  {
    printf("Overflow.Cannot insert\n");
    return;
  }
  new->val = data;
  if(headDLL == NULL)
  {
    headDLL = new;
    lastDLL = new;
    headDLL->nextDLL = NULL;
    headDLL->previous = NULL;
    return;
  }
  new->previous = lastDLL;
  lastDLL->nextDLL = new;
  lastDLL = new;
  return;
}
void insertbetweenDLL(int data,int pos)
{
  nodeDLL *new,*temp,*temp1;
  new = malloc(sizeof(nodeDLL));
  if(new == NULL)
  {
    printf("Memory not allocated.Cannot insert\n");
  }
  new->val = data;
  if(headDLL == NULL)
  {
    headDLL = new;
    lastDLL = new;
    new->nextDLL = NULL;
    new->previous = NULL;
    return;
  }
  temp = headDLL;

  while(temp->val != pos)
  {
    temp = temp->nextDLL;
    if(temp == NULL)
    {
      printf("Cannot insert.No %d in list\n",pos);
      return;
    }
  }
  if(temp == lastDLL)
  {
     insertendDLL(data);
     return;
  }

  temp1 = temp->nextDLL;
  temp1->previous = new;
  new->nextDLL = temp1;
  new->previous = temp;
  temp->nextDLL = new;

  return;

}
void deletebegDLL()
{
  if(headDLL == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return;
  }
  nodeDLL *temp = headDLL;
  nodeDLL *temp1;
  if(temp == lastDLL)
  {
    headDLL = NULL;
    lastDLL = NULL;
    free(temp);
    return;
  }
  temp1 = headDLL->nextDLL;
  headDLL = temp1;
  temp1->previous = NULL;
  free(temp);
  return;
}
void deleteendDLL()
{
  if(headDLL == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return;
  }

  nodeDLL *temp,*temp1;
  temp = headDLL;
  if(temp == lastDLL)
  {
    headDLL = NULL;
    lastDLL = NULL;
    free(temp);
    return;
  }
  temp = lastDLL;
  temp1 = lastDLL->previous;
  temp1->nextDLL = NULL;
  lastDLL = temp1;
  free(temp);
  return;
}
void deletebetweenDLL(int data)
{
  nodeDLL *temp,*temp1,*temp2;
  if(headDLL == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return;
  }
  temp = headDLL;
  temp1 = temp;
  while(temp->val != data)
  {
    temp1 = temp;
    temp = temp->nextDLL;
    if(temp == NULL)
    {
      printf("Value not found in Linked List\n");
      return;
    }
  }
  if(temp == headDLL)
  {
    deletebegDLL();
    return;
  }
  if(temp == lastDLL)
  {
    deleteendDLL();
    return;
  }

  temp2 = temp->nextDLL;
  temp1->nextDLL = temp2;
  temp2->previous = temp1;
  free(temp);
  printf("After deleting %d :\n",data);
  displayDLL();
  return;

}
