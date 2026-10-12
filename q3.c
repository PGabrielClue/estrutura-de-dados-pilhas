#include <stdio.h>
#include <string.h>

#define MAX 200

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void empilha(Pilha *P, char x) {
    P->topo++;
    P->itens[P->topo] = x;
}

char desempilha(Pilha *P) {
    char x = P->itens[P->topo];
    P->topo--;
    return x;
}

int main(void) {
    char frase[MAX];
    Pilha P;

    P.topo = -1;

    printf("Digite uma frase: ");
    fgets(frase, MAX, stdin);

    for (int i = 0; frase[i] != '\0'; i++) {

        if (frase[i] != ' ' && frase[i] != '\n') {
            empilha(&P, frase[i]);
        }
        else {
            while (P.topo != -1) {
                printf("%c", desempilha(&P));
            }

            if (frase[i] == ' ')
                printf(" ");
        }
    }

    // caso a frase termine sem \n
    while (P.topo != -1) {
        printf("%c", desempilha(&P));
    }

    return 0;
}
