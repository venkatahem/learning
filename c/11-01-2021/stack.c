#include <stdio.h>
int main()
{
    int stack[100];
    int n,pop,i=0,a;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element to push: ");
        scanf("%d",&stack[i]);
    }
    printf("Enter 1 to dispaly stack\nEnter 2 to pop element\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1: printf("Elements in stack\n");
                for(i=n-1;i>=0;i--)
                {
                    printf("%d\n",stack[i]);
                }
                break;
        case 2:         printf("Enter the number of elements to pop: ");
                        scanf("%d",&pop);
                        printf("These are the elements poped out\n");
                        for(i=n-1;i>=n-pop;i--)
                        {
                            printf("%d\n",stack[i]);
                        }
                        printf("Elements in stack\n");
                        for(i=n-pop-1;i>=0;i--)
                        {
                            printf("%d\n",stack[i]);
                        }
                        break;
        default : printf("Not valid");
                  break;                
    }
    
    
    return 0;
}