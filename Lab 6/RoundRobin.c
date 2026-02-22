#include<stdio.h>
#include<string.h>

struct Process {
    char id[10];
    int at;
    int bt;
    int tat;
    int ct;
    int wt, rt;
};

int main(){
    int n, tq;
    printf("Enter number of process: ");
    scanf("%d",&n);

    struct Process p[n];

    for(int i=0;i<n;i++){
        printf("Enter Process id , Arrival Time, Burst Time for process %d: ",i+1);
        scanf("%s %d %d",p[i].id,&p[i].at,&p[i].bt);
        p[i].rt = p[i].bt;
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int crt = 0, completed = 0;
    int queue[100], front=0, rear=0;
    int visited[n];

    for(int i=0;i<n;i++) visited[i]=0;

    // add processes that arrive at time 0
    for(int i=0;i<n;i++){
        if(p[i].at==0){
            queue[rear++] = i;
            visited[i]=1;
        }
    }

    printf("\nGantt Chart:\n");
    printf("%d ",crt);

    while(completed < n){

        // if queue empty, move time forward
        if(front==rear){
            crt++;
            for(int i=0;i<n;i++){
                if(p[i].at<=crt && !visited[i]){
                    queue[rear++]=i;
                    visited[i]=1;
                }
            }
            continue;
        }

        int i = queue[front++];

        printf("| %s ",p[i].id);

        if(p[i].rt > tq){
            crt += tq;
            p[i].rt -= tq;
        }else{
            crt += p[i].rt;
            p[i].rt = 0;
            p[i].ct = crt;
            completed++;
        }

        printf("%d ",crt);

        // add newly arrived processes
        for(int j=0;j<n;j++){
            if(p[j].at<=crt && !visited[j]){
                queue[rear++] = j;
                visited[j]=1;
            }
        }

        // if process not finished, add back to queue
        if(p[i].rt > 0){
            queue[rear++] = i;
        }
    }

    float tat=0, twt=0;

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);

        tat += p[i].tat;
        twt += p[i].wt;
    }

    printf("\nAverage Turn Around Time %.2f",tat/n);
    printf("\nAverage Waiting Time %.2f",twt/n);

    return 0;
}