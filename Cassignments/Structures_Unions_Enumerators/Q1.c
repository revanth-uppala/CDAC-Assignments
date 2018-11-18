#include<stdio.h>
struct time
{
	int hours;
	int mins;
	int secs;
};
int main()
{
	struct time t1;
        printf("enter hour\n");
        scanf("%d",&t1.hours);
	printf("enter minutes\n");
        scanf("%d",&t1.mins);
	printf("enter seconds\n");
        scanf("%d",&t1.secs);
        printf("The time is %d hrs: %d mins: %d secs\n ",t1.hours,t1.mins,t1.secs);
        return 0;
}
