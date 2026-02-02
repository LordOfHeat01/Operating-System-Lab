#include<stdio.h>
#include<string.h>

struct Process{
    char id[5];
    char state[20];
    int pc, r1, r2; // program counter & registers
};

void display(struct Process p){
    printf("%s\t%s\t%d\t%d\t%d\n",
           p.id, p.state, p.pc, p.r1, p.r2);
}

int main(){

    struct Process p1, p2;

    printf("Enter details for Process 1 (id state pc r1 r2):\n");
    scanf("%s %s %d %d %d",
          p1.id, p1.state, &p1.pc, &p1.r1, &p1.r2);

    printf("Enter details for Process 2 (id state pc r1 r2):\n");
    scanf("%s %s %d %d %d",
          p2.id, p2.state, &p2.pc, &p2.r1, &p2.r2);

    // BEFORE SWITCH
    printf("\n--- Before Context Switch ---\n");
    printf("CPU executing: %s\n", p1.id);
    printf("PC=%d R1=%d R2=%d\n", p1.pc, p1.r1, p1.r2);

    // Context switch condition
    if(strcmp(p1.state,"Running")==0 &&
       strcmp(p2.state,"Ready")==0){

        printf("\nSteps during Context Switch:\n");
        printf("1. Timer interrupt occurs\n");
        printf("2. Saving %s state to PCB\n",p1.id);
        printf("3. %s: Running -> Ready\n",p1.id);

        strcpy(p1.state,"Ready");

        printf("4. Loading %s into CPU\n",p2.id);
        printf("5. %s: Ready -> Running\n",p2.id);

        strcpy(p2.state,"Running");

        // AFTER SWITCH
        printf("\n--- After Context Switch ---\n");
        printf("CPU executing: %s\n", p2.id);
        printf("PC=%d R1=%d R2=%d\n", p2.pc, p2.r1, p2.r2);

    } else {
        printf("\nContext switch not possible!\n");
        printf("P1 must be Running and P2 must be Ready\n");
    }

    return 0;
}
