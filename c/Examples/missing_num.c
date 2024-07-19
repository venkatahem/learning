#include <stdio.h>
void quicksort(int number[], int first, int last)
{
    int i, j, pivot, temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;

        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;
            }
        }

        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main()
{
    int i, count, number[200000];
    int nums = 1, num[200000];

    scanf("%d", &count);

    for (i = 0; i < (count - 1); i++)
        scanf("%d", &number[i]);

    quicksort(number, 0, count - 2);

    for (i = 0; i < count; i++)
    {
        num[i] = nums++;
    }

    for (i = 0; i < count; i++)
    {
        if (num[i] != number[i])
        {
            printf("%d", num[i]);
            break;
        }
    }

    return 0;
}

/*

You are given all numbers between 1,2,…,n except one. Your task is to find the missing number.

Input Format

The first input line contains an integer n.

The second line contains n−1 numbers. Each number is distinct and between 1 and n (inclusive).

Constraints

2 ≤ n ≤ 2⋅10^5

Output Format

Print the missing number.

*/