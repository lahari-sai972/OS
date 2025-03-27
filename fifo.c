#include <stdio.h>

int main() {
    int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("\nEnter the reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("\nEnter number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
        m[i] = -1; // Initialize all frames to -1 (empty)

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++) {
        int pageFound = 0;

        for (k = 0; k < f; k++) {
            if (m[k] == rs[i]) {
                pageFound = 1; // Page hit
                break;
            }
        }

        if (!pageFound) {
            m[count] = rs[i]; 
            count = (count + 1) % f; 
            pf++; // Increase page fault count
        }

        for (j = 0; j < f; j++)
            printf("\t%d", (m[j] == -1) ? -1 : m[j]);

        if (!pageFound)
            printf("\tPF No. %d", pf); // Indicate page fault

        printf("\n");
    }

    printf("\nTotal Page Faults using FIFO: %d\n", pf);

    return 0;
}
