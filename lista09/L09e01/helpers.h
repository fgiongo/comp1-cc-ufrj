/* helpers.h */

#include <stdio.h>
#include "defs.h"

int ler_contatos(char *path, contato **lista);
int menu_principal(void);
contato *pesquisar_letra(char c, contato **lista);
int listar_contatos(contato *lista);
contato *pesquisar_nome(char *a_pesquisar, contato **lista);
int remover_contato(char *a_remover, contato **lista);
void inserir_contato(contato **lista);
void imprime_aniversariantes(contato *lista, int mes);
int imprimir_contato(contato *contato);
int lista_enc_inserir(contato *node, contato **lista);
contato *lista_enc_remover(contato **lista);
int salvar_lista(contato *lista, char * path);
