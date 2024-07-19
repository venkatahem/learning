#include <stdio.h>
int primecheck(int);
int main()
{
	int num,res=0;
	printf("\nENTER A NUMBER: ");
	scanf("%d",&num);
	res=primecheck(num);
	if(res==0)
		printf("\n%d IS A PRIME NUMBER",num);
	else
		printf("\n%d IS NOT A PRIME NUMBER",num);
}
int primecheck(int n)
{
	int i;
	for(i=2;i<=n/2;i++)
	{
		if(n%i!=0)
			continue;
		else
			return 1;
	}
	return 0;
}