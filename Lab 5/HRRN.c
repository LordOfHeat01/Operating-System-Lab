#include<stdio.h>
#include<stdbool.h>

struct Process {
    char id[10];
    int at, bt;
    int ct, tat, wt;
    bool completed;
};

int main() {

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct Process p[n];

    // Input
    for(int i=0;i<n;i++){
        printf("Enter Process ID, Arrival Time, Burst Time for process %d: ",i+1);
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].completed = false;
    }

    int current_time = 0;
    int finished = 0;

    // HRRN Scheduling
    while(finished < n){

        float highest_rr = -1.0;
        int selected = -1;

        for(int i=0;i<n;i++){

            if(p[i].at <= current_time && !p[i].completed){

                int wt = current_time - p[i].at;
                float rr = (float)(wt + p[i].bt) / p[i].bt;

                if(rr > highest_rr){
                    highest_rr = rr;
                    selected = i;
                }
            }
        }

        // If no process available
        if(selected == -1){
            current_time++;
            continue;
        }

        // Execute selected process
        p[selected].wt = current_time - p[selected].at;
        current_time += p[selected].bt;

        p[selected].ct = current_time;
        p[selected].tat = p[selected].ct - p[selected].at;
        p[selected].completed = true;

        finished++;
    }

    // Output
    float total_tat=0, total_wt=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

        total_tat += p[i].tat;
        total_wt  += p[i].wt;
    }

    printf("\nAverage Turnaround Time: %.2f",total_tat/n);
    printf("\nAverage Waiting Time: %.2f",total_wt/n);

    return 0;
}

/*
Sample Run & Output Guide (HRRN Scheduling)

Run this program with the following inputs:
(Process  Arrival Time  Burst Time)

P1 0 3
P2 2 6
P3 4 4

On execution (HRRN Scheduling), the output will be:

PID   AT  BT  CT  TAT WT
P1    0   3   3   3   0
P2    2   6   9   7   1
P3    4   4   13  9   5

This demonstrates correct calculation of:
CT  - Completion Time
TAT - Turnaround Time (CT - AT)
WT  - Waiting Time (TAT - BT)

HRRN selects the process with the
Highest Response Ratio:
RR = (Waiting Time + Burst Time) / Burst Time

Run the program to verify results.
*/
