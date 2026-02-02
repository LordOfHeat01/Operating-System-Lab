#include<stdio.h>
#include<string.h>
struct Process{
    char id [5];
    char state[20];
    int c,r1,r2;//\\counter, register 1 and register 2

};
void display(struct Process p[], int n){
    printf("Process Details:\n");
    printf("ID\tState\tCounter\tRegister1\tRegister2\n");
    for(int i=0;i<n;i++){
        printf("%s\t%s\t%d\t%d\t\t%d\n",p[i].id,p[i].state,p[i].c,p[i].r1,p[i].r2);
    }
}
int main (){
int n ;
printf("Enter number of processes: ");
scanf("%d",&n);
struct Process p[n];

for(int i=0;i<n;i++){
    printf("Enter process %d details (id state counter register1 register2):\n",i+1);
    scanf("%s %s %d %d %d",p[i].id,p[i].state,&p[i].c,&p[i].r1,&p[i].r2);
}
display(p,n);
    return 0;
}