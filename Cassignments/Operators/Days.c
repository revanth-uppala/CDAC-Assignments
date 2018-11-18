#include<stdio.h>
int isleapyear(int);
int daysfrom1stJan(int,int,int);
int daysinyear(int);
int isleapyear(int year)
{
	int i,j,temp;
	temp = year;	
	i = year %10;
	temp = temp/10;
	j = temp %10;
	if(i == 0 && j == 0)
	{	
		if(year%400 == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(year%4 == 0)
		{
			return 1;
		}
		else
			return 0;
	}
}			
int daysfrom1stJan(int year,int month,int day)
{
	int daysfromJan1;	
	int daysofmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(isleapyear(year) == 1)
	{
		daysofmonth[1] = 29;
	}
	if(month == 0)
	{
		daysfromJan1 = day;
	}
	else
	{
		int daysx = 0,i = 0;
		while(i < month-1)
		{
			daysx += daysofmonth[i];
			i++;
		}
		daysfromJan1 = day + daysx;
	}
	return daysfromJan1;
}
int daysinyear(int year)
{
	if(isleapyear(year) == 1)
		return 366;
	else
		return 365;
}
		
int main()
{
	int daysofmonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int year1,month1,day1,year2,month2,day2,leap1,leap2,diff,startdays,stopdays,days_yeardiff,yeardiff;
	printf("Enter year1,month1,day1\n");
	scanf("%d%d%d",&year1,&month1,&day1);
	printf("Enter year2,month2,day2\n");
	scanf("%d%d%d",&year2,&month2,&day2);
	leap1 = isleapyear(year1);
	leap2 = isleapyear(year2);
	if(year1 == year2)
	{
		if(month1 == month2)
		{
			diff = day2 - day1;
		}
		diff = daysfrom1stJan(year2,month2,day2) - daysfrom1stJan(year1,month1,day1);
	}
	else
	{
		if(leap1)
		{
			startdays = 366 - daysfrom1stJan(year1,month1,day1);
		}
		else
		{
			startdays = 365 - daysfrom1stJan(year1,month1,day1);
		}
		stopdays = daysfrom1stJan(year2,month2,day2);
		yeardiff = year2 - year1;
		days_yeardiff = 0;
		while(year1 + 1 < year2)
		{
			days_yeardiff += daysinyear(year1+1);
			year1++;
		}
		diff = startdays + stopdays + days_yeardiff;
	}
	printf("Number of days between the two dates is %d",diff);
	return 0;

} 		
		
	
