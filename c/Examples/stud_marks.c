#include <stdio.h>
#include <stdlib.h>
struct student
{
    int reg;
    char name[20];
    int mark[4];
    int avg;
};
int main()
{
    int reg1;
    struct student stu[2];
    printf("enter the required details:");
    for (int i = 0; i < 2; i++)
    {
        printf("\nSTUDENT %d", i + 1);
        printf("\nenter the register number:");
        scanf("%d", &stu[i].reg);
        printf("\nenter the name:");
        scanf("%s", stu[i].name);
        printf("\nenter marks in four subject:");
        scanf("%d %d %d %d", &stu[i].mark[0], &stu[i].mark[1], &stu[i].mark[2], &stu[i].mark[3]);
        stu[i].avg = (stu[i].mark[0] + stu[i].mark[1] + stu[i].mark[2] + stu[i].mark[3]) / 4;
    }
    while (1)
    {
        printf("\nEnter the register number of the student whose mark should be updated:(0 to exit)");
        scanf("%d", &reg1);
        if (reg1 == 0)
            break;
        else
        {
            printf("\nenter the updated marks:");
            for (int i = 0; i < 2; i++)
            {
                if (stu[i].reg == reg1)
                {
                    scanf("%d %d %d %d", &stu[i].mark[0], &stu[i].mark[1], &stu[i].mark[2], &stu[i].mark[3]);
                    stu[i].avg = (stu[i].mark[0] + stu[i].mark[1] + stu[i].mark[2] + stu[i].mark[3]) / 4;
                }
            }
        }
    }
    for (int i = 0; i < 2; i++)
    {
        if (stu[i].avg > 50 && stu[i].avg < 65)
        {
            printf("\nRegister number:%d", stu[i].reg);
            printf("\nName:%s", stu[i].name);
            printf("\nMarks in four subject:%d %d %d %d", stu[i].mark[0], stu[i].mark[1], stu[i].mark[2], stu[i].mark[3]);
            printf("\nAverage:%d", stu[i].avg);
        }
    }
    return 0;
}