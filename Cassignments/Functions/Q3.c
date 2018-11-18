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

