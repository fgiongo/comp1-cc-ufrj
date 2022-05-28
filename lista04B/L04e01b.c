/*
 * 	Programa: L04e01b.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/05/2022
 * 	Descrição: exercicio de re-escrever for loop usando while:
 * 	o programa imprime os numeros de 1 a 4, exceto o numero 2
 */

#include <stdio.h>

int main (void)
{
	int i = 0;
	while (i <= 20)
	{
		i++;
		if (i == 2) continue;
		if (i == 5) break;
		printf("i = %d\n", i);
	}
	return 0;
}

/* Saida

   i = 1
   i = 3
   i = 4

*/

