#include<stdio.h>
char* itoh(int n,int s)
{
	char val[s/4];
	int i;
	char*p;
	for( i = (s/4)-1; i >= 0   ; i--)
	{
		val[i] = n % 16;
		n = n / 16;
	}
	for(i = 0; i < s/4; i ++ )
	{
		switch(val[i])
		{
			case 10: val[i]='A';
				 break;
			case 11: val[i]='B';
			         break;
			case 12: val[i]='C';
				 break;
			case 13: val[i]='D';
				 break;
			case 14: val[i]='E';
				 break;
			case 15: val[i]='F';
				 break;
		}
		
	}
		p=val;
		return p;
		
}
