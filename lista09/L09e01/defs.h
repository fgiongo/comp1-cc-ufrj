/* defs.h */

#ifndef DEFS_H
#define DEFS_H
#define FILEPATH "./contatos.txt"

typedef struct _DATA
{
	int dia, mes, ano;
} data;

typedef struct _CONTATO
{
	char nome[41];
	int telefone;
	data data_de_nascimento;
	struct _CONTATO *prox;
} contato;
#endif
