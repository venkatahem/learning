#include <stdio.h>
int n = 3;
struct stu
{
    char name[20];
    int ID,total,sum,avg;
    int quiz[4],mid,end;
};
void input(struct stu *s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\nEnter name: ");
        fgets(s[i].name,20,stdin);
        printf("ID: ");
        scanf("%d",&s[i].ID);
        printf("Marks in 4 quizzes:\n");
        for(j=0;j<4;j++)
        {
            scanf("%d",&s[i].quiz[j]);
        }
        printf("Marks in MID-TERM and END-TERM:\n");
        scanf("%d",&s[i].mid);
        scanf("%d",&s[i].end);
        getchar();
        s[i].sum = 0;
        for(j=0;j<4;j++)
        {
            s[i].sum = s[i].sum + s[i].quiz[j];
        }
        s[i].sum = s[i].sum + s[i].mid + s[i].end;
        s[i].total = s[i].sum;
        s[i].avg = (s[i].total)/6;
    }
}
void display(struct stu *s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\n\nID: %d\n",s[i].ID);
        printf("Name: %s\n",s[i].name);
        printf("Marks in 4 quizzes:\n");
        for(j=0;j<4;j++)
        {
            printf("%d  ",s[i].quiz[j]);
        }
        printf("\nMID: %d and END: %d\n",s[i].mid,s[i].end);
        printf("Total: %d and Average: %d",s[i].total,s[i].avg);
    }
}
void average(struct stu *s)
{
    int x,i;
    do
    {
        printf("\nEnter a student ID to display his average marks\n");
        printf("'ZERO(0)' to exit\nEnter: ");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(s[i].ID == x)
            {
                printf("\nName: %s\n",s[i].name);
                printf("Average marks: %d\n",s[i].avg);
            }
        }
    } while (x != 0);
    
}
void handl(struct stu *s)
{
    int min,max,i,j;
    min = s[0].total;
    for(i=1;i<n;i++)
    {
        if(s[i].total < min)
        {
            min = s[i].total;
        }
    }
    max = s[0].total;
    for(i=1;i<n;i++)
    {
        if(s[i].total > min)
        {
            max = s[i].total;
        }
    }
    for(i=0;i<n;i++)
    {
        if(s[i].total == max)
        {
            printf("\nMAX mark is scored by\n");
            printf("Name: %s\n",s[i].name);
            printf("Total marks: %d\n",s[i].total);
        }
        if(s[i].total == min)
        {
            printf("\nMIN mark is scored by\n");
            printf("Name: %s\n",s[i].name);
            printf("Total marks: %d\n",s[i].total);
        }
    }
}
void search(struct stu *s)
{
    int x,i,j;
    do
    {
        printf("Enter a ID to serach the student\nZero(0) to exit\nEnter: ");
        scanf("%d",&x);
        for(i=0;i<n;i++)
        {
            if(s[i].ID == x)
            {
                printf("\n\nID: %d\n",s[i].ID);
                printf("Name: %s\n",s[i].name);
                printf("Marks in 4 quizzes:\n");
                for(j=0;j<4;j++)
                {
                    printf("%d  ",s[i].quiz[j]);
                }
                printf("\nMID: %d and END: %d",s[i].mid,s[i].end);
                printf("\nTotal: %d and Average: %d\n",s[i].total,s[i].avg);
            }
        }
    }while(x != 0);
}
int main()
{
    struct stu s[20];
    int x;
    do
    {
        printf("1 ==> Input\n2 ==> Display\n3 ==> Average of selected\n");
        printf("4 ==> Highest and Lowest score\n5 ==> Search by ID\n");
        printf("\n'ZERO(0)' to exit\n\nEnter:");
        scanf("%d",&x);
        getchar();
        switch (x)
        {
            case 1: printf("\nEnter the details of %d students:\n",n);
                    input(s);
                    break;
            case 2: printf("\nDisplaying the details of all students\n");
                    display(s);
                    break;
            case 3: average(s);
                    break;
            case 4: printf("\nDisplaying the highest and lowest\n");
                    handl(s);
                    break;
            case 5: search(s);
                    break;
        }
    } while (x != 0);
    return 0;
}