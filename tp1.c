#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void P(){
    printf("Pere, PID is %d\n", getpid());
}

void P1(){
    printf("fils1, PID is %d\n", getpid());
    exit(0);
}

void P2(){
    printf("fils2, PID is %d\n", getpid());
    exit(0);
}

int id;

int main(){
    printf("Hello World!\n");

    id = fork();
    
    if (id == 0) P1();

    id = fork();

    if (id == 0) P2();

    P();
    wait(0);
    wait(0);

    printf("test\n");

    return 0;
}