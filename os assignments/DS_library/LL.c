#include<stdio.h>
#include<stdlib.h>
struct node
{
  int val;
  struct node *next;
};
typedef struct node node;
void display(node* head)
{
  if(head == NULL)
  {
    printf("\nLinked List is empty\n");
    return;
  }
  node *temp = head;
  printf("\n");
  while(temp->next != NULL)
  {
    printf("%d->",temp->val);
    temp = temp->next;
  }
  printf("%d->",temp->val);
  printf("\n");
  return;
}
node *reverse(node *head)
{
  if(head == NULL)
  {
    printf("Cannot reverse.Empty List\n");
    return head;
  }
  node *current,*prev,*nextn;
  prev = NULL;
  nextn = NULL;
  current = head;
  while (current != NULL)
  {
    nextn = current->next;
    current->next = prev;
    prev = current;
    current = nextn;
  }
  head = prev;
  return head;
}
node* insertbeg(node* head,int data)
{
  node *new;
  new = malloc(sizeof(node));
  if(new == NULL)
  {
    printf("Overflow.Cannot insert\n");
    return head;
  }
  new->val = data;
  if(head == NULL)
  {
    head = new;
    head->next = NULL;
    return head;
  }
  new->next = head;
  head = new;
  return head;

}
node* insertend(node* head,int data)
{
  node *new,*temp;
  new = malloc(sizeof(node));
  if(new == NULL)
  {
    printf("Overflow.Cannot insert\n");
    return head;
  }
  new->val = data;
  if(head == NULL)
  {
    head = new;
    head->next = NULL;
    return head;
  }
  temp = head;
  while(temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = new;
  new->next = NULL;
  return head;
}
node* insertbetween(node* head,int data,int pos)
{
  node *new,*temp;
  new = malloc(sizeof(node));
  if(new == NULL)
  {
    printf("Memory not allocated.Cannot insert\n");
  }
  new->val = data;
  if(head == NULL)
  {
    new->next = NULL;
    head = new;
    return head;
  }
  temp = head;

  while(temp->val != pos)
  {
    temp = temp->next;
    if(temp == NULL)
    {
      printf("Cannot insert.No %d in list\n",pos);
      return head;
    }
  }
  new->next = temp->next;
  temp->next = new;
  return head;

}
node* deletebeg(node* head)
{
  if(head == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return head;
  }
  node *temp;
  temp = head;
  if(temp->next == NULL)
  {
    head = NULL;
    free(temp);
    return head;
  }
  head = head->next;
  free(temp);
  return head;
}
node* deleteend(node* head)
{
  if(head == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return head;
  }
  node *temp,*previous;
  temp = head;
  previous = NULL;
  if(temp->next == NULL)
  {
    head = NULL;
    free(temp);
    return head;
  }
  while(temp->next != NULL)
  {
    previous = temp;
    temp = temp->next;
  }
  previous->next = NULL;
  free(temp);
  return head;


}
node* deletebetween(node* head,int data)
{
  node *temp,*previous;
  if(head == NULL)
  {
    printf("Underflow.Linked List is empty\n");
    return head;
  }
  temp = head;
  previous = temp;

  while(temp->val != data)
  {
    previous = temp;
    temp = temp->next;
    if(temp == NULL)
    {
      printf("Value not found in Linked List\n");
      return head;
    }
  }
  if(temp == head)
  {
    head = deletebeg(head);
    return head;
  }
  else if(temp->next == NULL)
  {
    head = deleteend(head);
    return head;
  }
  previous->next = temp->next;
  free(temp);
  printf("After deleting %d :\n",data);
  display(head);
  return head;

}
