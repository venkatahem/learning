#include <stdio.h>
int vote(int);
int main()
{
    int age;
    int elig;
    printf("Enter your age: ");
    scanf("%d",&age);
    elig=vote(age);
    if(elig==0)
    {
        printf("Not a valid input for age");
    }
    else if(elig==1)
    {
        printf("You are not eligible to vote");
    }
    else if(elig==2)
    {
        printf("You are eligible to vote");
    }

    return 0;
}
int vote(int age)
{
    int a;
    if(age<0)
    {
        a=0;
    }
    else if(age>0&&age<18)
    {
        a=1;
    }
    else if(age>18)
    {
        a=2;
    }
    return a;
}