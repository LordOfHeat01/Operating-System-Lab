#include<stdio.h>
struct Process
{
    char id[10];
    int bt,rt;
    int ct;
    int tat;
    int wt;
    int q;
};
int main (){    
    int n;
    printf("Enter number of process: ");
    scanf("%d",&n);
    struct Process p[n];
    for(int i=0;i<n;i++){
        printf("Enter Process id , Burst Time, Queue for Process %d: ",i+1);
        scanf("%s %d %d",p[i].id,&p[i].bt,&p[i].q);
        p[i].rt = p[i].bt;}
        int tq;
        printf("Enter Time Quantum for Queue 1: ");
        scanf("%d",&tq);

    int time = 0;
    int q1[100],q2[100];
    int f1=0,r1=0,f2=0,r2=0;
    for(int i=0;i<n;i++){
        if(p[i].q == 1){
            q1[r1++] = i;
        }
        else{
            q2[r2++] = i;
        }
    }
     // 🔥 EXECUTE QUEUE 1 (ROUND ROBIN)
    while(f1 < r1){

        int i = q1[f1++];   // take process from queue

        if(p[i].rt > tq){
            // run for time quantum
            time += tq;
            p[i].rt -= tq;

            // put back into queue (not finished)
            q1[r1++] = i;
        }
        else{
            // run completely
            time += p[i].rt;
            p[i].rt = 0;

            p[i].ct = time;   // set completion time
        }
    }

    //  EXECUTE QUEUE 2 (FCFS)
    for(int k=f2;k<r2;k++){

        int i = q2[k];

        time += p[i].bt;     // run completely

        p[i].ct = time;      // completion time
    }

    // 🔹 CALCULATE TAT & WT
    float totaltat=0, totalwt=0;

    printf("\nPID\tQ\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++){

        p[i].tat = p[i].ct;           // AT = 0 assumed
        p[i].wt  = p[i].tat - p[i].bt;

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        p[i].id,p[i].q,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

        totaltat += p[i].tat;
        totalwt  += p[i].wt;
    }

    printf("\nAverage TAT: %.2f",totaltat/n);
    printf("\nAverage WT: %.2f",totalwt/n);
    return 0;
}