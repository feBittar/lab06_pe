#include <stdio.h>
#include <stdlib.h>

// FELIPE BITTAR MARTINIANO
// 11202130044

typedef struct no *Lista;

struct no
{
    int data;
    Lista prox;
};

Lista criar_lista()
{
    return NULL;
}

void adicionar_elemento(Lista *l, int x)
{
    Lista novo;
    novo = malloc(sizeof(struct no));
    novo->data = x;
    novo->prox = *l;
    *l = novo;
}

void destroi_lista(Lista a)
{
    if (a == NULL)
        return;

    Lista aux = a;

    while (aux != NULL)
    {
        Lista temp = aux->prox;
        free(aux);
        aux = temp;
    }
    return;
}

Lista imprimir(Lista a)
{
    Lista aux = a;

    if (aux == NULL)
    {
        printf("\n");
        return NULL;
    }

    else
    {
        printf("%d ", aux->data);
        return imprimir(a->prox);
    }
}

Lista inverte(Lista a)
{
    Lista ant = NULL;
    Lista aux = a;
    while (aux != NULL)
    {
        Lista prox = aux->prox;
        aux->prox = ant; // troca qual o valor que vem depois
        ant = aux;       // troca qual o valor que vem anteriormente
        aux = prox;      // troca o proprio valor
    }
    a = ant;
    return a;
}

int main()
{
    Lista l1;
    l1 = criar_lista();

    int a;
    printf("\nDigite o numero de valores que deseja inserir na lista: ");
    scanf("%d", &a);
    while (a != 0)
    {
        int b;
        printf("\nInsira um valor para adicionar na lista: ");
        scanf("%d", &b);
        adicionar_elemento(&l1, b);
        a -= 1;
    }

    printf("Lista: ");
    imprimir(l1);

    l1 = inverte(l1);

    printf("---------------------\nLista inversa: ");
    imprimir(l1);

    destroi_lista(l1);

    return 0;
}
