#include <stdin.h>
#include "defs.h"

void imprimir_dados(condominio *cond)
{
    printf("Dados sobre condomínio %s:\n\n", cond->nome);
    printf("Endereço: %s, %d\n", cond->endereco->rua, cond->endereco->num);

    while (cond->bloco != NULL)
    {
        printf("Bloco %c:\n", cond->bloco->letra);
        printf("%d andares\n", cond->bloco.qtd_andares);
        printf("%d apartamentos por andar\n", cond->bloco.qtd_apts);
    }
}

condominio *novo_condominio(char *nome, char *rua, int num_rua, int qtd_blocos, int *input_qtd_andares,
int *input_qtd_apts)
{
    int i;
    char c = 'A';

    bloco *lista_blocos, *bloco_novo;
    condominio *cond_novo;

    cond_novo = (condominio *) malloc(sizeof(condominio));
    if (cond_novo == NULL) return NULL;

    for (i = 0; i < qtd_blocos, i++)
    {
        bloco_novo = (bloco *)malloc(sizeof(bloco));
        if (bloco_novo == NULL) return NULL;

        bloco_novo->letra = c;
        bloco_novo->qtd_andares = input_qtd_andares;
        bloco_novo->qtd_apts = input_qtd_apts;
        bloco_novo->prox = NULL;
        c++;


        if (!(lista_enc_inserir_bloco(bloco_novo, &lista_blocos)))
        {
            while(bloco_novo != NULL)
            {
                free(lista_enc_remover_bloco(&bloco_novo));
            }
            return NULL;
        } 
    }

    cond_novo->bloco = lista_blocos;

    strcpy(cond_novo.nome, nome);

    return cond_novo;

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

