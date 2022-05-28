/*
 * 	Programa: L04e02a.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/05/2022
 * 	Descrição: o programa imprime um triangulo reto na forma de asteriscos
 * 	cuja altura e' pedida ao usuario
 */

#include <stdio.h>

int main (void)
{
	int altura, i, j, c;

	/* Pedindo entrada do valor altura ao usuario */
	do
	{
		printf("Entre com o numero de linhas da figura: ");
		c = scanf("%d", &altura);
	}
	while (c == 0 || altura <= 0);

	/* Imprimindo triangulo */
	for (i = 0; i < altura; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	return 0;
}

/* Saida

   Entre com o numero de linhas da figura: 4
   *
   **
   ***
   ****

*/
