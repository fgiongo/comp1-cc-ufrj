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
    contato *lista_de_contatos = ler_contatos(
            fopen(FILEPATH, "r")
            );
    
    while (1)
    {
        switch (menu_principal())
        {
        case 1:
            inserir_contato(&lista_de_contatos);
            break;

        case 2:
            remover_contato(&lista_de_contatos);
            break;

        case 3:
            if (!
                    imprimir_contato(
                        pesquisa_nome(

                            get_string(MAX_CHARS, "Pesquisa por nome: "), 
                            &lista_de_contatos

                            )
                        )
               ) printf("Contato não encontrado\n");
            break;

        case 4:
            lista_contatos(lista_de_contatos);
            break;

        case 5:
            pesquisa_letra();
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
