#include<stdio.h>
#include<stdlib.h>

void robin()
{
    int i, n, quantum, remaining, ct = 0, flag = 0, wt = 0, tat = 0, at[10], bt[10], t[10];
    printf("\nEnter total number of processes:\t");
    scanf("%d", &n);
    remaining = n;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the details of process[%d]\n", i + 1);
        printf("Arrival Time:\t");
        scanf("%d", &at[i]);
        printf("Burst Time:\t");
        scanf("%d", &bt[i]);
        t[i] = bt[i];
    }
    printf("\nEnter Time Quantum:\t");
    scanf("%d", &quantum);
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for (i = 0; remaining != 0;)
    {
        if (t[i] <= quantum && t[i] > 0)
        {
            ct = ct + t[i];
            t[i] = 0;
            flag = 1;
        }
        else if (t[i] > 0)
        {
            t[i] = t[i] - quantum;
            ct = ct + quantum;
        }
        if (t[i] == 0 && flag == 1)
        {
            remaining--;
            printf("\nProcess[%d]\t\t %d\t\t %d\t\t\t %d", i + 1, bt[i], ct - at[i], ct - at[i] - bt[i]);
            wt = wt + ct - at[i] - bt[i];
            tat = tat + ct - at[i];
            flag = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= ct)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\n\nAverage Waiting Time:\t%f", (float)wt / n);
    printf("\nAvg Turnaround Time:\t%f\n", (float)tat / n);
}

void srtf()
{
    int i, j, n, min, ct, total = 0, wt = 0, tat = 0, at[10], bt[10], t[10];
    printf("Enter the number of Processes : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time for Process P%d : ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for Process P%d : ", i + 1);
        scanf("%d", &bt[i]);
        t[i] = bt[i];
        total = total + bt[i];
    }
    printf("\n\nProcess\t|Turnaround Time|\t Waiting Time\n\n");
    t[9] = 9999;
    for (i = 0; i < total; i++)
    {
        min = 9;
        for (j = 0; j < n; j++)
        {
            if (at[j] <= i && t[j] < t[min] && t[j] > 0)
            {
                min = j;
            }
        }
        t[min]--;
        if (t[min] == 0)
        {
            ct = i + 1;
            printf("\nP[%d]\t|\t%d\t|\t%d",min+1,ct-at[min],ct-at[min]-bt[min]);
            wt=wt+ct-at[min]-bt[min];
            tat=tat+ct-at[min];
        }
    }
    printf("\n\nAverage waiting time = %f\n",(float)wt/n);
    printf("Average Turnaround time =%f",(float)tat/n);
}
int main()
{
 int ch;
  while(1)
  {
    printf("Enter 1-->round robin,2-->srtf,3-->stop\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:robin();
        break;
        case 2:srtf();
        break;
        default:exit(0);
      }
    }
return 0;
} 
