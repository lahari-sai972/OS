#include <stdio.h>
int main() {
    int i, j, k, min, rs[25], m[10], count[10], flag[25], n, f, pf = 0, next = 1;
    // Get reference string length
    printf("Enter the length of reference string: ");
    scanf("%d", &n);
    // Get reference string values
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0; // Initialize flag array to track page presence
    }
    // Get number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    // Initialize frames and counters
    for (i = 0; i < f; i++) {
        count[i] = 0;
        m[i] = -1; // Indicate empty frames
    }
    printf("\nThe Page Replacement Process is:\n");
    // LRU Page Replacement Logic
    for (i = 0; i < n; i++) {
        flag[i] = 0; // Reset flag for current page reference
        // Check if the page is already in a frame
        for (j = 0; j < f; j++) {
            if (m[j] == rs[i]) {
                flag[i] = 1; // Page hit
                count[j] = next; // Update recent usage
                next++;
                break;
            }
        }
        // If page is not found in frames (page fault occurs)
        if (flag[i] == 0) {
            if (i < f) {
                // Fill empty frame
                m[i] = rs[i];
                count[i] = next;
                next++;
            } else {
                // Find the Least Recently Used (LRU) page
                min = 0;
                for (j = 1; j < f; j++) {
                    if (count[min] > count[j]) {
                        min = j;
                    }
                }
                // Replace the LRU page
                m[min] = rs[i];
                count[min] = next;
                next++;
            }
            pf++; // Increment page fault count
        }
        // Print current frames
        for (j = 0; j < f; j++) {
            if (m[j] != -1)
                printf("\t%d", m[j]);
            else
                printf("\t-");
        }
        // Indicate a page fault if it happened
        if (flag[i] == 0)
            printf("\tPF No. %d", pf);
        printf("\n");
    }
    // Print total number of page faults
    printf("\nTotal Page Faults using LRU: %d\n", pf);
    return 0;
}

// Output
// Enter the length of reference string: 5
// Enter the reference string: 1 2 3 4 1
// Enter the number of frames: 3
// The Page Replacement Process is:
// 	1	-	-	PF No. 1
// 	1	2	-	PF No. 2
// 	1	2	3	PF No. 3
// 	4	2	3	PF No. 4
// 	4	1	3	PF No. 5
// Total Page Faults using LRU: 5
