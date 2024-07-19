#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_job, i, j;
    printf("Total Number of Processes:");
    scanf("%d", &num_job);
    // int arrival_time[num_job],burst_time[num_job];
    int *arrival_time = (int *)malloc(num_job * (sizeof(int)));
    int *burst_time = (int *)malloc(num_job * (sizeof(int)));
    printf("Arrival times:\n");
    for (i = 0; i < num_job; i++)
        scanf("%d", &arrival_time[i]);
    printf("Burst times:\n");
    for (i = 0; i < num_job; i++)
        scanf("%d", &burst_time[i]);
    // int Bt[num_job],Ct[num_job];
    int *Bt = (int *)malloc(num_job * (sizeof(int)));
    int *Ct = (int *)malloc(num_job * (sizeof(int)));
    for (i = 0; i < num_job; i++)
        Bt[i] = burst_time[i];
    int count = 0;
    j = 0;
    while (j < num_job)
    {
        int min_limit = 1000, index = -1;
        for (i = 0; i < num_job; i++)
        {
            if (Bt[i] == min_limit)
            {
                if (arrival_time[i] < arrival_time[index])
                    index = i;
            }

            else if (Bt[i] < min_limit)
            {
                if (arrival_time[i] <= count)
                {
                    min_limit = Bt[i];
                    index = i;
                }
            }
        }
        if (index != -1)
        {
            Ct[index] = burst_time[index] + count;
            count += burst_time[index];
            j++;
            Bt[index] = 1001;
        }
        // else
        //     count++;
    }

    // int TAT[num_job],WT[num_job];
    int *TAT = (int *)malloc(num_job * (sizeof(int)));
    int *WT = (int *)malloc(num_job * (sizeof(int)));

    for (i = 0; i < num_job; i++)
        TAT[i] = Ct[i] - arrival_time[i];

    for (i = 0; i < num_job; i++)
        WT[i] = TAT[i] - burst_time[i];

    printf("\nProcess Table:\nPid\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < num_job; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", (i + 1), arrival_time[i], burst_time[i], Ct[i], TAT[i], WT[i]);

    float avg_var = 0;
    for (i = 0; i < num_job; i++)
        avg_var += (float)TAT[i];
    printf("\nAverage Turnaround Time: %f", avg_var / num_job);
    avg_var = 0;
    for (i = 0; i < num_job; i++)
        avg_var += (float)WT[i];
    printf("\nAverage Waiting Time: %f", avg_var / num_job);
    printf("\n");
}