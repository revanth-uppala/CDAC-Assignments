#include<stdio.h>
struct s1
    {
	int a;
	char b;
    };
union u1
{
	int a;
 	char b;
}; 
int main()
{
	struct s1 st;
	union u1 un;
	printf("size of structure in bytes is %ld\n",sizeof(st));
	printf("size of union in bytes is %ld\n",sizeof(un));
	return 0;
}

