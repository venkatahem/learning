#include <stdio.h>

struct emp
{
    char name[20];
    char srt[20];
    char city[20];
    int id;
    int adr;
    int pay,nod;
};
int main()
{
    struct emp s;
    struct emp* sp;
    int salary;
    sp = &s;
    printf("Enter employee name: ");
    scanf("%s",sp->name);
    printf("Enter ID: ");
    scanf("%d",&sp->id);
    printf("Enter Door no: ");
    scanf("%d",&sp->adr);
    printf("Enter street name: ");
    scanf("%s",sp->srt);
    printf("Enter city name: ");
    scanf("%s",sp->city);
    printf("Enter pay scale(per day): ");
    scanf("%d",&sp->pay);
    printf("Enter no.of working days:");
    scanf("%d",&sp->nod);
    salary = (sp->pay)*(sp->nod);
    printf("\nDetails of the employee\n");
    printf("\nID: %d\n",sp->id);
    printf("Name: %s\n",sp->name);
    printf("Salary: %d",salary);

    return 0;
}  