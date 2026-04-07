#include<stdio.h>

int lock = 0;  // shared variable

void process(int i, int n){

    for(int j=0;j<n;j++){

        printf("Process %d requesting critical section\n", i);

        // wait until lock is free
        while(lock == 1);

        lock = 1;  // acquire lock

        // critical section
        printf("Process %d entering critical section\n", i);

        printf("Process %d leaving critical section\n", i);

        lock = 0;  // release lock
    }
}

int main(){

    int n;
    printf("Enter number of attempts: ");
    scanf("%d",&n);

    // simulate two processes sequentially
    process(0,n);
    process(1,n);

    return 0;
}