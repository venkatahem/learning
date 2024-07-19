/*You have two boxes containing a and b pencils. On each move, you can either remove one pencil from the left box and two pencils from the right box, or two pencils from the left box and one pencil from the right box.

Your task is to efficiently find out if you can empty both the pencil boxes.

Input Format

The first input line has an integer t: the number of tests.

After this, there are t lines, each of which has two integers a and b: the numbers of pencils in the boxes.

Constraints

1 ≤ t ≤ 10^5

0≤ a,b ≤ 10^9

Output Format

String YES or NO (Yes, YEs are invalid)*/
#include <stdio.h>
int main()
{
    long int x;
    long int arr[100000];
    long int sum;
    long int i;
    scanf("%ld", &x);
    for (i = 0; i < 2 * x; i++)
    {
        scanf("%ld", &arr[i]);
    }
    for (i = 0; i < 2 * x; i = i + 2)
    {
        sum = arr[i] + arr[i + 1];
        if (sum % 3 == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}