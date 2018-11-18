
int* itob(int n,int s)
{
	int val[s];
	int i;
	int *p;
	for( i = s-1; i >= 0   ; i--)
	{
		val[i] = n%2;
		n = n/2;
	}
	p = val;
	return p;
}
