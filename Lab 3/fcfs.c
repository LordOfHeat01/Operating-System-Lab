#include<stdio.h>
#include<string.h>
struct Process
{
        char pid[5];
        int at;
        int bt;
        int ct;
        int tat;
        int wt;
};
void sort(struct Process p[], int n ){
        for(int i =0;i<n-1;i++){
                for(int j =i+1;j<n;j++){
                        if(p[i].at > p[j].at){
                                struct Process temp = p[i];
                                p[i] = p[j];
                                p[j] = temp;}
                }
        }
}
 int main (){
         int n ;
         printf("Enter no of Subprocesss: ");
         scanf("%d", &n);
         struct Process p[n];
         for(int i =0;i<n;i++){
                 printf ("Enter Process id , Arrival Time, Bust Time for process %d: ", i+1);
                 scanf("%s %d %d", p[i].pid, &p[i].at, &p[i].bt);
         }
         sort(p,n);
         int time =0;
         float totaltat = 0, totalwt =0;
         for ( int i =0;i<n;i++){
                 if (time< p[i].at){
                         time = p[i].at;}
                 time += p[i].bt;
                 p[i].ct = time;
                 p[i].tat = p[i].ct - p[i].at;
                 p[i].wt = p[i].tat - p[i].bt;
                 totaltat += p[i].tat;
                 totalwt  += p[i].wt;}
         float avgtat = totaltat/n;
         float avgwt = totalwt/n;
          printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
         for (int i =0;i<n;i++){

              printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
         }
         printf("\n Average Turn Around Time : %.2f", avgtat);
        printf("\n Average Waiting Time : %.2f", avgwt);
        return 0;
 }
 /*
First Come First Serve (FCFS) Scheduling
Sample Run & Output Guide

Provide input in this format:
PID  ArrivalTime  BurstTime

Example Input:
P1 0 5
P2 1 3
P3 2 8
P4 3 6

Expected Output (FCFS):

PID  AT  BT  CT  TAT WT
P1   0   5   5   5   0
P2   1   3   8   7   4
P3   2   8   16  14  6
P4   3   6   22  19  13

Where:
CT  = Completion Time
TAT = Turnaround Time (CT - AT)
WT  = Waiting Time (TAT - BT)

This verifies correct FCFS scheduling implementation.
Run the program in this repository to reproduce results.
*/
