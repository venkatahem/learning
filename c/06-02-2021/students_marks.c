#include <stdio.h>

struct student
{
    char name[20];
    int id;
    int sub[3];
    int total;
    float avg;
};
void print(struct student *s,int n);
void print1(struct student *s,int n);
int main()
{
    struct student s[10];
    int n,x,i,j;
    printf("No.of students: ");
    scanf("%d",&n);
    printf("\nEnter students details and marks one by one");
    for(i=0;i<n;i++)
    {
        printf("\nEnter student name: ");
        scanf("%s",s[i].name);
        printf("Enter ID: ");
        scanf("%d",&s[i].id);
        printf("Enter the marks in 3 subjects:\n");
        for(j=0;j<3;j++)
        {
            scanf("%d",&s[i].sub[j]);
        }
    }
    do
    {
        printf("\nEnter '1' to print the details of every student\nor\n'2' for a individual student\n");
        printf("or\n'0' to exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: print(s,n);
                    break;
            case 2: print1(s,n);
                    break;        
        }
    } while (x!=0);
    
    return 0;
}
void print(struct student *s,int n)
{
    int i,j;
    int total[10]={0,0,0,0,0,0,0,0,0,0};
    float average[10];
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            total[i] = s[i].sub[j] + total[i];
        }
        average[i] = total[i]/3;
    }
    for(i=0;i<n;i++)
    {
        printf("\nStudent ID: %d\n",s[i].id);
        printf("Name: %s\n",s[i].name);
        printf("Average marks = %f\n",average[i]);
        printf("Total marks = %d\n",total[i]);
    }
}
void print1(struct student *s,int n)
{
    int total=0,i,j,y,k;
    float average;
    printf("\nEnter the ID of the student: ");
    scanf("%d",&y);
    for(i=0;i<n;i++)
    {
        if(s[i].id == y)
        {
            j=i;
        }
    }
    for(i=0;i<3;i++)
        {
            total = s[j].sub[i] + total;
        }
        average = total/3;
    printf("\nStudent ID: %d\n",s[j].id);
    printf("Name: %s\n",s[j].name);
    printf("Average marks = %f\n",average);
    printf("Total marks = %d\n",total);
}