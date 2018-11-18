/*Given as input an integer number of seconds, print as output the equivalent time in hours,
minutes and seconds. Recommended output format is something like 7322 seconds is
equivalent to 2 hours 2 minutes 2 seconds.*/
#include<stdio.h>
int main()
{
	int secs,hrs,mins,temp;
	printf("enter no of seconds\n");
	scanf("%d",&secs);
	hrs=0,mins = 0;
	temp = secs;
	mins = secs / 60;
	hrs = mins / 60;
	if(mins >= 60)
	{
		mins = mins % 60;
	}
	secs = secs % 60;
	printf("%d seconds is %d hours %d minutes %d seconds\n",temp,hrs,mins,secs);
	return 0;
}

	
	
