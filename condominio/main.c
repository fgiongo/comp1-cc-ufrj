#include "defs.h"
#include "mainfuncs.h"

int main(void)
{
    condominio *lista_condominios;

    printf("Bem-vindo ao Sistema de Controle da Imobiliária Tabajara\n\n");

    lista_condominios = NULL;

    while(1)
    {
        switch (menu_principal())
        {
            case 1: /*inseir condomínio*/
                inserir_condominio(&lista_condominios);
                break;

            case 2: /*remover condomínio*/
                remover_condominio(&lista_condominios);
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
                imprimir_lista_condominial(lista_condominios);

                break;
            case 9: /*sair e salvar*/
                return 0;
                break;
        }
  
    }
    
    return 0;
}

