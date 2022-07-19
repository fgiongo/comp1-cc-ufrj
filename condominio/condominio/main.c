#include "defs.h"
#include "mainfuncs.h"

int main(void)
{
    condominio *lista_condominios;
    FILE *arquivo_lista;

    arquivo_lista = fopen(LISTA_PATH, "r");
    if (!arquivo_lista)
    {
        printf("Nenhum arquivo salvo encontrado, criando novo arquivo...\n");
        arquivo_lista = fopen(LISTA_PATH, "w");
        fclose(arquivo_lista);
        arquivo_lista = fopen(LISTA_PATH, "r");
    }
    if (!arquivo_lista)
    {
        printf("Não foi possível criar novo arquivo. Encerrando.\n");
        return 1;
    }

    lista_condominios = ler_arquivo_salvo(arquivo_lista);
    fclose(arquivo_lista);

    printf("\n\nBem-vindo ao Sistema de Controle da Imobiliária Tabajara\n\n");
    printf("(versão alpha 0.1)\n\n");

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
                inserir_bloco(lista_condominios);
                break;
            case 4: /*remover bloco*/
                remover_bloco(lista_condominios);
                break;
            case 6: /*editar bloco*/
                break;
            case 7: /*consultar condomio*/
                consultar_por_condominio(lista_condominios);
                break;
            case 8: /*listar condominio*/
                imprimir_lista_condominial(lista_condominios);
                break;

            case 9: /*salvar e sair*/
                arquivo_lista = fopen(LISTA_PATH, "w");
                salvar_lista(lista_condominios, arquivo_lista);
                fclose(arquivo_lista);
                return 0;
        }
    }
}

