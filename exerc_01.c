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

int main()
{
    Lista l;
    l = criar_lista();

    int a;
    printf("Digite um valor para adicionar na lista: ");
    scanf("%d", &a);
    adicionar_elemento(&l, a);

    destroi_lista(l); // verifiquei com "Dr.Memory"
    return 0;
}
