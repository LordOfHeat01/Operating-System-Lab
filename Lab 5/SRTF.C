#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

struct Process {
    char id[10];
    int at;
    int bt;
    int tat;
    int ct;
    int wt, rt;
};

int main (){
    int n ;
    printf("Enter number of process: ");
    scanf("%d",&n);

    struct Process p[n];

    for (int i=0;i<n;i++){
        printf("Enter Process id , Arrival Time, Burst Time for process %d: ",i+1);
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }

    int crt=0, c=0;
    int last = -1; // for gantt tracking

    printf("\nGantt Chart:\n");
    printf("%d ",crt);

    while (c<n){
        int s=-1;
        int mr=INT_MAX;

        for (int i=0;i<n;i++){
            if (p[i].at<=crt && p[i].rt>0 && p[i].rt<mr){
                mr=p[i].rt;
                s=i;
            }
        }

        if(s==-1){
            crt++;
            continue;
        }

        // print when process changes
        if(last!=s){
            printf("| %s ",p[s].id);
            last=s;
        }

        p[s].rt--;
        crt++;

        printf("%d ",crt);

        if (p[s].rt==0){
            p[s].ct=crt;
            c++;
        }
    }

    float tat=0, twt=0;

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

        tat += p[i].tat;
        twt += p[i].wt;
    }

    printf("\nAverage Turn Around Time %.2f",tat/n);
    printf("\nAverage waiting Time %.2f",twt/n);

    return 0;
}
/*
Sample Run & Output Guide

Run this program with the following inputs:
(Process  Arrival Time  Burst Time)

P1 0 6
P2 1 3
P3 2 1

On execution (SRTF Scheduling), the output will be:

PID   AT  BT  CT  TAT WT
P1    0   6   10  10  4
P2    1   3   5   4   1
P3    2   1   3   1   0

This demonstrates correct calculation of:
CT  - Completion Time
TAT - Turnaround Time (CT - AT)
WT  - Waiting Time (TAT - BT)

SRTF always selects the process with the
shortest remaining burst time at any moment.

Run the program in the repository to verify these results.
*/
