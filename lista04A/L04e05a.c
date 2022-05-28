/*
 * 	Programa: L04e05a.c
 * 	Autor: Fernando Giongo
 * 	Data: 18/05/2022
 * 	Descrição: O programa verifica se o gerador de numeros aleatorios tem
 * 	vicios. Ele geera 1 000 000 numeros aleatorios entre 0 e RAND_MAX e calcula
 * 	a frequencia de pares ou impares.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ITERATIONS 1000000 

int main (void)
{
	int i, randomNumber, pares = 0, impares = 0;
	float porcentagem;

	srand(time(NULL));

	for (i = 0; i < ITERATIONS; i++)
	{
		randomNumber = rand();
		(randomNumber % 2 == 0) ? pares++ : impares++;
	}

	porcentagem = ((float) pares / (float) ITERATIONS) * 100;
	printf("Porcentagem de pares: %.2f%%\n", porcentagem);

	porcentagem = ((float) impares / (float) ITERATIONS) * 100;
	printf("Porcentagem de impares: %.2f%%\n", porcentagem);
	return 0;
}

/* Saida

Porcentagem de pares: 49.91%
Porcentagem de impares: 50.09%

*/

