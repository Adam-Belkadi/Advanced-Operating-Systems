#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int id;
int n=10;

void P(){
    printf("Pere, PID is %d\n", getpid());
}

void petitFils(int j, int i){
    printf("petit fils %d, pere %d, PID is %d, PID pere %d\n",j ,i ,getpid(),getppid());

    exit(0);
}

void fils(int i){
    for(int j=1; j<=i; j++) {
        id = fork();
        if (id == 0) petitFils(j, i);
    }

    printf("fils %d, PID is %d, PID pere %d\n",i ,getpid(),getppid());

    for(int j=1; j<=i; j++) {
        wait(0);
    }

    exit(0);
}

int main(){
    printf("Hello World!\n");

    for(int i=1; i<=n; i++) {
        id = fork();
        if (id == 0) fils(i);

    }

    P();

    for(int i=1; i<=n; i++) {
        wait(0);
    }

    printf("test\n");

    return 0;
}