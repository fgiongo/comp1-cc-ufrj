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
	FILE * arquivo_contatos;
	contato * lista_de_contatos = NULL;

	if (!(arquivo_contatos = fopen(FILEPATH, "r")))
	{
		printf("Criando nova lista de contatos...\n");
		if (!(arquivo_contatos = fopen(FILEPATH, "w")))
		{
			printf("Nao foi possivel criar arquivo de contatos\n");
			return 1;
		}
        else fclose(arquivo_contatos);
	}

    printf("Lendo lista de contatos...\n");

    if (!(arquivo_contatos = fopen(FILEPATH, "r")))
    {
			printf("Nao foi possivel abrir arquivo de contatos\n");
            return 1;
    }

    lista_de_contatos = (contato *) ler_contatos(arquivo_contatos);

    switch (menu_principal())
    {
        case 1:
            inserir_contato();
            break;

        case 2:
            remover_contato();
            break;

        case 3:
            pesquisa_nome();
            break;

        case 4:
            lista_contatos();
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

	return 0;
}

