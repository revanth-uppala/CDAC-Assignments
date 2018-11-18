struct stack
{
	int capacity;
	int *array;
	int top;
};
typedef struct stack stack;
void display_stack(stack *S);
int pop(stack *S);
void push(stack *S,int value);
int tos(stack *S);
