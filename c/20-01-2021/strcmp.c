#include <stdio.h>

int main()
{
    char str1[20];
    char str2[20];
    const char *p1;
    const char *p2;
    int i;
    printf("Enter the first string: ");
    scanf("%s",str1);
    p1=str1;
    printf("Enter the second string: ");
    scanf("%s",str2);
    p2=str2;
    for(i = 0; *(p1+i) == *(p2+i) && *(p1+i) == '\0'; i++);
		   
  	if(*(p1+i) < *(p2+i))
   	{
   		printf("\n str1 is Less than str2");
	}
	else if(*(p1+i) > *(p2+i))
   	{
   		printf("\n str2 is Less than str1");
	}
	else
   	{
   		printf("\n str1 is Equal to str2");
	}
  	
  	return 0;
}