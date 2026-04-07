#include<stdio.h>

int turn = 0;  // shared variable

void process0(int n){

    for(int i=0;i<n;i++){

        // wait for turn
        while(turn != 0);

        printf("Process 0 entering critical section\n");

        printf("Process 0 leaving critical section\n");

        turn = 1;  // give turn to P1
    }
}

void process1(int n){

    for(int i=0;i<n;i++){

        while(turn != 1);

        printf("Process 1 entering critical section\n");

        printf("Process 1 leaving critical section\n");

        turn = 0;  // give turn to P0
    }
}

int main(){

    int n;
    printf("Enter number of attempts: ");
    scanf("%d",&n);

    // simulate alternation
    for(int i=0;i<n;i++){
        process0(1);
        process1(1);
    }

    return 0;
}