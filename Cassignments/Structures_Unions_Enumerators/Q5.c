#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,n,s;
	enum flag{FALSE,TRUE}e1,e2;	
	e1 = FALSE;
	e2 = TRUE;	
	printf("Enter number of elements\n");
	scanf("%d",&n);
	int a[n];
	printf("Enter the elements\n");
	for(int i = 0; i < n ; i ++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter search term\n");
	scanf("%d",&s);
	for(i = 0; i < n; i ++)
	{
		if(a[i] == s)
		{
			printf("%d\n",e2);
			exit(1);		
		}
	}
	printf("%d\n",e1);
	return 0;
}
