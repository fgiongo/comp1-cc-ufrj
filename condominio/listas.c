#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int lista_enc_inserir_bloco(bloco *c, bloco **lista)
{
    bloco *tmp;

    if (c == NULL) return 0;

    tmp = *lista;
    *lista = c;
    c->prox = tmp;

    return 1;
}

bloco *lista_enc_remover_bloco(bloco **lista)
{
    bloco *tmp;

    tmp = *lista;

    if (*lista != NULL)
    {
        *lista = (*lista)->prox;
        tmp->prox = NULL;
    }

    return tmp;
}

void esvaziar_lista_blocos(bloco **lista_blocos)
{
    while (*lista_blocos->prox != NULL)
        free(lista_enc_remover_bloco(lista_blocos));
}

int lista_enc_inserir_condominio(condominio *c, condominio **lista)
{
    condominio *tmp;

    if (c == NULL) return 0;

    tmp = *lista;
    *lista = c;
    c->prox = tmp;

    return 1;
}

condominio *lista_enc_remover_condominio(condominio **lista)
{
    condominio *tmp;

    tmp = *lista;

    if (*lista != NULL)
    {
        *lista = (*lista)->prox;
        tmp->prox = NULL;
    }

    return tmp;
}

void esvaziar_lista_cond(condominio **lista_cond)
{
    while (*lista_cond->prox != NULL)
        free(lista_enc_remover_condominio(lista_cond));
}
