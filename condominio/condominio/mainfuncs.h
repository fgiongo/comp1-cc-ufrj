condominio *ler_arquivo_salvo(FILE *arquivo);
int menu_principal(void);
int inserir_condominio(condominio **lista);
void remover_condominio(condominio **lista);
void imprimir_lista_condominial(condominio *lista_cond);
void salvar_lista(condominio *lista_condominios, FILE *arquivo);
void consultar_por_condominio(condominio *lista);
void inserir_bloco(condominio *lista);
void remover_bloco(condominio *lista);
