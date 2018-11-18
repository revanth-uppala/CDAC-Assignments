#include<stdio.h>
#include<stdlib.h>
float mul(float a,float b)
{
   return a*b;
}
float div1(float a,float b)
{ 
 
 return a/b;
}
long int fact(int a)
{
if(a==0 || a==1)
{
return 1;
}
else
{
return a*fact(a-1);
}
}
float square(float a)
{
return a*a;
}
int main()
{
	int ch,c;
	float c1;
	float result,a,b;
	while(1)
       {
         printf("\nenter ur choice\n1.multiply\n2.divide\n3.factorial\n4.square\n5.quit\n");
         scanf("%d",&ch);
        switch(ch)
       {
	case 1: printf("enter two numbers\n");
	scanf("%f%f",&a,&b);
	result=mul(a,b);
	printf("result is %f\n",result);	
	break;
	case 2: printf("enter two numbers\n");
	scanf("%f%f",&a,&b);
	if(b != 0)
	{
        result=div1(a,b);
	printf("result is %f\n",result);	
	}
	else	
	{	
	printf("divide by zero error");
	}	
	break;
	case 3: printf("enter one number\n");
	scanf("%d",&c);
        result=fact(c);
	printf("result is %f\n",result);	
	break;
	case 4: printf("enter one number\n");
	scanf("%f",&c1);
        result=square(c1);
	printf("result is %f\n",result);
	break;
	case 5: exit(0);
	default: printf("invalid choice\n");
	}
	
        }

return 0;
}


        
