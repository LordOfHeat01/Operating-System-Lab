#include<stdio.h>
#include<limits.h>

struct Process {
    char id[10];
    int at;
    int bt;
    int pr;
    int ct;
    int tat;
    int wt;
    int done;
};

int main(){
    int n;
    printf("Enter number of process: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        printf("Enter Process id , Arrival Time, Burst Time, Priority for process %d: ",i+1);
        scanf("%s %d %d %d",p[i].id,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].done = 0;
    }

    int completed = 0;
    int crt = 0;

    printf("\nGantt Chart:\n");
    printf("%d ",crt);

    while(completed < n){

        int idx = -1;
        int bestPriority = INT_MAX;

        // find process with minimum priority value
        for(int i=0;i<n;i++){
            if(p[i].at <= crt && p[i].done==0 && p[i].pr < bestPriority){
                bestPriority = p[i].pr;
                idx = i;
            }
        }

        // if no process available, increase time
        if(idx == -1){
            crt++;
            continue;
        }

        // execute process fully
        printf("| %s ",p[idx].id);
        crt += p[idx].bt;
        printf("%d ",crt);

        p[idx].ct = crt;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        p[idx].done = 1;
        completed++;
    }

    float avgTAT=0, avgWT=0;

    printf("\n\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].id,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);

        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }

    printf("\nAverage Turn Around Time %.2f",avgTAT/n);
    printf("\nAverage Waiting Time %.2f",avgWT/n);

    return 0;
}