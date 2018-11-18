/*Develop a C program which accepts character type data item from user. In case if user typed
‘A’ or ‘a’, it should display A for Apple
‘B’ or ‘b’, it should display B for Bat
‘D’ or ‘d’, it should display D for Dog
‘F’ or ‘f’, it should display F for Fan
Instead of the above 4 characters, if user types any other character, it should display “Character
is not in the range”. Implement this using if-else statement and switch statement.*/
#include<stdio.h>
int main()
{
	char ch;
	printf("Enter a character\n");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'a':
		case 'A':
			printf("A for Apple\n");
		break;
		case 'b':
		case 'B':
			printf("B for Bat\n");
		break;
		case 'd':
		case 'D':
			printf("D for Dog\n");
		break;
		case 'f':
		case 'F':
			printf("F for Fan\n");
		break;
		default:
			printf("Character is not in the range\n");
	}
	return 0;
}	
