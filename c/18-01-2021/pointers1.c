#include <stdio.h>
int main()
{
	int a,b, *ap, *bp, *temp;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	ap = &a;
	bp = &b;
    printf("\nBefore swapping\nAdress of pointers pointing to\nap =%p, bp =%p\n",ap,bp);
    printf("Values of a =%d, b =%d\n",*ap,*bp);
	temp = ap;
	ap = bp;
	bp = temp;
	printf("\n\nAfter swapping\nap = %p, bp = %p\n",ap,bp);
    printf("Values of a =%d, b =%d",*ap,*bp);
	return 0;
}