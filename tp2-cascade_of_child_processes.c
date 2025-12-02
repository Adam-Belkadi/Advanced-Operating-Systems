#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int n=5;
int fac=1;

void PPere(){
    printf("Pere, PID is %d\n", getpid());
}

void PFils(int i){
    fac=fac*i;

    if(i<n) {
        int id;

        printf("fils %d, PID is %d, Mon pere %d\n", i, getpid(), getppid());
        printf("PID=%d, fac=%d\n",getpid(), fac, getppid());

        i=i+1;

        id = fork();
        if (id == 0) PFils(i);

        wait(0);

        exit(0);
    } else {
        printf("fils %d, PID is %d, Mon pere %d\n", i, getpid(), getppid());
        printf("PID=%d, fac=%d\n",getpid(), fac, getppid());
        exit(0);
    }

    
}

int main(){
    printf("Hello World!\n");

    int id;
    int i=1;


    id = fork();
    if (id == 0) PFils(i);


    PPere();
    wait(0);

    printf("test\n");

    return 0;
}