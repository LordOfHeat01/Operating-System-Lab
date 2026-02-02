#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
struct Process {
    char id[10];
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};
int main (){
    int n ;
    printf("Enter number of process: ");
    scanf("%d",&n);
    bool completed [n] ;
    struct Process p [n];
    for (int i =0;i<n;i++){ completed[i] = false; }
    for (int i =0;i<n;i++){
        printf("Enter Process id , Arrival Time, Burst Time for process %d: ",i+1);
        scanf("%s",p[i].id);
        fflush(stdout);
        scanf("%d %d",&p[i].at, &p[i].bt);
    }
    int time =0;
    int cc =0;
    while (cc<n){
        int mbt = INT_MAX;
        int in =-1;
        for (int i =0;i<n;i++){
            if (p[i].at<=time &&completed[i] == false ){
                if (p[i].bt < mbt){
                    mbt = p[i].bt;
                    in =i;
                }
            }
        }
        if (in == -1){
            time =time +1;
        }
        else {
            time += p[in].bt;
            p[in].ct = time;
            p[in].tat = p[in].ct - p[in].at;
            p[in].wt = p[in].tat - p[in].bt;
            completed [in]= true;
            cc+=1;
        }
        }
        float tat =0; float twt=0;
        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
        for (int i =0;i<n;i++){

        printf("%s\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        tat +=p[i].tat;
        twt +=p[i].wt;
    }
    printf("\nAverage Turn Around Time %.2f",tat/n);
    printf("\nAverage waiting Time %.2f",twt/n);
return 0;}
