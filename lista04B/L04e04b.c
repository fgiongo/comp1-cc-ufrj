/*
 * 	Programa: L04e04b.c
 * 	Autor: Fernando Giongo
 * 	Data: 17/05/2022
 * 	Descrição: O programa calcula o valor total a ser pago pelo cliente.
 * 	O programa recebe um codigo para determinar o tipo de cliente e aplica
 * 	descontos de acordo (10% para funcionarios e 5% para vips).
 */

#include <stdio.h>

int main (void)
{
	float item, subtotal = 0.00;
	int match, codigoDoCliente, c = 0;

	do
	{
		printf("Entre codigo do cliente: (1) para comum, (2) para funcionario ou (3) para VIP\n");
		match = scanf("%d", &codigoDoCliente);
	}
	while (match == 0 || codigoDoCliente < 1 || codigoDoCliente > 3);
	
	c = getchar();
	while (c != '\n') c = getchar();

	do
	{
		printf("Entre valor do proximo item (entre 0 para encerrar): ");
		match = scanf("%f", &item);
		if (match == 0) continue;
		if (item == 0) break;
		subtotal += item;

	}
	while(1);

	switch (codigoDoCliente)
	{
		case 1:
			break;

		case 2:
			printf("Desconto de funcionario:\nValor original: %.2f\n", subtotal);
			subtotal *= 0.9;
			break;
			
		case 3:
			printf("Desconto de VIP:\nValor original: %.2f\n", subtotal);
			subtotal *= 0.95;
			break;
	}

	printf("Valor a pagar: %.2f\n", subtotal);

	return 0;
}

/* Saida

Entre codigo do cliente: (1) para comum, (2) para funcionario ou (3) para VIP
2
Entre valor do proximo item (entre 0 para encerrar): 20.00
Entre valor do proximo item (entre 0 para encerrar): 10.00
Entre valor do proximo item (entre 0 para encerrar): 20.00
Entre valor do proximo item (entre 0 para encerrar): 0
Desconto de funcionario:
Valor original: 50.00
Valor a pagar: 45.00

*/

