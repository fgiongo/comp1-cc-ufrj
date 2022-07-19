#include "defs.h"

int menu_principal(void)
{
    char *titulo = "\nMenu Principal\n\n";
    char *a = "(1) inserir condomínio\n";
    char *b = "(2) remover condomínio\n";
    char *c = "(3) inserir bloco\n";
    char *d = "(4) remover bloco(não disponível)\n";
    char *e = "(5) editar condominio(não disponível)\n";
    char *f = "(6) editar bloco(não disponível)\n";
    char *g = "(7) consultar condomínio por nome\n";
    char *h = "(8) listar todos os condomínios\n";
    char *i = "(9) salvar e sair\n";

    printf("%s%s%s%s%s%s%s%s%s%s\n", titulo, a, b, c, d, e, f, g, h, i);

    return get_int(1, 9, "Escolha opcao: ");
}

int inserir_condominio(condominio **lista)
{
    condominio *novo_condominio;
    int blocos, numero, *andares, *apts;
    char *nome, *endereco;

    nome = get_string(MAX_CHARS, "Nome do condominio: ");

    if (buscar_por_condominio(*lista, nome))
    {
        printf("\nCondomínio já existente! \n");
        return 0;
    }

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

static void salvar_blocos(bloco *lista_blocos, FILE *arquivo)
{
    while (lista_blocos != NULL)
    {
        fwrite(lista_blocos, sizeof(bloco), 1, arquivo);
        lista_blocos = lista_blocos->prox;
    }
}

void salvar_lista(condominio *lista_condominios, FILE *arquivo)
{
    while (lista_condominios != NULL)
    {
        fwrite(lista_condominios, sizeof(condominio), 1, arquivo);
        salvar_blocos(lista_condominios->lista_blocos, arquivo);
        lista_condominios = lista_condominios->prox;
    }
}

static bloco *ler_blocos(FILE *arquivo)
{
    bloco *lista_blocos, *novo_bloco;
    int eh_ultimo;

    lista_blocos = NULL;
    eh_ultimo = 0;
    do
    {
        novo_bloco = (bloco *) malloc(sizeof(bloco));
        if (novo_bloco == NULL && lista_blocos != NULL)
        {
            esvaziar_lista_blocos(&lista_blocos);
            return NULL;
        }

        fread(novo_bloco, sizeof(bloco), 1, arquivo);

        if (novo_bloco->prox == NULL) eh_ultimo++;

        lista_enc_inserir_bloco(novo_bloco, &lista_blocos);
    }
    while (!eh_ultimo);

    return lista_blocos;
}

condominio *ler_arquivo_salvo(FILE *arquivo)
{
    condominio *lista_cond, *novo_cond;
    bloco *lista_blocos;
    int eh_ultimo;

    lista_cond = NULL;
    lista_blocos = NULL;
    eh_ultimo = 0;

    if (feof(arquivo)) return NULL;

    do
    {
        novo_cond = (condominio *) malloc(sizeof(condominio));
        if (novo_cond == NULL && lista_cond != NULL)
        {
            esvaziar_lista_cond(&lista_cond);
            return NULL;
        }

        fread(novo_cond, sizeof(condominio), 1, arquivo);

        if (novo_cond->prox == NULL) eh_ultimo++;

        lista_blocos = ler_blocos(arquivo);
        novo_cond->lista_blocos = lista_blocos;
        
        lista_enc_inserir_condominio(novo_cond, &lista_cond);
    }
    while (!eh_ultimo);

    return lista_cond;
}

void consultar_por_condominio(condominio *lista)
{

    char *c = get_string(MAX_CHARS, "Condomínio a procurar: ");
    condominio *cond;

    cond = buscar_por_condominio(lista, c);

    if (cond == NULL)
    {
        printf("Não existe um condomínio com esse nome! \n");
    }else {

        imprimir_condominio(cond);
    }
}

static bloco *criar_bloco(void)
{
    int apt, andar;
    bloco *blocs;

    blocs = (bloco *)malloc(sizeof(bloco));

    if (blocs == NULL) return NULL;

    andar = get_int(1, MAX_ANDARES, "Número de andares: ");
    apt = get_int(1, MAX_APTS, "Número de Apts por andar: ");

    blocs->qtd_andares = andar;
    blocs->qtd_apts = apt;

    return blocs;

}

void inserir_bloco(condominio *lista)
{
    char *c;
    condominio *cond;
    bloco *b;

    c = get_string(MAX_CHARS, "Selecione o condominio \n Nome: ");

    cond = buscar_por_condominio(lista, c);

    if (cond == NULL)
    {
        printf("\nCondominio não encontrado!\n");
        return;
    }

    if (contar_blocos(cond->lista_blocos) >= MAX_ALPHA)
    {
        printf("\nCondomínio com máxima ocupação de blocos \n");
        return;
    }

    b = criar_bloco();

    lista_enc_inserir_bloco(b, &(cond->lista_blocos));

    renomear_blocos(cond->lista_blocos);

    printf("\nBloco inserido com sucesso!\n");
}

void remover_bloco(condominio *lista)
{
    char *s, c;
    condominio *cond;
    bloco *b;

    s = get_string(MAX_CHARS, "Selecione o condominio \n Nome: ");

    cond = buscar_por_condominio(lista, s);

    if (cond == NULL)
    {
        printf("\nCondominio não encontrado!\n");
        return;
    }

    imprimir_condominio(cond);

    c = get_char("Selecione bloco a ser removido: ");
    b = buscar_bloco_por_letra(c, lista->lista_blocos);

    if (b == NULL)
    {
        printf("\nBloco não encontrado!\n");
        return;
    }

    /* criar funcao para remover bloco do meio da lista */
}
