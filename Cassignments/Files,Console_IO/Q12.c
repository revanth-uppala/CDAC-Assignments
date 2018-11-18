#include<stdio.h>
int main()
{
 	char str[30];
	int ch;
	int x=0,a=0,e=0,i=0,o=0,u=0,rest=0,total=0;
	float per;
	printf("enter a string\n");
	scanf("%[^\n]s",str);
	/*while( ch = getchar() != '\n'   )
	{
		str[x++] = ch;

		total++;
	}*/
	
	//str[x] = '\0';
	printf("entered string is %s\n",str);
	for(x=0; str[x] != '\0' ;x++)
	{
	switch(str[x])
		{
			case 'a' :
			case 'A': a++;
				   break; 
			case 'e' :
			case 'E': e++;
				   break; 
			case 'i' :
			case 'I': i++;
				   break; 
			case 'o':
			case 'O' : o++;
				   break; 
			case  'u':
			case  'U': u++;
				   break;
			default : rest++;
		}

	} 
	total =x;
	printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\nrest:%d\ntotal:%d\n",a,e,i,o,u,rest,total);
	per=((float)a/total)*100;
	printf("percentage of 'a' in string is %f\n",per);

	per=((float)e/total)*100;
	printf("percentage of 'e' in string is %f\n",per);
	
	per=((float)i/total)*100;
	printf("percentage of 'i' in string is %f\n",per);
	
	per=((float)o/total)*100;	
	printf("percentage of 'o' in string is %f\n",per);
	
	per=((float)u/total)*100;
	printf("percentage of 'u' in string is %f\n",per);
	
	per=((float)rest/total)*100;
	printf("percentage of 'rest' in string is %f\n",per);
	
	return 0;
}














