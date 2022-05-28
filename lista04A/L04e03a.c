/*
 * 	Programa: L04e03a.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/05/2022
 * 	Descrição: Este programa imprime um triangulo reto invertido cuja altura
 * 	e' dada pelo usuario
 */

#include <stdio.h>

int main (void)
{
	int altura, i, j, c;

	/* pedindo ao usuario a entrada do numero de linhas da figura */
	do
	{
		printf("Entre com o numero de linhas da figura: ");
		c = scanf("%d", &altura);
	}
	while (c == 0 || altura <= 0);

	/* imprimindo figura */
	for (i = 0; i < altura; i++)
	{
		for (j = 0; j < altura - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/* Saida

   Entre com o numero de linhas da figura: 5
   *****
   ****
   ***
   **
   *

*/
