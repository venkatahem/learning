#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    long int i, sum, arr[2000000], len;
    scanf("%ld", &len);
    sum = 0;
    for (i = 0; i < len; i++)
    {
        scanf("%ld", &arr[i]);
    }
    for (i = 0; i < len; i++)
    {

        if ((arr[i] > arr[i + 1]) && ((i + 1) != len))
        {

            sum = sum + (arr[i] - arr[i + 1]);
            // printf("%ld,%ld\t%ld\n",arr[i],arr[i+1],sum);
            arr[i + 1] = arr[i];
        }
    }
    printf("%ld", sum);
    return 0;
}

/*

You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at least as large as the previous element.

On each move, you may increase the value of any element by one. What is the minimum number of moves required?

Input Format

The first input line contains an integer n: the size of the array.

Then, the second line contains n integers x1,x2,…,xn: the contents of the array.

Constraints

1 ≤ n ≤ 2*10^5
1 ≤ xi ≤ 10^9

Output Format

Print the minimum number of moves.

*/