#include<stdio.h>
int main()
{
    int rs[50], i, j, k, m, f, cntr[20], a[20], min, pf=0;
    printf("\nEnter number of page references -- ");
    scanf("%d",&m);
    printf("\nEnter the reference string -- ");
    for(i=0; i<m; i++)
        scanf("%d",&rs[i]);
    printf("\nEnter the available number of frames -- ");
    scanf("%d",&f); 
    for(i=0; i<f; i++)  
    {
        cntr[i]=0;
        a[i]=-1;
    }
    printf("\nThe Page Replacement Process is:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<f; j++)
        {
            if(rs[i] == a[j])  // Page hit
            {
                cntr[j]++; 
                break;
            }
        }
        if(j == f) // Page fault
        {
            min = 0;
            for(k=1; k<f; k++) 
                if(cntr[k] < cntr[min]) 
                    min = k;
            
            a[min] = rs[i]; 
            cntr[min] = 1;
            pf++;
        }
        // Printing current frame status
        for(j=0; j<f; j++)
            printf("\t%d", a[j]);
        
        printf("\tPF No. %d", pf);
        printf("\n");
    }
    printf("\nTotal number of page faults -- %d\n", pf);
    return 0;
}

// Output
// Enter number of page references -- 5
// Enter the reference string -- 1 2 1 3 4
// Enter the available number of frames -- 3
// The Page Replacement Process is:
// 	1	-1	-1	PF No. 1
// 	1	2	-1	PF No. 2
// 	1	2	-1	PF No. 2
// 	1	2	3	PF No. 3
// 	1	4	3	PF No. 4
// Total number of page faults -- 4
