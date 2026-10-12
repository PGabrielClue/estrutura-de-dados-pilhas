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

int vazia(Pilha *P) {
    return P->topo == -1;
}

int balanceada(char exp[]) {
    Pilha P;
    P.topo = -1;

    for (int i = 0; exp[i] != '\0'; i++) {

        if (exp[i] == '(' ||
            exp[i] == '[' ||
            exp[i] == '{') {

            empilha(&P, exp[i]);
        }

        else if (exp[i] == ')' ||
                 exp[i] == ']' ||
                 exp[i] == '}') {

            if (vazia(&P))
                return 0;

            char abre = desempilha(&P);

            if (exp[i] == ')' && abre != '(')
                return 0;

            if (exp[i] == ']' && abre != '[')
                return 0;

            if (exp[i] == '}' && abre != '{')
                return 0;
        }
    }

    return vazia(&P);
}

int main(void) {
    char exp[MAX];

    printf("Digite a expressao: ");
    fgets(exp, MAX, stdin);

    if (balanceada(exp))
        printf("Expressao balanceada!\n");
    else
        printf("Expressao nao balanceada!\n");

    return 0;
}
