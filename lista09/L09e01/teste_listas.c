#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _LISTA_NOMES
{
    struct _LISTA_NOMES *prox;
    int i;
} lista_nomes;

void linked_list_insert(void **new_node, void **list, int node_size)
{
    /* !!!caution!!!
     * function relies on pointer to next node being AT START of node! */

    void *temp;
    unsigned char **ptr_next;

    temp = *list;
    *list = *new_node;

    ptr_next = *new_node;
    *ptr_next = temp;
}

void *linked_list_remove(void **list)
{
    /* !!! caution !!!
     * function relies on pointer to next node being AT START of node! */

    void *temp, **next;

    temp = *list;
    next = *list;
    *list = *next;

    return temp;
}

int main(void)
{
    lista_nomes *grupo_de_comp = NULL;
    lista_nomes *novo_nome;
    int j;

    for (j = 0; j < 20; j++)
    {
        novo_nome = (lista_nomes *) malloc(sizeof(lista_nomes));
        if (novo_nome == NULL)
        {
            printf("Sem memória.\n");
            return 1;
        }

        novo_nome -> i = j + 1;
        linked_list_insert((void *) &novo_nome, (void *) &grupo_de_comp, sizeof(lista_nomes));
    }

    novo_nome = grupo_de_comp;
    while (novo_nome != NULL)
    {
        printf("%d\n", novo_nome -> i);
        novo_nome = novo_nome -> prox;
    }

    for (j = 0; j < 5; j++)
    {
        free(linked_list_remove((void *) &grupo_de_comp));
    }

    novo_nome = grupo_de_comp;
    while (novo_nome != NULL)
    {
        printf("%d\n", novo_nome -> i);
        novo_nome = novo_nome -> prox;
    }

    return 0;

}