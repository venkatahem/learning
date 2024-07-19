#include <stdio.h>

void main()
{
    int nums[] = {0,1,2,3,4,5,6,7,8,9};
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J'};
    char encrypt[20];
    int x,y,i,j=0,len=10;
    printf("Enter a number: ");
    scanf("%d",&x);
    if(x == 0)
    {
        printf("\nA");
    }
    else
    {
        while(x != 0)
        {
            y = x%10;
            for(i=0;i<len;i++)
            {
                if(y == nums[i])
                {
                    encrypt[j] = alpha[i];
                    j++;
                }
            } 
            x = x/10;
        }
        printf("\n%s",encrypt);
    }
}