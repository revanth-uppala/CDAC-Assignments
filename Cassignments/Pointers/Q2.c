#include<stdio.h>
int main()
{
	float table[2][3] = { { 1.1,1.2,1.3},{2.1,2.2,2.3}};
	printf("table = %p\n (table + 1)) = %p\n *(table + 1) = %p \n(*(table+1)+1) = %p \n *(*(table+1) +1) = %f",table,(table + 1),*(table + 1),(*(table+1)+1),*(*(table+1) +1));
	printf("\n*(*(table)+1) = %f \n *(*(table+1) = %f \n *(*(table) + 1)+1 = %f",*(*(table)+1),*(*(table+1)),*(*(table) + 1)+1 );
	return 0;
}


