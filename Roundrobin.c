#include <stdio.h>

int main() {
    int n, i, tq, rem[10], tat[10], wt[10], bt[10], t = 0, done = 0;
    
    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);
    if (n > 10 || n <= 0) return printf("Invalid number of processes!\n"), 1;

    for (i = 0; i < n; i++) {
        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i]; // Copy burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);
    if (tq <= 0) return printf("Invalid time quantum!\n"), 1;

    while (done < n) { 
        for (i = 0; i < n; i++) 
            if (rem[i] > 0) {
                int exec = (rem[i] <= tq) ? rem[i] : tq;
                t += exec, rem[i] -= exec;
                if (!rem[i]) tat[i] = t, wt[i] = tat[i] - bt[i], done++;
            }
    }

    float awt = 0, atat = 0;
    printf("\nP\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) 
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]), awt += wt[i], atat += tat[i];

    printf("\nAvg WT: %.2f\nAvg TAT: %.2f\n", awt / n, atat / n);
    return 0;
}
