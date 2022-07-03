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
    lista_temp = lista_match = NULL;

    while ((removido = lista_enc_remover(lista)) != NULL)
    {
        if (removido->nome[0] == c)
            lista_enc_inserir(removido, &lista_match);
        else lista_enc_inserir(removido, &lista_temp);
    }

    while ((removido = lista_enc_remover(&lista_temp)) != NULL)
    {
        lista_enc_inserir(removido, lista);
    }

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
    char *nome_novo;

    if (novo == NULL)
    {
        printf("Memória insuficiente.\n");
        exit(1);
    }

    nome_novo = get_string(MAX_CHARS, "Nome: ");
    strcpy(novo->nome, nome_novo);
    free(nome_novo);

    novo->telefone = get_long(0, LONG_MAX, "Telefone (sem espaços ou outros símbolos): ");
    novo->data_de_nascimento.ano = get_int(0, INT_MAX, "Ano de nascimento: ");
    novo->data_de_nascimento.mes = get_int(0, INT_MAX, "Mês de nascimento: ");
    novo->data_de_nascimento.dia = get_int(0, INT_MAX, "Dia de nascimento: ");
    novo->prox = NULL;

    lista_enc_inserir(novo, lista);
}

void imprime_aniversariantes(contato *lista, int mes)
{
    int imprimiu_contato = 0;
    while (lista != NULL)
    {
        if ((lista->data_de_nascimento.mes) == mes)
        {
            printf("\n");
            imprimir_contato(lista);
            imprimiu_contato = 1;
        }

        lista = lista->prox;
    }
    if (!imprimiu_contato) printf("\nNão existem contatos com aniversário no mês %d\n", mes);
}

int imprimir_contato(contato *c)
{
    if (c == NULL) return 0;
    
    printf("Nome: %s\n", c->nome);
    printf("Telefone: %li\n", c->telefone);
    printf("Data de nascimento: %d/%d/%d\n",
            c->data_de_nascimento.dia,
            c->data_de_nascimento.mes,
            c->data_de_nascimento.ano);

    return 1;
}

int lista_enc_inserir(contato *c, contato **lista)
{
    contato *tmp;

    if (c == NULL) return 0;

    tmp = *lista;
    *lista = c;
    c->prox = tmp;

    return 1;
}

contato *lista_enc_remover(contato **lista)
{
    contato *tmp;

    tmp = *lista;

    if (*lista != NULL)
    {
        *lista = (*lista)->prox;
        tmp->prox = NULL;
    }

    return tmp;
}
