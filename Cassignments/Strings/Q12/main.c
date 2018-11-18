/*12. Implement string library functions. strrev, strcpy, strcat, strcmp with same return values and all
error handling features using pointers.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "string1.h"
char* strcat1(char* str1,char* str2);
char* strcpy1(char* str1,char * str2);
void strrev1(char *str);
int main()
{
	char str1[20],str2[20],temp1[20],temp2[20];
	char *p,*q;
	int c,i;
	
	while(1)
	{
		printf("Enter choice\n1:strrev\n2:strcpy\n3:strcat\n4.strcmp\n5.Quit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nEnter first string\n");
				scanf("%s",str1);
				printf("Enter second string\n");
				scanf("%s",str2);				
				printf("String 1 is %s\n",str1);		
				printf("String 2 is %s\n",str2);				
				strrev1(str1);
				strrev1(str2);
				printf("Reverse of first string is : %s\nReverse of second string is %s\n ",str1,str2);
				break;
			case 2:
				printf("\nEnter first string\n");
				scanf("%s",str1);
				printf("Enter second string\n");
				scanf("%s",str2);				
				printf("Before copying\nString 1: %s\nString 2: %s\n",str1,str2);
				p = strcpy1(str1,str2);
				printf("After copying\nString 1: %s\nString 2: %s\n",p,str2);				
				break;
			case 3:
				printf("\nEnter first string\n");
				scanf("%s",str1);
				printf("Enter second string\n");
				scanf("%s",str2);				
				printf("\nBefore concatenation : \nString 1: %s\nString 2: %s\n",str1,str2);
				p = strcat1(str1,str2);
				printf("After concatenation\nString 1: %s\nString 2: %s\n",p,str2);
				break;
			case 4:

				printf("\nEnter first string\n");
				scanf("%s",str1);
				printf("Enter second string\n");
				scanf("%s",str2);				
				i =  strcmp1(str1,str2);				
				if(i == 0)
				{
					printf("%s  and %s are same \n",str1,str2);
				}
				else if(i > 0)
				{
					printf("%s > %s\n",str1,str2);
				}
				else
				{
					printf("%s < %s\n",str1,str2);
				}
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid input\n");
		}
	}
					
	 
	return 0;
} 
	
	
	
	
