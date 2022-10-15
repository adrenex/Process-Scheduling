#include<stdio.h>
#include<string.h>
int main()
{
    int pn[10],start[10],rt[10],tat[10],bt[10],finish[10],arr[10],i,j,temp,n,wt[10];
    int tottat=0,totwt=0,totbt=0;
    printf("Enter the Number of Processes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Process number, Arrival Time & Burst Time : ");
        scanf("%d%d%d",&pn[i],&arr[i],&bt[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[i]<arr[j])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=pn[i];
                pn[i]=pn[j];
                pn[j]=temp;
            }
        }
    }
    finish[0] = 0;
    for(i=0;i<n;i++)
    {
        if(i==0 || arr[i] > finish[i-1])
        {
            start[i]=arr[i];
        }
        else
            start[i]=finish[i-1];
        rt[i]=start[i]-arr[i];
        finish[i]=start[i]+bt[i];
        tat[i]=finish[i]-arr[i];
        wt[i]=tat[i]-bt[i];
    }
     printf("\n PNo   Arrtime Burstime WaitTime  Start   TAT\tFinish\tResponse");
     for(i=0; i<n; i++)
     {
         printf("\n%3d\t%3d\t%3d\t%3d\t%3d\t%4d\t%3d\t%3d",pn[i],arr[i],bt[i],rt[i],start[i],tat[i],finish[i],rt[i]);
         totwt+=wt[i];
         tottat+=tat[i];
         totbt+=bt[i];
     }
     float cpu = (float)totbt/finish[n-1];
     printf("\nAverage Waiting time: %f\n",(float)totwt/n);
     printf("Average Turn Around Time: %f\n",(float)tottat/n);
     printf("Throughput %f\n",(float)n/finish[n-1]);
     printf("CPU Efficiency: %f\n",cpu*100);
     printf("Number of Context Switches: %d\n",n+1);
    return 0;
}

