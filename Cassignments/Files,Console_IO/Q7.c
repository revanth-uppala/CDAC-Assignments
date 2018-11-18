/*Write a program to embed assembly language code in C program*/
#include<stdio.h>
/*int main()
{
	int a,b,sum=0;
	printf("enter values of a and b\n");
	scanf("%d %d",&a,&b);
	__asm__("\n\tSTR:\n\t.string ""message from assembler\n""mov %edx,10\n\tmov %eax,20\n\taddl %edx,%eax\n\tint $0x80\n\tret");
	
	//printf("sum of %d and %d is %d\n",a,b,sum);
	 	
	return 0;
	
}*/
int main()
{
	int a,b,sum = 0;
	printf("Enter value of a and b\n");
	scanf("%d%d",&a,&b);
	asm
	(
		"mov $a,%eax\n\tmov $b,%ebx\n\tadd %eax,%ebx\n\tmov %eax,$sum"
	);
	printf("%d+%d = %d",a,b,sum);
	return 0;
}
	
