#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "defs.h"
#include "utils.h"
#include "helpers.h"

void imprimir_dados(condominio *cond)
{
    printf("Dados sobre condomínio %s:\n\n", cond->nome);
    printf("Endereço: %s, %d\n",
            cond->endereco_condominio.rua,
            cond->endereco_condominio.num);

    while (cond->lista_blocos != NULL)
    {
        printf("Bloco %c:\n", cond->lista_blocos->letra);
        printf("%d andares\n", cond->lista_blocos->qtd_andares);
        printf("%d apartamentos por andar\n", cond->lista_blocos->qtd_apts);
    }
}

condominio *criar_novo_condominio(
        char *nome,
        char *rua,
        int num_rua,
        int qtd_blocos,
        int *qtd_andares,
        int *qtd_apts)
{
    int i;
    char c;

    bloco *nova_lista_blocos, *novo_bloco;
    condominio *novo_cond;

    novo_cond = (condominio *) malloc(sizeof(condominio));
    if (novo_cond == NULL) return NULL;

    nova_lista_blocos = NULL;
    for (i = 0, c = 'A'; i < qtd_blocos; i++)
    {
        novo_bloco = criar_novo_bloco(
                (char) c + i,
                qtd_andares[i],
                qtd_apts[i]);

        if (!(lista_enc_inserir_bloco(novo_bloco, &nova_lista_blocos))) 
        {
            esvaziar_lista_blocos(&nova_lista_blocos);
            free(novo_cond);
            return NULL;
        }
    }

    novo_cond->lista_blocos = nova_lista_blocos;

    strcpy(novo_cond->nome, nome);
    strcpy(novo_cond->endereco_condominio.rua, rua);
    novo_cond->endereco_condominio.num = num_rua;
    novo_cond->prox = NULL;

    return novo_cond;
}

bloco *criar_novo_bloco(char letra, int qtd_andares, int qtd_apts)
{
    bloco *novo_bloco;
    novo_bloco = (bloco *) malloc(sizeof(bloco));
    if (novo_bloco == NULL) return NULL;

    novo_bloco->letra = letra;
    novo_bloco->qtd_andares = qtd_andares;
    novo_bloco->qtd_apts = qtd_apts;
    novo_bloco->prox = NULL;

    return novo_bloco;
}

int menu_principal(void)
{
    char *titulo = "\nMenu Principal\n\n";
    char *a = "(1) inserir condomínio\n";
    char *b = "(2) remover condomínio\n";
    char *c = "(3) inserir bloco\n";
    char *d = "(4) remover bloco\n";
    char *e = "(5) editar condominio\n";
    char *f = "(6) editar bloco\n";
    char *g = "(7) consultar condomínio\n";
    char *h = "(8) listar condomínios\n";
    char *i = "(9) sair\n";

    printf("%s%s%s%s%s%s%s%s%s%s\n", titulo, a, b, c, d, e, f, g, h, i);

    return get_int(1, 9, "Escolha opcao: ");
}

