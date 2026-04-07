#include<stdio.h>
#include<stdbool.h>

bool flag[2] = {false, false};
int turn;

// one step of process execution
void peterson(int i){

    int other = 1 - i;

    printf("Process %d requesting critical section\n", i);

    flag[i] = true;        // interested
    turn = other;          // give turn to other

    // wait condition
    while(flag[other] && turn == other);

    // critical section
    printf("Process %d entering critical section\n", i);

    printf("Process %d leaving critical section\n", i);

    flag[i] = false;       // exit
}

int main(){

    int n;
    printf("Enter number of attempts: ");
    scanf("%d",&n);

    // simulate interleaving
    for(int i=0;i<n;i++){

        peterson(0);  // P0 tries
        peterson(1);  // P1 tries
    }

    return 0;
}