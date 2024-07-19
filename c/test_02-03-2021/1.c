#include <stdio.h>
#include <stdlib.h>
int n;
struct stu
{
    char name[20];
    int ID,total,sum,rank;
    int quiz[4];
};

void input(struct stu *s)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("\n*** STUDENT %d ***\n",i+1);
        printf("\nEnter name: ");
        fgets(s[i].name,20,stdin);
        printf("ID: ");
        scanf("%d",&s[i].ID);
        printf("Marks in 4 quizzes:\n");
        for(j=0;j<4;j++)
        {
            scanf("%d",&s[i].quiz[j]);
        }
        getchar();
        s[i].sum = 0;
        for(j=0;j<4;j++)
        {
            s[i].sum = s[i].sum + s[i].quiz[j];
        }
        s[i].total = s[i].sum;
    }
}

void ranks(struct stu *s)
{
    int i,j,k;
    int a[20]={0};
    for(i=0;i<n;i++)
    {
        a[i] = s[i].total;
    }
    for(j=0;j<n-1;j++)
    {
        for(k=j+1;k<n;k++)
        {
            if(a[j] > a[k])
            {
                i = a[j];
                a[j] = a[k];
                a[k] = i;
            }
        }
    }
    for(i= n-1;i >= 0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(a[i] == s[j].total)
            {
                s[j].rank = n-i;
            }
        }
    }
}

void store(struct stu *s)
{
    FILE *f;
    int i,j;
    char a[20] = "Rank wise marks";
    f = fopen("Stu marks.txt","w");
    fprintf(f,"%s\n\n",a);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[j].rank == i+1)
            {
                fprintf(f,"Name: %s",s[j].name);
                fprintf(f,"ID: %d",s[j].ID);
                putc('\n',f);
                fprintf(f,"Marks in tests: %d, %d, %d, %d.",s[j].quiz[0],s[j].quiz[1],s[j].quiz[2],s[j].quiz[3]);
                putc('\n',f);
                fprintf(f,"Total: %d",s[j].total);
                putc('\n',f);
                putc('\n',f);
            }
        }
    }
}

int main()
{
    struct stu s[5];
     printf("\nEnter the no.of students: ");
     scanf("%d",&n);
     getchar();
     printf("\nEnter the details of %d students:\n",n);
     input(s);

     ranks(s);

     store(s);

     printf("\nSuccessfully completed\n");

     return 0;
}