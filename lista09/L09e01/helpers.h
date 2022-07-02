/* helpers.h */

#include <stdio.h>
#include "defs.h"

contato * ler_contatos(FILE * arquivo);
int menu_principal(void);
void pesquisa_letra(void);
void lista_contatos(contato *lista);
contato *pesquisa_nome(char *a_pesquisar, contato **lista);
void remover_contato(contato **lista);
void inserir_contato(contato **lista);
void imprime_aniversariantes(void);
int imprimir_contato(contato *contato);

