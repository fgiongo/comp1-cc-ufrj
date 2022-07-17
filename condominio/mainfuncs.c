#include "defs.h"

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

int inserir_condominio(condominio **lista)
{
    condominio *novo_condominio;
    int blocos, numero, *andares, *apts;
    char *nome, *endereco;

    nome = get_string(MAX_CHARS, "Nome do condominio: ");
    endereco = get_string(MAX_CHARS, "Endereço (Rua): ");
    numero = get_int(1, INT_MAX, "Endereço (Numero): ");
    blocos = get_int(1, INT_MAX, "Numero de blocos: ");

    andares = criar_vetor_andares(blocos);
    if (!andares) return 0;

    apts = criar_vetor_apts(blocos);
    if (!apts)
    {
        free(andares);
        return 0;
    }

    novo_condominio = criar_novo_condominio(
            nome,
            endereco,
            numero,
            blocos,
            andares,
            apts);

    free(andares);
    free(apts);

    if (!novo_condominio) return 0;

    lista_enc_inserir_condominio(
            novo_condominio,
            lista);

    return 1;
}

void remover_condominio(condominio **lista)
{
    if (remover_cond_por_nome(
                get_string(MAX_CHARS, "\nRemover condominio\nNome: "),
                lista))
    {
        printf("\nCondominio removido com sucesso.\n");
    }
    else printf("\nCondominio nao encontrado\n");
}

void imprimir_lista_condominial(condominio *lista)
{
    while (lista != NULL)
    {
        imprimir_condominio(lista);
        lista = lista->prox;
    }
}
