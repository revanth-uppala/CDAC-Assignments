/*3. Define a structure declaration for each of the following situations. Assume a 16-bit integer word
a) Define three bit fields, called a, b and c, whose widths are 6-bits, 4-bits and 6-bits,
respectively
b) Declare a structure-type variable v having the composition defined in part (a) above. Assign
initial values 3, 5 and 7 respectively, to the three bit fields. Are the bit fields large enough to
accommodate these values?
c) What are the largest values that can be assigned to each of the bit fields defined in part (a)
above?
d) Define three bit fields, called a, b and c, whose widths are 8 bits, 6 bits and 5 bits,
respectively. How will these fields be stored within the computer’s memory?
e) Define three bit fields, called a, b and c, whose widths are 8 bits, 6 bits and 5-bits respectively.
Separate a and b with 2 vacant bits.*/

#include<stdio.h>
#include<stdlib.h>
#define PACKED __attribute__((packed));

#undef PACKED
struct s1
{
	unsigned a:6;
	unsigned b:4;
	unsigned c:6;
};
//PACKED
struct s2
{
	unsigned a:8;
	unsigned  :2;
	unsigned b:6;
	unsigned c:5;
};
//PACKED

int main()
{
	struct s1 v;
	struct s2 w;	
	v.a=3;
	v.b=5;
	v.c=7;
	printf("s1 size :%d\n",sizeof(v));
	printf("s2 size :%d\n",sizeof(w));
		
	/*printf("Largest value that %d can store is %d\n",i,pow(2,i) - 1);
	printf("Largest value that %d can store is %d\n",j,pow(2,j) - 1);
	printf("Largest value that %d can store is %d\n",k,pow(2,k) - 1);*/	
	return 0;
}

