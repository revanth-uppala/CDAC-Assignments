#include<stdio.h>
#include<string.h>
int main()
{
char name[20];
int i=0,count=0;
printf("enter a name\n");
gets(name);
printf("entered name is %s\n",name);
printf("length of name is %d\n",strlen(name));
while(name[i] != '\0')
{
count++;
i++;
}
printf("size of array that stores %s is %d\n",name,count);
return 0;
}
