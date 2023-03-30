#include <stdio.h>
#include <stdlib.h>

int n, r, ch;

int safe(int avail[], int max[][50], int need[][50], int alloc[][50]) {
    int finish[50] = {0};
    int flag = 0;
    int seq[n];
    int work[r];
    int i, j, k;
    int count = 0;

    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }

    for (i = 0; i < r; i++) {
        work[i] = avail[i];
    }

    while (count < n) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == r) {
                    for (k = 0; k < r; k++) {
                        work[k] = work[k] + alloc[i][k];
                    }

                    finish[i] = 1;
                    seq[count++] = i;
                    flag = 1;
                }
            }
        }

        if (flag == 0) {
            printf("Unsafe state\n");
            return 0;
        }
    }

    printf("The system is in safe mode\n");
    printf("The sequence is\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", seq[i]);
    }

    printf("\n");
    return 1;
}

int resource(int available[], int maxm[][50], int need[][50], int alloct[][50]) {
    int pid;
    int reqResource[50];
    int i, j;

    printf("Enter the process no\n");
    scanf("%d", &pid);

    if (pid > n) {
        printf("Invalid Process!");
        return;
    }

    printf("Enter the resource to be requested from process %d:\n", pid);

    for (i = 0; i < r; i++) {
        scanf("%d", &reqResource[i]);
    }

    for (i = 0; i < r; i++) {
        if (reqResource[i] <= need[pid][i]) {
            if (reqResource[i] <= available[i]) {
                available[i] -= reqResource[i];
                alloct[pid][i] += reqResource[i];
                need[pid][i] -= reqResource[i];
                printf("\nAvailable: %d ", available[i]);
            }

            printf("Need: %d ", need[pid][i]);
        } else {
            printf("\nProcess is not in safe State and request Cannot be granted\n");
            return 0;
        }
    }

    printf("\nRequest can be granted\n");
    return 1;
}

int main() {
    int i, j;
    int max[50][50], need[50][50], alloc[50][50];
    int avail[50];

    printf("Enter the number of process\n");
    scanf("%d", &n);

    printf("Enter the number of resources\n");
    scanf("%d", &r);

    printf("Enter the max matrix\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocation matrix\n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<r;j++)
      {
        scanf("%d",&alloc[i][j]);
      }
   }
   printf("Enter the number of process\n");
scanf("%d",&n);

printf("Enter the number of resources\n");
scanf("%d",&r);

printf("Enter the max matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<r;j++)
    {
        scanf("%d",&max[i][j]);
    }
}

printf("Enter the allocation matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<r;j++)
    {
        scanf("%d",&alloc[i][j]);
    }
}

printf("Enter the available matrix\n");
for(i=0;i<r;i++)
{
    scanf("%d",&avail[i]);
}

//Calculate Need
for (i = 0 ; i < n ; i++)
{
    for ( j = 0 ; j < r ; j++)
    {
        need[i][j] = max[i][j] - alloc[i][j];
    }
}

printf("\nBankers Algorithm\n");

while(1)
{
    printf("\n1-safe seq\n2-resource request \n3-exit \n");
    printf("enter your choice \n");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: safe(avail,max,need,alloc);
                break;
        case 2: resource(avail,max,need,alloc);
                break;
        case 3: exit(0);
        default: printf("Invalid Choice\n");
    }
}
