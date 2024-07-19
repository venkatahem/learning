#include <stdio.h>

#define SIZE 5

struct student_marks
{
    int rollno;
    char name[30];
    int marks[3];
    int average;
};

void input_details(struct student_marks *s)
{
    int i;
    int j;
    for (i = 0; i < SIZE; i++)
    {
        printf("---------- Student %d ----------\n", i + 1);
        printf("Enter Roll.No: ");
        scanf("%d", &s[i].rollno);
        getchar();
        printf("Name: ");
        fgets(s[i].name, 30, stdin);
        for (j = 0; s[i].name[j] != '\0'; j++)
        {
            if (s[i].name[j] >= 65 && s[i].name[j] <= 90)
            {
                s[i].name[j] = s[i].name[j] + 32;
            }
        }
        for (j = 0; j < 3; j++)
        {
            printf("Marks in subject %d:", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
        s[i].average = 0;
        for (j = 0; j < 3; j++)
        {
            s[i].average = s[i].average + s[i].marks[j];
        }
        s[i].average = s[i].average / 3;
    }
}

void avg_marks_sub(struct student_marks *s)
{
    int i;
    int j;
    int avg_mark[3];
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < 3; j++)
        {
            avg_mark[j] = avg_mark[j] + s[i].marks[j];
        }
    }
    for (j = 0; j < 3; j++)
    {
        avg_mark[j] = (avg_mark[j] / 5);
    }
    printf("\nEnter the subject no: ");
    scanf("%d", &i);
    printf("\nAverage marks of subject %d: %d\n", i, avg_mark[i - 1]);
}

void marks_swap(struct student_marks *s)
{
    int i;
    int j;
    int x;
    int temp;
    printf("Student roll no: ");
    scanf("%d", &x);
    for (i = 0; i < SIZE; i++)
    {
        if (s[i].rollno == x)
        {
            j = i;
            break;
        }
    }
    printf("\nSubjects to swap\n1 --> Subjects 1 and 2\n2 --> Subjects 1 and 3\n3 --> Subjects 2 and 3\nINPUT:");
    scanf("%d", &i);
    if (i == 1)
    {
        temp = s[j].marks[1];
        s[j].marks[1] = s[j].marks[2];
        s[j].marks[2] = temp;
    }
    else if (i == 2)
    {
        temp = s[j].marks[1];
        s[j].marks[1] = s[j].marks[3];
        s[j].marks[3] = temp;
    }
    else if (i == 3)
    {
        temp = s[j].marks[2];
        s[j].marks[2] = s[j].marks[3];
        s[j].marks[3] = temp;
    }
}

void stu_marks(struct student_marks *s)
{
    int i;
    int j;
    int x;
    printf("Student roll no: ");
    scanf("%d", &x);
    for (i = 0; i < SIZE; i++)
    {
        if (s[i].rollno == x)
        {
            j = i;
            break;
        }
    }
    for (i = 0; i < 3; i++)
    {
        printf("\nSubject %d: %d\n", i + 1, s[j].marks[i]);
    }
}

void stu_avg_mark(struct student_marks *s)
{
    int x;
    int i;
    printf("Student Roll.No: ");
    scanf("%d", &x);
    for (i = 0; i < SIZE; i++)
    {
        if (s[i].rollno == x)
        {
            printf("\nAverage marks of the student: %d", s[i].average);
            break;
        }
    }
}
void all_stu_info(struct student_marks *s)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("Name: %s\n", s[i].name);
        printf("Roll.no: %d\n", s[i].rollno);
    }
}

int main()
{
    int i;
    int x;
    int avg_mark[3] = {0, 0, 0};

    struct student_marks s[SIZE];

    input_details(s);

    do
    {
        printf("1 --> All students info\n2 --> Average marks of a student\n3 --> Average marks of a particular subject\n4 --> Swap marks of a student\n5 --> Marks of a student\n0 --> Exit\nInput:");
        scanf("%d", &x);
        if (x == 1)
        {
            all_stu_info(s);
        }
        else if (x == 2)
        {
            stu_avg_mark(s);
        }
        else if (x == 3)
        {
            avg_marks_sub(s);
        }
        else if (x == 4)
        {
            marks_swap(s);
        }
        else if (x == 5)
        {
            stu_marks(s);
        }
    } while (x != 0);

    return 0;
}