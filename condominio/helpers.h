#include "defs.h"


int menu_principal(void);

condominio *criar_novo_condominio(
        char *nome,
        char *rua,
        int num_rua,
        int qtd_blocos,
        int *qtd_andares,
        int *qtd_apts);

bloco *criar_novo_bloco(char letra, int qtd_andares, int qtd_apts);

void imprimir_dados(condominio *cond);

int *criar_vetor_andares(int num_blocos);
int *criar_vetor_apts(int num_blocos);
