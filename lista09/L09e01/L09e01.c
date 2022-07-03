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
    contato *lista_de_contatos, *lista_tmp;

    lista_de_contatos = lista_tmp = NULL;
    
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
                lista_tmp = pesquisar_letra(
                        get_char("Inserir inicial: "),
                        &lista_de_contatos);

                listar_contatos(lista_tmp);
                
                printf("listar_contatos concluída\n");

                while (lista_tmp != NULL)
                {
                    lista_enc_inserir(
                            lista_enc_remover(&lista_tmp),
                            &lista_de_contatos);
                }
                
            break;

        case 6:
            imprime_aniversariantes(lista_de_contatos, get_int(1, 12, "Insira mês de aniversário a procurar: "));
            break;

        case 7:
            return 0;

        default:
            return 2;
        }
    }

    return 0;
}
