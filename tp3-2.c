#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int id;
int n=10;

void P(){
    printf("Pere, PID is %d\n", getpid());

    FILE *fp = fopen("numbers.txt", "w");

    for (int i = 1; i <= n; i++) {
        fprintf(fp, "%d\n", i);
        fclose(fp);
    }
}

void fils_read(int i){
    printf("fils %d, PID is %d, PID pere %d\n",i ,getpid(),getppid());

    FILE *fp = fopen("numbers.txt", "r");

    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        printf("%d\n", num);
    }

    fclose(fp);

    exit(0);
}

int main(){
    printf("Hello World!\n");

    P();

    for(int i=1; i<=2; i++) {
        id = fork();
        if (id == 0) fils(i);
    }

    for(int i=1; i<=2; i++) {
        wait(0);
    }

    printf("test\n");

    return 0;
}