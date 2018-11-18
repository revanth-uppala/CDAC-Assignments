int fact(int);
int fact(int n)
{
	int f=1;	
	if(n == 1 || n == 0)
	{
		return 1;
	}
	else
		return n*fact(n-1);
		
}
