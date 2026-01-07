#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



// genere (expression, i, pere);
// {
// j:= operateur_central (expression);
// generer_numero_tache (i);
// s_exG:=s_expression_G(expression, j);
// x=calculer_nbop (s_exG);
// Si existe (s_exG) Alors genere(s_exG, i+1, i) Fsi;
// s_exD:=s_expression_D(expression, j);
// Si existe (s_exD) Alors genere(s_exD, i+x+1, i) Fsi;
// generer_contenu_tache (expression, i, x, j);
// generer_precedence (i, pere)
// }
// main()
// { Lire (E);
// genere (E, 1, -1); /* E est l’expression entière; 1 veut dire que la fonction
// travaillera sur la tache N° 1); -1 signifie qu’il s’agit du premier appel de genere
// () */
// }
void substring(const char *src, char *dest, int debut, int fin) {
    int j = 0;

    if (debut < 0 || fin < debut) {
        dest[0] = '\0';
        return;
    }

    for (int i = debut; i <= fin && src[i] != '\0'; i++) {
        dest[j++] = src[i];
    }

    dest[j] = '\0'; // null-terminate
}

int generer_operateur_central(char* e){
    int cpt=0;
    int i=1;

    do{
        if(e[i]=='(') cpt++;
        else if(e[i]==')') cpt--;
        i++;
    } while(cpt != 0);

    return i;
}

int generer_numero_tache(int neoud){
    printf("T[%d]\n", neoud);
}

int generer_contenu_tache(char* e, int neoud, int x, int j){
    if(e[j-1] == '(' && e[j+1] == ')') printf("T[%d]: M[%d] %c M[%d]\n", neoud, neoud, e[j], neoud+x+1); 
    else if(e[j-1] == '(' && e[j+1] != ')') printf("T[%d]: M[%d] %c %c\n", neoud, neoud, e[j], e[j+1]); 
    else if(e[j-1] != '(' && e[j+1] == ')') printf("T[%d]: %c %c M[%d]\n", neoud, e[j-1], e[j], neoud+1); 
    else printf("T[%d]: %c %c %c\n", neoud, e[j-1], e[j], e[j+1]);
}

int generer_precedence(int neoud, int pere){

}

int calculer_nbop(char* s_gauche){
    int cpt=0;
    int i=0;

    do{
        if(s_gauche[i]=='+' || s_gauche[i]=='/' || s_gauche[i]=='*' || s_gauche[i]=='-') cpt++;
        i++;
    } while(s_gauche[i] != '\0');

    return cpt;
}

void genere(char* e,int neoud,int pere){
    printf("Je suis genere!\n");
    int j,x;

    j=(generer_operateur_central(e));
    printf("indice op central=%d, op=%c\n", j, e[j]);\

    generer_numero_tache(neoud);

    char s_gauche[100];
    substring(e, s_gauche, 1, j-1);
    printf("s_gauche: %s\n", s_gauche);

    char s_droite[100];
    substring(e, s_droite, j+1, strlen(e)-2);
    printf("s_gauche: %s\n", s_droite);

    printf("Nombre op=%d\n", calculer_nbop(s_gauche));
}


int main(){

    char *e = "((A+B)*(C-(D/E)))";
    genere(e, 1, -1);

    return 0;
}