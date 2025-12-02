#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int id;
int n=100;
FILE *fp;
FILE *fp1;
FILE *fp2;

void RemplireF(){
    fp = fopen("numbers.txt", "w");

    for (int i = 1; i <= n; i++) {
        fprintf(fp, "%d\n", i);
        printf("%d ", i);
    }
    printf("\n");
    printf("\n");

    fclose(fp);
}

void Generer_impair(){
    fp = fopen("numbers.txt", "r");
    fp1 = fopen("numbers_impair.txt", "w");

    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        if(num % 2 == 1){
            fprintf(fp1, "%d ", num);
        }
    }
    
    fclose(fp);
    fclose(fp1);
    exit(0);
}

void Generer_pair(){
    fp = fopen("numbers.txt", "r");
    fp2 = fopen("numbers_pair.txt", "w");

    int num;
    while (fscanf(fp, "%d", &num) == 1) {
        if(num % 2 == 0){
            fprintf(fp2, "%d ", num);
        }
    }
    
    fclose(fp);
    fclose(fp2);
    exit(0);
}

void Afficher_impair(){
    fp1 = fopen("numbers_impair.txt", "r");

    int num;
    while (fscanf(fp1, "%d", &num) == 1) {
        printf("p3: %d \n", num);
        sleep(3);
    }
    printf("\n");
    printf("\n");
    
    fclose(fp1);
    exit(0);
}

void Afficher_pair(){
    fp2 = fopen("numbers_pair.txt", "r");

    int num;
    while (fscanf(fp2, "%d", &num) == 1) {
        printf("p4: %d \n", num);
        sleep(2);
    }
    printf("\n");
    printf("\n");
    
    fclose(fp2);
    exit(0);
}

int main(){
    printf("Hello World!\n");

    RemplireF();

    id = fork();
    if (id == 0) Generer_impair();

    id = fork();
    if (id == 0) Generer_pair();

    wait(0);
    wait(0);

    id = fork();
    if (id == 0) Afficher_impair();

    id = fork();
    if (id == 0) Afficher_pair();

    wait(0);
    wait(0);

    printf("travail termine\n");

    return 0;
}