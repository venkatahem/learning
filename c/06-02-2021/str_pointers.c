#include <stdio.h>

struct str
{
    char name[10];
    int roll;
    int class;
    int adm;
};
int main()
{
    struct str s;
    struct str* sp;
    sp = &s;
    printf("Enter student name: ");
    scanf("%s",sp->name);
    printf("Enter admission no: ");
    scanf("%d",&sp->adm);
    printf("Enter class: ");
    scanf("%d",&sp->class);
    printf("Enter roll no: ");
    scanf("%d",&sp->roll);
    printf("\nDetails of the student\n");
    printf("Admission no: %d\n",sp->adm);
    printf("Name: %s\n",sp->name);
    printf("Class: %d\n",sp->class);
    printf("Roll no: %d\n",sp->roll);

    return 0;
}