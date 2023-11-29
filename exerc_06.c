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
        return NULL;

    else
    {
        printf("%d ", aux->data);
        return imprimir(a->prox);
    }
}

void insert(Lista *l, int x)
{
    Lista novo = malloc(sizeof(struct no));
    novo->data = x;
    novo->prox = NULL;

    if (*l == NULL)
        *l = novo;

    else
    {
        Lista aux = *l;

        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

int main()
{
    Lista l;
    l = criar_lista();
    int a;

    adicionar_elemento(&l, 1);
    adicionar_elemento(&l, 2);
    adicionar_elemento(&l, 3);

    printf("--------------------\nLista: ");
    imprimir(l);

    printf("\nDigite o numero de valores que deseja inserir na lista: ");
    scanf("%d", &a);
    while (a != 0)
    {
        int b;
        printf("\nInsira um valor para adicionar na lista: ");
        scanf("%d", &b);
        insert(&l, b);
        a -= 1;
    }

    printf("--------------------\nNova lista: ");

    imprimir(l);

    destroi_lista(l);

    return 0;
}
