/* helpers.c */

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "utils.h"

contato * ler_contatos(FILE * arquivo)
{
    contato *lista = NULL, *novo_contato;

    while (!(feof(arquivo)))
    {
        novo_contato = malloc(sizeof(contato));
        if (novo_contato == NULL) return NULL;

        if (!(fread(novo_contato, sizeof(contato), 1, arquivo)))
        {
            free(novo_contato);
            return NULL;
        }

        linked_list_insert(novo_contato, lista, sizeof(contato));
    }

    return lista;
}

int menu_principal(void)
{
	char * titulo = "\nMenu Principal\n\n";
	char * a = "(1) inserir contato\n";
	char * b = "(2) remover contato\n";
	char * c = "(3) pesquisar contato por nome\n";
	char * d = "(4) listar todos os contatos\n";
	char * e = "(5) listar contatos cujo nome inicia com dada letra\n";
	char * f = "(6) imprimir aniversariantes do mes\n";
	char * g = "(7) sair\n";

	printf("%s%s%s%s%s%s%s%s\n", titulo, a, b, c, d, e, f, g);

    return get_int(1, 7, "Escolha opcao: ");
}

void pesquisa_letra(void)
{
}

void lista_contatos(void)
{
}

void pesquisa_nome(void)
{
}

void remover_contato(void)
{
}

void inserir_contato(void)
{
}

void imprime_aniversariantes(void)
{
}

