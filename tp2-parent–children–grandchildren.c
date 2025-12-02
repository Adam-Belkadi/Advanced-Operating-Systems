#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void PPere(){
    printf("Pere, PID is %d\n", getpid());
}

void PetitFils(int i,int j){
    printf("petit fils %d, pere is %d, PID is %d, Mon pere %d\n", j, i, getpid(), getppid());

    exit(0);
}

void Fils(int i){
    int id;

    for (int j=1; j<=i; j++){
        id = fork();
        if (id == 0) PetitFils(i, j);
    }

    printf("fils %d, PID is %d\n", i, getpid());

    for (int j=1; j<=i; j++){
        wait(0);
    }

    exit(0);
}



int main(){
    printf("Hello World!\n");

    int id;
    int n=5;

    for (int i=1; i<=n; i++){
        id = fork();
        if (id == 0) Fils(i);
    }

    PPere();
    for (int i=1; i<=n; i++){
        wait(0);
    }

    printf("test\n");

    return 0;
}