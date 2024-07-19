#include <stdio.h>

struct student
{
    char name[20];
    int id,total,avg;
};
union stu
{
    char name[20];
    int id ,total,avg;
};
int main()
{
    struct student s;
    union stu t;
    printf("Enter student name: ");
    scanf("%s",s.name);
    scanf("%s",t.name);
    printf("Enter student ID: ");
    scanf("%d%d",&s.id,&t.id);
    printf("Enter student average marks: ");
    scanf("%d%d",&s.avg,&t.avg);
    printf("Enter student total marks: ");
    scanf("%d%d",&s.total,&t.total);
    printf("\nIn structure\n");
    printf("Name: %s\n",s.name);
    printf("ID: %d\n",s.id);
    printf("Average: %d\n",s.avg);
    printf("Total: %d\n",s.total);
    printf("Size of structure: %d",sizeof(s));
    printf("\nIn union\n");
    printf("Name: %s\n",t.name);
    printf("ID: %d\n",t.id);
    printf("Average: %d\n",t.avg);
    printf("Total: %d\n",t.total);
    printf("Size of union: %d",sizeof(t));

    return 0;
}