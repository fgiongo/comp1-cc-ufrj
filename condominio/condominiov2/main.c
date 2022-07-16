#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "helpers.h"
#include "utils.h"
#include "listas.h"

int main(void)
{
    printf("Bem-vindo Mobiliária Tabajara\n\n");

    while(1)
    {
        switch (menu_principal())
        {
            case 1: /*inseir condomínio*/
                lista_enc_inserir_condominio(
                    novo_condominio(
                        get_string(MAX_CHARS, "Nome: "),
                        get_string(MAX_CHARS, "Nome da Rua: "),
                        get_long(1, 99999999, "Número: "),

                        /*resolver questão de vetores*/
                        get_int(1, 26, "Quantidade de Blocos "),
                        get_int(1, 100, "Quantidade de andares "),
                        get_int(1, 20, "Quantidade de apt por andar ")
                    )
                )
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
            case 8: /*clistar condominio*/
                break;
            case 9: /*sair e salvar*/
                break;
        }
  
    }
    
    return 0;
}