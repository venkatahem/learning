#include <stdio.h>
int main()
{
	int a,b, *ap, *bp, temp;
	printf("Enter a:  ");
	scanf("%d",&a);
	printf("Enter b:  ");
	scanf("%d",&b);
	ap = &a;
	bp = &b;
	temp = *ap;
	*ap = *bp;
	*bp = temp;
	printf("After swapping, \n a = %d \n b = %d ",*ap,*bp);
	return 0;
}