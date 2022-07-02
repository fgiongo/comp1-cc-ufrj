#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils.h"
#include "../defs.h"
#include "../helpers.h"


contato *pesquisar_letra_teste(char c, contato **lista)
{
    contato *lista_temp, *lista_match, *removido;

    while ((removido = (void *)linked_list_remove((void *)lista)) != NULL)
    {
        if (removido->nome[0] == c)
            linked_list_insert((void *)removido, (void *)&lista_match);
        else linked_list_insert((void *)removido, (void *)&lista_temp);
    }
    
    while ((removido = (void *)linked_list_remove((void *) &lista_temp)) != NULL)
        linked_list_insert((void *)removido, (void *)lista);
    
    return lista_match;
}

int main (void)
{
    contato *lista, *temp;
    contato *node;
    char c;

    lista = NULL;

    node = (contato *) malloc(sizeof(contato));
    inserir_contato(&lista);

    node = (contato *) malloc(sizeof(contato));
    inserir_contato(&lista);

    node = (contato *) malloc(sizeof(contato));
    inserir_contato(&lista);

    c = get_char("Inserir letra inicial: ");
    temp = pesquisar_letra_teste(c, &lista);
    listar_contatos(temp);

    return 0;
}
