#include <stdio.h>
int main()
{
    int date,month,year;
    printf("Enter date: ");
    scanf("%d",&date);
    printf("Enter month: ");
    scanf("%d",&month);
    printf("Enter year: ");
    scanf("%d",&year);
    if(date==1||date==01)
    {
        if(month==1||month==01)
        {
        printf("\n\nHappy New Year %d",year);
        }
    }
    else
    {
        printf("Todays date is %d-%d-%d",date,month,year);
    }
    

}