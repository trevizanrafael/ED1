#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int info;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

Pilha* cria() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha *p, int v) {
    No *novo = (No*)malloc(sizeof(No));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p) {
    if (p->topo == NULL) {
        printf("Pilha vazia!\n");
        return -1;
    }
    No *aux = p->topo;
    int v = aux->info;
    p->topo = aux->prox;
    free(aux);
    return v;
}

int vazia(Pilha *p) {
    return (p->topo == NULL);
}

void libera(Pilha *p) {
    while (!vazia(p)) {
        pop(p);
    }
    free(p);
}

void decimal_para_binario(int n) {
    Pilha *p = cria();
    if (n == 0) {
        printf("0");
        libera(p);
        return;
    }
    while (n > 0) {
        push(p, n % 2);
        n = n / 2;
    }
    while (!vazia(p)) {
        printf("%d", pop(p));
    }
    libera(p);
}

int main() {
    int numero;
    printf("Digite um numero decimal: ");
    scanf("%d", &numero);
    printf("Binario: ");
    decimal_para_binario(numero);
    printf("\n");
    return 0;
}
