    /* defs.h */

#ifndef DEFS_H
#define DEFS_H
#define FILEPATH "./contatos.txt"
#define MAX_CHARS 40

typedef struct _DATA
{
	int dia, mes, ano;
} data;

typedef struct _CONTATO
{
	struct _CONTATO *prox;
	char nome[MAX_CHARS + 1];
	long telefone;
	data data_de_nascimento;
} contato;
#endif
