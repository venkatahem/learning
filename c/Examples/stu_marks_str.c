#include <stdio.h>

struct student
{
    char name[20];
    int rollno;
    int marks[6];
};
int main()
{
    struct student s[3];
    int i, j;
    for (i = 0; i < 3; i++)
    {
        printf("Enter student name: ");
        scanf("%s", s[i].name);
        printf("Enter student roll number: ");
        scanf("%d", &s[i].rollno);
        for (j = 0; j < 3; j++)
        {
            printf("Enter the marks of subject[%d]: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
        printf("\n");
    }
    for (i = 0; i < 3; i++)
    {
        printf("Student name is %s\nRoll number is %d\n", s[i].name, s[i].rollno);
        for (j = 0; j < 3; j++)
        {
            printf("Marks of subject[%d] = %d\n", j + 1, s[i].marks[j]);
        }
        printf("\n");
    }
    return 0;
}