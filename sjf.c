#include <stdio.h>

int main() {
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1; // Process IDs start from 1
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            if (bt[i] > bt[k]) {
                // Swap burst time
                temp = bt[i];
                bt[i] = bt[k];
                bt[k] = temp;
                // Swap process numbers
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
            }
        }
    }

   
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = tat[0];

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];  
        tat[i] = wt[i] + bt[i];         
        wtavg += wt[i];
        tatavg += tat[i];
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    wtavg /= n;
    tatavg /= n;

    printf("\nAverage Waiting Time: %.2f", wtavg);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg);

    return 0;
}



//Enter the number of processes: 3
//Enter Burst Time for Process 1: 3
//Enter Burst Time for Process 2: 3
//Enter Burst Time for Process 3: 4

//Process	Burst Time	Waiting Time	Turnaround Time
//P1	3		0		3
//P2	3		3		6
//P3	4		6		10

//Average Waiting Time: 3.00
//Average Turnaround Time: 6.33
