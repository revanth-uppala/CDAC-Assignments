extern int i; 
int foo()
{
	static int j;
	j = i;	
	return j++;
}
	
