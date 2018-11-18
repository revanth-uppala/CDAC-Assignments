/*Read two integers, representing a rate of pay (pence per hour) and a number of hours. Print out
the total pay, with hours up to 40 being paid at basic rate, from 40 to 60 at rate-and-a-half,
above 60 at double-rate. Print the pay as rupees to two decimal places.
Terminate the loop when a zero rate is encountered.
At the end of the loop, printout the total pay.
The code for computing the pay from the rate and hours is to be written as a function.
The recommended output format is something like:
Pay at 200 pence/hr for 38 hours is 76.00 rupees
Pay at 220 pence/hr for 48 hours is 114.40 rupees
Pay at 240 pence/hr for 68 hours is 206.40 rupees
Pay at 260 pence/hr for 48 hours is 135.20 rupees
Pay at 280 pence/hr for 68 hours is 240.80 rupees
Pay at 300 pence/hr for 48 hours is 156.00 rupees
Total pay is 928.80 rupees*/
#include<stdio.h>
float calc(float rate,int hours)
{
  float pay;
  
  if(hours <=40)
  {
   pay=rate*hours;
   
  }
  else if(hours>40 && hours<=60)
  {
  rate=rate*1.5;
  pay=rate*hours;
  
  }
  else
 {
   rate*=2;
   pay=rate*hours;
   
 }
	return pay/100;
}
int main()
{
    int w,i,hours;
	float rate,pay,sum = 0;
    printf("enter the no of workers \n");
    scanf("%d",&w);
	for(i = 1;i<=w;i++)
	{
		printf("enter rate in pence/hr and no of hours of worker %d\n",i);
  		scanf("%f%d",&rate,&hours);
		pay = calc(rate,hours);
		sum += pay;		
		printf("Worker %d : Pay at %f pence/hr for %d hours is %.2f rupees\n",i,rate,hours,pay);
	}
	printf("Total pay is %.2f rupees",sum);
	return 0;
}
		
		
    
