/*
 * 	Programa: L04e01a.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/05/2022
 * 	Descrição: O programa imprime um retangulo de asteriscos
 * 	cujo numero de linhas e colunas e' pedido ao usuario
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */
	int linhas, colunas, match;
	int c, i, j;

	/* pedindo ao usuario entrada de numero de linhas */
	do
	{
		printf("Entre com o número de linhas: ");
		match = scanf("%d", &linhas);

	}
	while (match == 0 || linhas <= 0);

	/* descartando caracteres extras */
	c = getchar();
	while(c != '\n') c = getchar();


	/* pedindo ao usuario entrada de numero de colunas */
	do
	{
		printf("Entre com o número de colunas: ");
		match = scanf("%d", &colunas);
	}
	while (match == 0 || colunas <= 0);

	/* desenhando retangulo */
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/* Saida

Entre com o numero de linhas: 3
Entre com o numero de colunas: 5
*****
*****
*****

*/
