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

Lista buscarOcc(Lista a, int alvo)
{
    Lista aux = a;

    while (aux != NULL)
    {
        if (aux->data == alvo)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}
Lista removeOcc(Lista a, int alvo)
{
    Lista ant = NULL;
    Lista aux = a;

    while (aux != NULL)
    {
        if (aux->data == alvo)
        {
            if (ant == NULL)
                a = aux->prox;
            else
                ant->prox = aux->prox;
            printf("limpando memoria com conteudo: %d\n", alvo);
            free(aux);
            return a;
        }
        ant = aux;
        aux = aux->prox;
    }
    return a;
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

int main()
{
    Lista l;
    l = criar_lista();
    int a,b,c,d;

    printf("Digite um valor para adicionar na lista: ");
    scanf("%d", &a);
    printf("Digite outro valor para adicionar na lista: ");
    scanf("%d", &b);
    printf("Digite outro valor para adicionar na lista: ");
    scanf("%d", &c);
    adicionar_elemento(&l, a);
    adicionar_elemento(&l, b);
    adicionar_elemento(&l, c);


    printf("--------------------\nDigite qual elemento deseja remover a primeira ocorrencia na lista: ");
    scanf("%d", &d);

    l = removeOcc(l, d);
    printf("--------------------\nNova lista: ");
    imprimir(l);

    destroi_lista(l);

    return 0;
}
