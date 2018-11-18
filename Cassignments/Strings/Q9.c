#include<stdio.h>
#include<string.h>
void expand(char s[],char t[])
{
	int i,j = 0;
	for(i = 0; s[i] != '\0' ; i ++)
	{
		switch(s[i])
		{
			case '\t': 
				t[j] = '\\';
				t[j + 1] = 't';
				j++;
				//t[j + 2] = 't';
				
				break;
			case '\n':
				t[j] = '\\';
				t[j + 1] = 'n';
				//t[j + 2] = 110;
				j++;
				break;
				
			default : t[j] = s[i]; 
				
		}
		j++;
			
	}
	t[j + 1] = '\0';
	printf("Original string is :\n");
	puts(s);
	printf("\n");
	printf("Expanded string is :\n");
	printf("%s",t);

}
int main()
{
	char t[150];
	char s[50] = "This is \t string1\nThis is \t second line";
	expand(s,t);	
	return 0;
}	
