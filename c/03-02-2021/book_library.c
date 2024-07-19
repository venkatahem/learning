#include <stdio.h>

struct date
{
    int d,m,y;
};
struct library
{
    char name[30];
    char author[20];
    int id;
    int cost;
    struct date s1;
};
int main()
{
    struct library s2[30];
    int n,i;
    printf("Enter the no.of books: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\nBook %d\n",i+1);
        printf("Enter the name of the book\n");
        scanf("%s",s2[i].name);
        printf("Enter author name\n");
        scanf("%s",s2[i].author);
        printf("Enter the cost: ");
        scanf("%d",&s2[i].cost);
        printf("Enter the date of purchase in DD-MM-YYYY format\n");
        scanf("%d%d%d",&s2[i].s1.d,&s2[i].s1.m,&s2[i].s1.y);
        s2[i].id = i+1;
    }
    for(i=0;i<n;i++)
    {
        printf("\nBook ID: %d\n",s2[i].id);
        printf("Name: %s\n",s2[i].name);
        printf("Autor: %s\n",s2[i].author);
        printf("Price: %d\n",s2[i].cost);
        printf("Date of purchase: %d-%d-%d\n",s2[i].s1.d,s2[i].s1.m,s2[i].s1.y);
    }
    return 0;
}