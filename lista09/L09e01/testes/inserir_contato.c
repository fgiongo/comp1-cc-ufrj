#include <stdio.h>
#include <stdlib.h>

#define MAX_CHARS 40

typedef struct _DATA
{
	int dia, mes, ano;
} data;

typedef struct _CONTATO
{
	struct _CONTATO *prox;
	char nome[MAX_CHARS + 1];
	long telefone;
	data data_de_nascimento;
} contato;

char *get_string(int length, char * prompt)
{
    int i;
    char *c;
    printf("%s", prompt);
    c = calloc(length, sizeof(char));
    fgets(c, length, stdin);

    for (i = 0; c[i] != '\0'; i++)
        if (c[i] == '\n') c[i] = '\0';

    return c;
}

void linked_list_insert(void **new_node, void **list, int node_size)
{
    /* !!!caution!!!
     * function relies on pointer to next node being AT START of node! */

    void *temp;
    unsigned char **ptr_next;

    temp = *list;
    *list = *new_node;

    ptr_next = *new_node;
    *ptr_next = temp;
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
    strcpy(novo -> nome, nome);

    novo -> data_de_nascimento.ano = get_int(0, INT_MAX, "Ano de nascimento: ");
    novo -> data_de_nascimento.mes = get_int(0, INT_MAX, "Mês de nascimento: ");
    novo -> data_de_nascimento.dia = get_int(0, INT_MAX, "Dia de nascimento: ");
    novo -> prox = NULL;

    linked_list_insert((void *) &novo, (void *) lista, sizeof(contato));
}

int main (void)
{
    contato *lista;
    return 0;
}