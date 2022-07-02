/* helpers.c */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "defs.h"
#include "utils.h"

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

void pesquisa_letra(void)
{
}

void lista_contatos(contato *lista)
{
    
    printf("\nLista de contatos:\n\n");

    while (lista != NULL)
    {
        printf("%s\n", lista->nome);
        lista = lista->prox;
    }
}

contato *pesquisa_nome(char *a_pesquisar, contato **lista)
{
    contato *contato_removido, *match, *lista_temp;
    int contato_inserido, nomes_diferentes;

    lista_temp = NULL;
    nomes_diferentes = 1;

    do
    {
        contato_removido = (contato *) linked_list_remove((void *) lista);

        contato_inserido = linked_list_insert((void *) contato_removido,
                (void *) &lista_temp);

        if (lista_temp != NULL)
            nomes_diferentes = strcmp(a_pesquisar, lista_temp->nome);
    }
    while (contato_inserido && nomes_diferentes);

    if(!nomes_diferentes) match = lista_temp;
    else match = NULL;
  
    while(lista_temp != NULL)
    {
        linked_list_insert((void *) linked_list_remove((void *) &lista_temp),
                (void *) lista);
    }
    
    return match;
}

void remover_contato(contato **lista)
{
    char * a_remover;

    a_remover = get_string(MAX_CHARS, "Nome do contato a remover: ");

    contato *lista_temp = NULL;
    while (linked_list_insert((void *) linked_list_remove((void *) lista), (void *) &lista_temp) && strcmp(a_remover, lista_temp->nome));
    free(linked_list_remove((void *) &lista_temp));
  
    while(lista_temp != NULL){

        linked_list_insert((void *) linked_list_remove((void *) &lista_temp), (void *) lista);
    }
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

    novo->telefone = get_long(0, LONG_MAX, "Telefone: ");
    novo->data_de_nascimento.ano = get_int(0, INT_MAX, "Ano de nascimento: ");
    novo->data_de_nascimento.mes = get_int(0, INT_MAX, "Mês de nascimento: ");
    novo->data_de_nascimento.dia = get_int(0, INT_MAX, "Dia de nascimento: ");
    novo->prox = NULL;

    linked_list_insert((void *) novo, (void *) lista);
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
