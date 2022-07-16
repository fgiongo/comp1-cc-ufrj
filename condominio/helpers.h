#include "defs.h"


int menu_principal(void);

condominio *novo_condominio(char *nome, char *rua, int num_rua, int qtd_blocos, int *input_qtd_andares,
int *input_qtd_apts);

void imprimir_dados(condominio *cond);