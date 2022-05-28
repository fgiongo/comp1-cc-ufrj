/*
 * 	Programa: ex01.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Este programa mostra exemplo de definicao de variaveis
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	int i;
	float r;
	double dr;
	char c;

	/* Aqui vao os comandos do programa */

	i = 10;
	r = 1.0;
	dr = 3e13;
	c = 'a';

	printf("i = %d\n", i);
	printf("r = %f\n", r);
	printf("df = %f\n", dr);
	printf("c = %c\n", c);

	return 0;
}
