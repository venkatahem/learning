#include <stdio.h>
int main()
{
    int queue[100];
    int n,a,delete,i=0;
    printf("Enter the size os queue: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the element to insert: ");
        scanf("%d",&queue[i]);
    }
    printf("\nEnter 1 to display the queue\nEnter 2 to delete elements\n");
    scanf("%d",&a);
    switch(a)
    {
        case 1: printf("Elements in queue\n");
                for(i=0;i<n;i++)
                {
                    printf("%d\n",queue[i]);
                }
                break;
        case 2: printf("Enter the no.of elements to delete: ");
                scanf("%d",&delete);
                printf("Deleted elements\n");
                for(i=0;i<delete;i++)
                {
                    printf("%d\n",queue[i]);
                }       
                break;
        default : printf("Not valid\n");
    }

}