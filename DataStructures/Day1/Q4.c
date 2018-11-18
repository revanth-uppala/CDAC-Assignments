/*Write a program to swap two pointers.
◦
◦
Write a function 'swap' which takes two arguments as integer
pointers and doesn't return any thing. Swap the contents of these
two pointers in 'swap' function.
Print the contents of two pointers in main before & after call of
'swap' function*/

#include<stdio.h>
void swap(int* p,int* q)
{
int temp;
temp=*p;
*p=*q;
*q=temp;

}
int main()
{
int a,b;
printf("enter values of a and b\n");
scanf("%d%d",&a,&b);
printf("before swapping a=%d\n,b=%d\n",a,b);
swap(&a,&b);
printf("after swapping a=%d\n,b=%d\n",a,b);
return 0;
}

