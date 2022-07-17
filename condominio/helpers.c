#include "defs.h"

void imprimir_condominio(condominio *cond)
{
    bloco *ptr_bloco;

    printf("Dados sobre condomínio %s:\n\n", cond->nome);
    printf("Endereço: %s, %d\n",
            cond->endereco_condominio.rua,
            cond->endereco_condominio.num);

    ptr_bloco = cond->lista_blocos;
    while (ptr_bloco != NULL)
    {
        printf("Bloco %c:\n", ptr_bloco->letra);
        printf("%d andares\n", ptr_bloco->qtd_andares);
        printf("%d apartamentos por andar\n", ptr_bloco->qtd_apts);
        ptr_bloco = ptr_bloco->prox;
    }
}

void imprimir_lista_condominial(condominio *lista_cond)
{
    while (lista_cond != NULL)
    {
        imprimir_condominio(lista_cond);
        lista_cond = lista_cond->prox;
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

int *criar_vetor_andares(int num_blocos)
{
    int *vetor_andares, i;
    vetor_andares = (int *)malloc(sizeof(int) * num_blocos);

    for (i = 0; i < num_blocos; i++)
    {
        printf("Bloco %d:\n", i + 1);
        vetor_andares[i] = get_int(1, MAX_ANDARES, "Numero de andares: ");
    }
    
    return vetor_andares;
}

int *criar_vetor_apts(int num_blocos)
{
    int *vetor_apts, i;
    vetor_apts = (int *)malloc(sizeof(int) * num_blocos);

    for (i = 0; i < num_blocos; i++)
    {
        printf("Bloco %d:\n", i + 1);
        vetor_apts[i] = get_int(1, MAX_APTS, "Numero de apartamentos por andar: ");
    }
    
    return vetor_apts;
}
