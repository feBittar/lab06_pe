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

Lista conc(Lista a, Lista b)
{
    if (a == NULL)
        return b;
    else
    {
        Lista aux = a;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = b;
        return a;
    }
}

int main()
{
    Lista l1, l2, l3;
    l1 = criar_lista();
    l2 = criar_lista();

    adicionar_elemento(&l2, 1);
    adicionar_elemento(&l1, 1);
    adicionar_elemento(&l2, 2);
    adicionar_elemento(&l1, 2);
    adicionar_elemento(&l2, 3);
    adicionar_elemento(&l1, 3);

    printf("Lista 1: ");
    imprimir(l1);
    printf("--------------------\nLista 2: ");
    imprimir(l2);

    l3 = conc(l1, l2);
    printf("--------------------\nNova lista: ");

    imprimir(l3);

    destroi_lista(l1);
    destroi_lista(l2);
    destroi_lista(l3);

    return 0;
}
