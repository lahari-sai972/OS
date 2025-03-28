#include <stdio.h>

int main() {
    int n, frameSize, pages[100], frames[10], i, j, k, pos, farthest, pageFaults = 0, count = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frameSize);

    for (i = 0; i < frameSize; i++)
        frames[i] = -1; // Initialize frames as empty

    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < count; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            if (count < frameSize) {
                frames[count++] = pages[i];
            } else {
                farthest = -1;
                pos = -1;
                for (j = 0; j < frameSize; j++) {
                    int foundInFuture = 0;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k]) {
                            if (k > farthest) {
                                farthest = k;
                                pos = j;
                            }
                            foundInFuture = 1;
                            break;
                        }
                    }
                    if (!foundInFuture) {
                        pos = j;
                        break;
                    }
                }
                frames[pos] = pages[i];
            }
            pageFaults++;
        }

        // Print frames after each step
        printf("\nStep %d: ", i + 1);
        for (j = 0; j < count; j++)
            printf("%d ", frames[j]);
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    return 0;
}
//OUTPUT
//Enter number of pages: 3
//Enter page reference string: 1 4 2 
//Enter number of frames: 8

//Step 1: 1 
//Step 2: 1 4 
//Step 3: 1 4 2 
//Total Page Faults: 3

