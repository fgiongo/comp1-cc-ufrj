#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "defs.h"
#include "helpers.h"
#include "utils.h"
#include "listas.h"

int main(void)
{
    condominio *lista_condominios, *novo_condominio;
    int blocos, numero, *andares, *apts;
    char *nome, *endereco;

    printf("Bem-vindo Mobiliária Tabajara\n\n");

    lista_condominios = NULL;

    while(1)
    {
        switch (menu_principal())
        {
            case 1: /*inseir condomínio*/

                nome = get_string(MAX_CHARS, "Nome do condominio: ");
                endereco = get_string(MAX_CHARS, "Endereço (Rua): ");
                numero = get_int(1, INT_MAX, "Endereço (Numero): ");
                blocos = get_int(1, INT_MAX, "Numero de blocos: ");
                andares = criar_vetor_andares(blocos);
                apts = criar_vetor_apts(blocos);

                novo_condominio = criar_novo_condominio(
                        nome,
                        endereco,
                        numero,
                        blocos,
                        andares,
                        apts);

                free(andares);
                free(apts);
                
                lista_enc_inserir_condominio(
                        novo_condominio,
                        &lista_condominios);
                break;

            case 2: /*remover condomínio*/
                break;
            case 3: /*inserir bloco*/
                break;
            case 4: /*remover bloco*/
                break;
            case 5: /*editar condominoi*/
                break;
            case 6: /*editar bloco*/
                break;
            case 7: /*consultar condominio*/
                break;
            case 8: /*listar condominio*/
                imprimir_dados(novo_condominio);

                break;
            case 9: /*sair e salvar*/
                return 0;
                break;
        }
  
    }
    
    return 0;
}
