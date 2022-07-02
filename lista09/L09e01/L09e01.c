/* Nome do arquivo: L09e01.c
 * Data: 29/06/2022
 * Autor: Fernando Giongo
 * Descricao: O programa gerencia uma agenda de contatos. Cada item da agenda
 * contem nome, telefone e data de aniversario do contato. O programa permite
 * listar contatos e pesquisar contatos por nome e inicial e permite imprimir
 * os aniversariantes do mes.
 */

#include <stdio.h>
#include "defs.h"
#include "utils.h"
#include "helpers.h"

int main(void)
{
    contato *lista_de_contatos;

    lista_de_contatos = NULL;
    
    while (1)
    {
        switch (menu_principal())
        {
        case 1:
            inserir_contato(&lista_de_contatos);
            break;

        case 2:
            if (!remover_contato(
                    get_string(MAX_CHARS, "Nome do contato a remover: "),
                    &lista_de_contatos)) printf("\nContato inexistente\n");
            else
                printf("\nContato removido com sucesso\n");
            break;

        case 3:
            if (!imprimir_contato(
                    pesquisar_nome(

                        get_string(MAX_CHARS, "Pesquisa por nome: "),
                        &lista_de_contatos

                        )))
                printf("\nContato não encontrado\n");
            break;

        case 4:
            if (!listar_contatos(lista_de_contatos))
                printf("Não há contatos\n");
                break;

        case 5:
                {
                    char c = get_char("Inserir letra inicial: ");
                    contato *lista_temp, *lista_match, *removido;
                    lista_temp = NULL;

                    while ((removido = (void *)lista_enc_remover((void *)&lista_de_contatos)) != NULL)
                    {
                        if (removido->nome[0] == c)
                            lista_enc_inserir((void *)removido, (void *)&lista_match);
                        else lista_enc_inserir((void *)removido, (void *)&lista_temp);
                    }

                    printf("Lista temporaria construida\n");
                    listar_contatos(lista_match);

                    while ((removido = (void *)lista_enc_remover((void *) &lista_temp)) != NULL)
                        lista_enc_inserir((void *)removido, (void *)&lista_de_contatos);

                    printf("Lista principal reconstruida\n");
                }
            break;

        case 6:
            imprime_aniversariantes();
            break;

        case 7:
            return 0;

        default:
            return 2;
        }
    }

    return 0;
}
