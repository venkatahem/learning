#include <stdio.h>
struct employee
{
char name[20];
int id;
struct DOB { int day:6;int month:5;int year:20;} d;
struct salary { int NOD:6;int scale;int month_salary;} s;
struct employee *p2;
};
void compute_salary(struct employee e1,struct employee e2,struct employee *p1);
void check_salary(struct employee e1,struct employee e2,struct employee *p1);
int main()
{
struct employee e1,e2;
struct employee *p1;
int n=0;
p1=&e1;
e1.p2=&e2;
printf("\nEnter employee name: ");
scanf("%s",p1->name);
printf("\nEnter employee ID: ");
scanf("%d",&p1->id);
printf("\nEnter employee's date of birth(DD-MM-YYYY):\n");
scanf("%d",&n);
p1->d.day = n;
scanf("%d",&n);
p1->d.month = n;
scanf("%d",&n);
p1->d.year = n;
printf("\nEnter pay scale: ");
scanf("%d",&p1->s.scale);
printf("\nEnter no.of days: ");
scanf("%d",&n);
p1->s.NOD = n;

printf("\nEnter employee name: ");
scanf("%s",e1.p2->name);
printf("\nEnter employee ID: ");
scanf("%d",&e1.p2->id);
printf("\nEnter employee's date of birth(DD-MM-YYYY):\n");
scanf("%d",&n);
e1.p2->d.day = n;
scanf("%d",&n);
e1.p2->d.month = n;
scanf("%d",&n);
e1.p2->d.year = n;
printf("\nEnter pay scale: ");
scanf("%d",&e1.p2->s.scale);
printf("\nEnter no.of days: ");
scanf("%d",&n);
e1.p2->s.NOD = n;

compute_salary(e1,e2,p1);
check_salary(e1,e2,p1);

return 0;
}
void compute_salary(struct employee e1,struct employee e2,struct employee *p1)
{
p1->s.month_salary = p1->s.NOD*p1->s.scale;
e1.p2->s.month_salary = (e1.p2->s.NOD)*(e1.p2->s.scale);
}
void check_salary(struct employee e1,struct employee e2,struct employee *p1)
{
int i=0,n;
do
{
printf("\nEnter ID: ");
scanf("%d",&n);
if(n == p1->id)
{
printf("\nName: %s",p1->name);
printf("\nDOB: %d-%d-%d",p1->d.day,p1->d.month,p1->d.year);
printf("\nNOD: %d and Scale: %d",p1->s.NOD,p1->s.scale);
printf("\nSalary: %d\n",p1->s.month_salary);
}
else if(n == e2.id)
{
printf("\nName: %s",e1.p2->name);
printf("\nDOB: %d-%d-%d",e1.p2->d.day,e1.p2->d.month,e1.p2->d.year);
printf("\nNOD: %d and Scale: %d",e1.p2->s.NOD,e1.p2->s.scale);
printf("\nSalary: %d\n",e1.p2->s.month_salary);
}
i++;
}while(i<2);
}