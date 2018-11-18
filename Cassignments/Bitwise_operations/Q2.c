#include<stdio.h>
//#include "Baseconverter.h"
int* itob(int n,int s);
void display_bin(int a)
{

	int *p,i;
	
	p = itob(a,16);
	
	for(i = 0 ; i < 16 ; i ++)
	{
		if(*(p + i) == 1)
		{
			putchar('1');

		}
		else if(*(p+i) == 0)
		{
			putchar('0');
		}
	}
	printf("\n");


}
int main()
{	
	int a = 0xA2C3;
	int *p,i;
	char *q;	
	printf("%x in binary is\n0b",a);	
	display_bin(a);	
	printf("\n");
	printf(" Operations(result in hexadecimal) : \n~%x = %x\n %x ^ 0x3f06 = %x\n %x | 0x3f06 = %x\n %x | ~(0x3f06) = %x\n %x >> 3 = %x\n %x << 5 = %x\n %x ^ ~%x = %x\n %x | ~ %x = %x\n (%x & ~0x3f06) << 8 = %x\n (%x & ~0x3f06) >> 8 = %x\n",a,~a,a,a^0x3f06,a,a|0x3f06,a,a|(~0x3f06),a,a>>3,a,a<<5,a,a,a^(~a),a,a,a|(~a),a,(a & ~0x3f06)<<8,a,(a & ~0x3f06)>>8);
	
	printf("\n\n");	
	printf(" Operations(result in binary) : \n~%x = ",a);
	display_bin(~a);
	printf("\n%x ^ 0x3f06 =",a);
	display_bin(a^0x3f06);	
	 printf("\n%x | 0x3f06 =",a);
	display_bin((a | 0x3f06));	
	printf("\n%x | ~(0x3f06) =",a );
	display_bin((a | ~(0x3f06)));	
	printf("\n%x >> 3 = ",a);
	display_bin((a>>3));	
	printf("\n%x << 5 =",a);
	display_bin((a<<5));	
	 printf("\n%x ^ ~%x =",a,a);
	display_bin((a^(~a)));	
	 printf("\n%x | ~ %x =",a,a);
	display_bin((a | (~a)));
	printf("\n (%x & ~0x3f06) << 8 =",a);
	display_bin((a & (~0x3f06)) << 8);	
	printf("\n (%x & ~0x3f06) >> 8 =",a);
	display_bin((a & (~0x3f06))>>8);	
	
	



	return 0;
}
	
