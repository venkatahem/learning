#include <stdio.h>
struct student
{
    int rollno, math, phy, che;
    char name[20];

} obj[5];
void Displayinfo()
{
    for (int i = 0; i < 5; i++)
    {
        printf("\n rollno:%d", obj[i].rollno);
        printf("\n name:%s", obj[i].name);
        printf("\n marks \n maths:%d \n physics: %d \n chemistry: %d", obj[i].math, obj[i].phy, obj[i].che);
    }
}
void calcavg()
{
    int total[5];
    float avg;
    for (int i = 0; i < 5; i++)
    {
        total[i] = obj[i].math + obj[i].phy + obj[i].che;
    }
    avg = (total[0] + total[1] + total[2] + total[3] + total[4]) / 5;
    printf("average marks of students :%f", avg);
}
void specificavg(int x)
{
    int total;
    float avg;
    for (int i = 0; i < 5; i++)
    {
        if (obj[i].rollno == x)
        {
            total = obj[i].math + obj[i].phy + obj[i].che;
        }
    }
    avg = total / 3;
    printf("average marks of student :%f", avg);
}
void displaymarks(int x)
{
    printf("\n marks of rollno: %d", x);
    for (int i = 0; i < 5; i++)
    {
        if (obj[i].rollno == x)
        {
            printf("\n marks \n maths:%d \n physics: %d \n chemistry: %d", obj[i].math, obj[i].phy, obj[i].che);
        }
    }
}
void swap(int x)
{
    int c, k;
    for (int i = 0; i < 5; i++)
    {
        if (obj[i].rollno == x)
        {
            printf("1.maths and chemistry\n 2.maths and physics \n 3.physics and chemistry");
            printf("\n Enter your choice:");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                k = obj[i].math;
                obj[i].math = obj[i].che;
                obj[i].che = k;
                break;
            case 2:
                k = obj[i].math;
                obj[i].math = obj[i].phy;
                obj[i].phy = k;
                break;
            case 3:
                k = obj[i].phy;
                obj[i].phy = obj[i].che;
                obj[i].che = k;
                break;
            default:
                printf("\n invalid choice");
                break;
            }
        }
    }
}
void convert()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; obj[i].name[j] != '\0'; j++)
        {
            if (obj[i].name[j] >= 'a' && obj[i].name[j] <= 'z')
            {
                obj[i].name[j] = obj[i].name[j] - 32;
            }
        }
    }
    printf("\n Names after convertion:");
    for (int i = 0; i < 5; i++)
    {
        printf("\n name %d : %s", i + 1, obj[i].name);
    }
}
int main()
{

    int ch, n;
    printf("\n Enter the details of 5 students");
    for (int i = 0; i < 5; i++)
    {
        printf("\n name:");
        scanf("%s", &obj[i].name);
        printf("\n rollno:");
        scanf("%d", &obj[i].rollno);
        printf("\n enter 3 subjects marks:");
        printf("\n enter maths marks:");
        scanf("%d", &obj[i].math);
        printf("\n enter physics marks:");
        scanf("%d", &obj[i].phy);
        printf("\n enter chemistry marks:");
        scanf("%d", &obj[i].che);
    }
    do
    {
        printf("\n menu");
        printf("\n 1.Display information\n 2.Average marks of all student \n 3.Average marks of specific student \n 4.swap the marks ");
        printf("\n 5. display marks of specified student\n 6.convert lower case names into uppercase\n 7.exit");
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Information of students");
            Displayinfo();
            break;
        case 2:
            calcavg();
            break;
        case 3:
            printf("\n enter rollno of student for which you want to calculate avg:");
            scanf("%d", &n);
            specificavg(n);
            break;
        case 4:
            printf("\n enter rollno of student for which you want to swap the marks:");
            scanf("%d", &n);
            swap(n);
            break;
        case 5:
            printf("\n enter rollno of student for which you want to know the marks:");
            scanf("%d", &n);
            displaymarks(n);
            break;
        case 6:
            convert();
            break;
        case 7:
            break;
        default:
            printf("\n enter valid choice");
            break;
        }
    } while (ch != 7);

    return 0;
}