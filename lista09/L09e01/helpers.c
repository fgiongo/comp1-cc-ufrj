/* helpers.c */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "defs.h"
#include "utils.h"
#include "helpers.h"

contato *ler_contatos(FILE *arquivo)
{
    return NULL;
}

int menu_principal(void)
{
    char *titulo = "\nMenu Principal\n\n";
    char *a = "(1) inserir contato\n";
    char *b = "(2) remover contato\n";
    char *c = "(3) pesquisar contato por nome\n";
    char *d = "(4) listar todos os contatos\n";
    char *e = "(5) listar contatos cujo nome inicia com dada letra\n";
    char *f = "(6) imprimir aniversariantes do mes\n";
    char *g = "(7) sair\n";

    printf("%s%s%s%s%s%s%s%s\n", titulo, a, b, c, d, e, f, g);

    return get_int(1, 7, "Escolha opcao: ");
}

contato *pesquisar_letra(char c, contato **lista)
{
    contato *lista_temp, *lista_match, *removido;

    while ((removido = lista_enc_remover(lista)) != NULL)
    {
        if (removido->nome[0] == c)
            lista_enc_inserir(removido, &lista_match);
        else lista_enc_inserir(removido, &lista_temp);
    }

    printf("Lista temporaria construida\n");
    
    while ((removido = lista_enc_remover(&lista_temp)) != NULL)
        lista_enc_inserir(removido, lista);

    printf("Lista principal reconstruida\n");

    return lista_match;
}

int listar_contatos(contato *lista)
{
    
    if (lista == NULL) return 0;

    printf("\nLista de contatos:\n\n");

    while (lista != NULL)
    {
        imprimir_contato(lista);
        printf("\n");
        lista = lista->prox;
    }

    return 1;
}

contato *pesquisar_nome(char *a_pesquisar, contato **lista)
{
    contato *contato_removido, *match, *lista_temp;
    int contato_inserido, nomes_diferentes;

    lista_temp = NULL;
    nomes_diferentes = 1;

    do
    {
        contato_removido = lista_enc_remover(lista);

        contato_inserido = lista_enc_inserir(contato_removido, &lista_temp);

        if (lista_temp != NULL)
            nomes_diferentes = strcmp(a_pesquisar, lista_temp->nome);
    }
    while (contato_inserido && nomes_diferentes);

    if(!nomes_diferentes) match = lista_temp;
    else match = NULL;
  
    while(lista_temp != NULL)
    {
        lista_enc_inserir(lista_enc_remover(&lista_temp), lista);
    }
    
    return match;
}

int remover_contato(char *a_remover, contato **lista)
{
    contato *contato_removido, *lista_temp;
    int contato_inserido, nomes_diferentes;

    nomes_diferentes = 1;
    lista_temp = NULL;

    do
    {
        contato_removido = lista_enc_remover(lista);

        contato_inserido = lista_enc_inserir(contato_removido, &lista_temp);

        if (lista_temp != NULL)
            nomes_diferentes = strcmp(a_remover, lista_temp->nome);

    } while (contato_inserido && nomes_diferentes);

    if (!nomes_diferentes)
    {
        free(lista_enc_remover(&lista_temp));
    }
    else return 0;

    while(lista_temp != NULL)
    {
        lista_enc_inserir(lista_enc_remover(&lista_temp), lista);
    }

    return 1;
}

void inserir_contato(contato **lista)
{
    contato *novo = malloc(sizeof(contato));
    char *nome;

    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    nome = get_string(MAX_CHARS, "Nome: ");
    strcpy(novo->nome, nome);

    novo->telefone = get_long(0, LONG_MAX, "Telefone (sem espaços ou outros símbolos): ");
    novo->data_de_nascimento.ano = get_int(0, INT_MAX, "Ano de nascimento: ");
    novo->data_de_nascimento.mes = get_int(0, INT_MAX, "Mês de nascimento: ");
    novo->data_de_nascimento.dia = get_int(0, INT_MAX, "Dia de nascimento: ");
    novo->prox = NULL;

    lista_enc_inserir(novo, lista);
}

void imprime_aniversariantes(void)
{
}

int imprimir_contato(contato *contato)
{
    if (contato == NULL) return 0;
    
    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %li\n", contato->telefone);
    printf("Data de nascimento: %d/%d/%d\n",
            contato->data_de_nascimento.dia,
            contato->data_de_nascimento.mes,
            contato->data_de_nascimento.ano);

    return 1;
}

int linked_link_inserir(contato *node, contato **lista)
{
    contato *temp;

    if (node->prox == NULL) return 0;

    temp = *lista;
    *lista = node;
    node->prox = temp;

    return 1;
}

contato *lista_enc_remover(contato **lista)
{
    contato *temp;

    temp = *lista;
    *lista = (*lista)->prox;
    temp->prox = NULL;

    return temp;
}
