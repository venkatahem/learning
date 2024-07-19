#include <stdio.h>

int main()
{
    int quiz[8] = {202003, 202023, 202031, 202007, 202046, 202012, 202014, 202054};
    int present[8] = {202005, 202054, 202014, 202065, 202046, 202007, 202034, 202031};
    int both[20];
    int i, j, k, len_quiz, len_present, temp;

    len_quiz = sizeof(quiz) / sizeof(int);
    len_present = sizeof(present) / sizeof(int);
    k = 0;
    for (i = 0; i < len_quiz; i++)
    {

        for (j = 0; j < len_present; j++)
        {
            if (quiz[i] == present[j])
            {
                both[k] = quiz[i];
                k++;
                break;
            }
        }
    }
    printf("Students in both programmes:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d\t", both[i]);
    }

    return 7;
}