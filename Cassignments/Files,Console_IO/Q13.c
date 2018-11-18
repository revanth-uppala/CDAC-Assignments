#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int i=0,j=0,k = 0,l= 0,count = 0;
	int counts[25],lengths[26];
	printf("Enter any sentence\n");
	scanf("%[^\n]s",str);
	for(i = 0 ; i < 26 ; i ++)
	{
		lengths[i] = 0;
	}
	i = 0;	
		
	while(str[l] != '\0')	
	{	
		while((str[i] != '\0') && (str[i] != ' '))
		{
			count++;
			i++;
		}
		counts[j] = count;
		j ++;		
		count = 0;
		l = i + 1;		
		i++;		
		 
	}
	for(i  = j ; i <= 25 ; i ++)
	{
		counts[i] = 0;
	}
		
		
	for(i = 0; i < 25 ; i ++)
	{
		for(k = 1 ; k <= 25 ; k ++)
		{
			if(counts[i] == k)
			{
				lengths[k] ++ ;
			}
		}
	}
	for(i = k ; i <= 25 ; i ++)
	{
		lengths[i] = 0;
	}
	for( k = 1 ; k <=25 ; k ++)
	{
		printf("length %d : %d occurences\n",k,lengths[k]);
	}
	return 0;
}
		
		
		
	
