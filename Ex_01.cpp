#include <stdio.h>
#include <stdlib.h>

// defini��o da estrutura de pilha
typedef struct pilha {
    int topo;
    int capacidade;
    int* elementos;
} Pilha;

// cria��o de uma pilha vazia
Pilha* cria_pilha(int capacidade) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = -1;
    p->capacidade = capacidade;
    p->elementos = (int*) malloc(capacidade * sizeof(int));
    return p;
}

// empilha um elemento na pilha
void empilha(Pilha* p, int valor) {
    if (p->topo == p->capacidade - 1) {
        printf("Erro: a pilha est� cheia\n");
        return;
    }
    p->topo++;
    p->elementos[p->topo] = valor;
}

// desempilha um elemento da pilha
int desempilha(Pilha* p) {
    if (p->topo == -1) {
        printf("Erro: a pilha est� vazia\n");
        return -1;
    }
    int valor = p->elementos[p->topo];
    p->topo--;
    return valor;
}

// verifica se um n�mero � par
int Par(int x) {
    return x % 2 == 0;
}

int main() {
    // cria��o das pilhas
    Pilha* S1 = cria_pilha(10);
    Pilha* S2 = cria_pilha(10);

    // preenchimento da pilha S1
    for (int X = 12; X <= 19; X++) {
        empilha(S1, X);
    }

    // processamento dos elementos da pilha S1
    printf("Passo dois\n");
    while (S1->topo != -1) {
        int x = desempilha(S1);
        if (Par(x)) {
            empilha(S2, x);
        }
    }

    // impress�o das pilhas S1 e S2
    printf("Pilha S1:\n");
    for (int i = 0; i <= S1->topo; i++) {
        printf("%d ", S1->elementos[i]);
    }
    printf("\n");

    printf("Pilha S2:\n");
    for (int i = 0; i <= S2->topo; i++) {
        printf("%d ", S2->elementos[i]);
    }
    printf("\n");

    // libera��o da mem�ria das pilhas
    free(S1->elementos);
    free(S1);
    free(S2->elementos);
    free(S2);

    return 0;
}

