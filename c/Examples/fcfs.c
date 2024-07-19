#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, i, j;
  int start = 0, end_time;
  float atat = 0, awt = 0;

  printf("Enter the no.of processes: ");
  scanf_s("%d", &x);

  int *bt = (int *)malloc(x * (sizeof(int)));
  int *pr = (int *)malloc(x * (sizeof(int)));
  int *at = (int *)malloc(x * (sizeof(int)));
  int *wt = (int *)malloc(x * (sizeof(int)));
  int *gc = (int *)malloc(x * (sizeof(int)));
  int *tat = (int *)malloc(x * (sizeof(int)));

  printf("\nInput arrival time and brust time\n");
  printf("AT  BT\n");
  for (i = 0; i < x; i++)
  {
    scanf_s("%d %d", &at[i], &bt[i]);
    pr[i] = i + 1;
  }

  // SORT

  for (i = 0; i < x; i++)
  {
    for (j = i + 1; j < x; j++)
    {
      if (at[i] > at[j])
      {
        int temp = at[i];
        at[i] = at[j];
        at[j] = temp;
        // swap(at[i], at[j]);

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
        // swap(bt[i], bt[j]);

        temp = pr[i];
        pr[i] = pr[j];
        pr[j] = temp;
        // swap(pr[i], pr[j]);
      }
    }
  }

  gc[0] = at[0] + bt[0];
  for (i = 1; i < x; i++)
  {
    if (at[i] > gc[i - 1])
    {
      gc[i] = (at[i] - gc[i - 1]) + bt[i] + gc[i - 1];
    }
    else
    {
      gc[i] = bt[i] + gc[i - 1];
    }
  }

  printf("\n\nCompletion time\n\n");
  for (i = 0; i < x; i++)
  {
    printf("P%d: %d   ", pr[i], gc[i]);
  }

  for (i = 0; i < x; i++)
  {
    tat[i] = gc[i] - at[i];
    wt[i] = tat[i] - bt[i];
  }

  printf("\n\nP\tAT\tBT\tCT\tTAT\tWT\n");

  for (i = 0; i < x; i++)
  {
    printf("\nP%d\t%d\t%d\t%d\t%d\t%d\n", pr[i], at[i], bt[i], gc[i], tat[i], wt[i]);
    atat = atat + (float)tat[i];
    awt = awt + (float)wt[i];
  }

  atat = atat / x;
  awt = awt / x;

  printf("\nAverage Turn around time = %f and waiting time = %f", atat, awt);

  return 0;
}