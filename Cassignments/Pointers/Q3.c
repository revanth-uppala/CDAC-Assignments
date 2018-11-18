#include<stdio.h>
int main()
{
	char *color[6] = {"red","green","blue","white","black","yellow"};
	printf("color = %p \n (color + 2) = %p \n *color = %p \n",color,color+2,*color);
	printf("**(color +2) = %c \n *(color + 5) = %p\n color[5] = %p",**(color + 2),*(color + 5),color[5]);	
	return 0;
}
