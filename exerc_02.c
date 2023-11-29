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

Lista buscar(Lista a, int alvo)
{
    if (a != NULL)
    {
        if (a->data == alvo)
        {
            printf("Elemento encontrado!");
            return a;
        }
        else
            return buscar(a->prox, alvo);
    }
    else
        return NULL;
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

    printf("--------------------\nDigite qual elemento deseja buscar na lista: ");
    scanf("%d", &d);
    buscar(l, d);

    destroi_lista(l);

    return 0;
}
