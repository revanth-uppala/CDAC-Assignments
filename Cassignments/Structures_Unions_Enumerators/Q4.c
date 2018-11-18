#include<stdio.h>
#include<stdlib.h>
union result
{
	float p;
	float cgpa;
};

struct srecord
{
	char name[10];
	int roll;
	int marks1,marks2;
	union result u;	
};

typedef struct srecord student;
typedef union result result;

void inputDESD(student *temp,int i)
{
	int c1;	
	printf("\n\tEnter details of student %d:\n",i);
	//temp.name =(char*)malloc(sizeof(char) * 20);
	printf("Name : ");	
	scanf("%s",temp->name);
	printf("Enter roll :");
	scanf("%d",&temp->roll);
	printf("Enter C Programming marks:");
	scanf("%d",&temp->marks1);
	printf("Enter IoT Marks :");
	scanf("%d",&temp->marks2);
}
void inputDAC(student *temp,int i)
{
	int c1;	
	printf("\n\tEnter details of student %d:\n",i);
	//temp.name =(char*)malloc(sizeof(char) * 20);
	printf("Name : ");	
	scanf("%s",temp->name);
	printf("Enter roll :");
	scanf("%d",&temp->roll);
	printf("Enter Software Design marks :");
	scanf("%d",&temp->marks1);
	printf("Enter Discrete Mathematics marks :");
	scanf("%d",&temp->marks2);
	
}
void inputDSSD(student *temp,int i)
{
	int c1;	
	printf("\n\tEnter details of student %d:\n",i);
	//temp.name =(char*)malloc(sizeof(char) * 20);
	printf("Name : ");	
	scanf("%s",temp->name);
	printf("Enter roll :");
	scanf("%d",&temp->roll);
	printf("Enter Computer Networking marks :");
	scanf("%d",&temp->marks1);
	printf("Enter Ethical Hacking marks :");
	scanf("%d",&temp->marks2);
}

void display(student *temp,int i,int j)
{
	if(j == 1)
	{
		temp->u.p = ((temp->marks1 + temp->marks2) / 2);
		printf("%d.Name : %s\nRoll: %d\nMarks1 : %d\nMarks 2: %d\nPercentage : %f \n",i,temp->name,temp->roll,temp->marks1,temp->marks2,temp->u.p);			
	}
	else if(j == 2)
	{
		temp->u.cgpa = ((temp->marks1 + temp->marks2) / 20);
		printf("%d.Name : %s\nRoll: %d\nMarks1 : %d\nMarks2 : %d\nCGPA : %f\n",i,temp->name,temp->roll,temp->marks1,temp->marks2,temp->u.cgpa);			
	}	
}
		
	
int main()
{
	int n,c,i,c1,j;
	
	printf("Select Branch\n1:DESD\n2:DAC\n3:DSSD\n");
	scanf("%d",&c);
	printf("Enter choice:\n 1.Percentage\n2.CGPA\n");
	scanf("%d",&c1);
	switch(c1)
	{
		case 1:
			j = c1;
			break;
		case 2:
			j = c1;
			break;
		default:
			printf("Invalid Input\n");
			//goto l1;
	}
	printf("\n");
	if(c == 1)
	{
			printf("Enter number of DESD students :\n");
			scanf("%d",&n);
			student s[n];
			for(i = 0; i < n ; i ++)
			{
				inputDESD(&s[i],i+1);
			}
			printf("\t\tResults of DESD students are\n");		
			for(i = 0; i < n ; i ++)
			{
				display(&s[i],i +1,j);
			}
			
	}
	else if( c == 2)
	{			
			printf("Enter number of DAC students :\n");
			scanf("%d",&n);
			student s[n];
			for(i = 0; i < n ; i ++)
			{
				inputDAC(&s[i],i+1);
			}
			printf("\t\tResults of DAC students are :\n");
			for(i = 0; i < n ; i ++)
			{
				display(&s[i],i +1,j);
			}
			
	}
	else if(c == 3)
	{			
			printf("Enter number of DSSD students\n");
			scanf("%d",&n);
			student s[n];
			for(i = 0; i < n ; i ++)
			{
				inputDSSD(&s[i],i+1);
			}
			printf("\t\tResults of DSSD students are :\n");
			for(i = 0; i < n ; i ++)
			{
				display(&s[i],i +1,j);
			}
	}
	else
	printf("Invalid input\n");
			//goto l2;
	
	return 0;
}		
			
				
				
	
				
	
		

	
