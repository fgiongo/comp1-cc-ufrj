/*
 * 	Programa: L04e05b.c
 * 	Autor: Fernando Giongo
 * 	Data: 17/05/2022
 * 	Descrição: O programa imprime o nome do mes, de acordo com o numero
 * 	digitado pelo usuario.
 */

#include <stdio.h>

int main (void)
{
	int mes, match;

	do
	{
		printf("Entre com o numero do mes: ");
		match = scanf("%d", &mes);
	}
	while (match == 0 || mes < 1 || mes > 12);

	switch (mes)
	{
		case 1:
			printf("Janeiro\n");
			break;
		case 2:
			printf("Fevereiro\n");
			break;
		case 3:
			printf("Marco\n");
			break;
		case 4:
			printf("Abril\n");
			break;
		case 5:
			printf("Maio\n");
			break;
		case 6:
			printf("Junho\n");
			break;
		case 7:
			printf("Julho\n");
			break;
		case 8:
			printf("Agosto\n");
			break;
		case 9:
			printf("Setembro\n");
			break;
		case 10:
			printf("Outubro\n");
			break;
		case 11:
			printf("Novembro\n");
			break;
		case 12:
			printf("Dezembro\n");
			break;
	}

	return 0;
}

/* Saida

   Entre com o numero do mes: 8
   Agosto

*/

