#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct No {
    char info;
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


void push(Pilha *p, char v) {
    No *novo = (No*)malloc(sizeof(No));
    novo->info = v;
    novo->prox = p->topo;
    p->topo = novo;
}


char pop(Pilha *p) {
    if (p->topo == NULL) {
        return '\0';
    }
    No *aux = p->topo;
    char v = aux->info;
    p->topo = aux->prox;
    free(aux);
    return v;
}


void libera(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
    free(p);
}


void inverte_string(char *str) {
    Pilha *p = cria();
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        push(p, str[i]);
    }
    i = 0;
    while (p->topo != NULL) {
        str[i++] = pop(p);
    }
    str[i] = '\0';
    libera(p);
}

int main() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);


    str[strcspn(str, "\n")] = '\0';

    inverte_string(str);
    printf("String invertida: %s\n", str);
    return 0;
}
