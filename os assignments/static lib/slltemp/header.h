typedef struct node
{
	int info;
	struct node *next;
}node;

void display(node* last);
node *insert_beg(node *last,int data);
node *insert_end(node *last,int data);
