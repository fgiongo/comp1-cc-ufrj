/*
 * 	Programa: L04e06a.c
 * 	Autor: Fernando Giongo
 * 	Data: 19/05/2022
 * 	Descrição: Este programa cria um dado virtual e testa se e' justo ou
 * 	tem alguma tendencia.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ITERATIONS 6000000

int main (void)
{
	int i, dado;
	int lado[] = {0, 0, 0, 0, 0, 0};
	float porcentagem[6];

	srand(time(NULL));
	for (i = 0; i < ITERATIONS; i++)
	{
		dado = rand() % 6;
		switch(dado)
		{
			case(0):
				lado[dado]++;
				break;
				
			case(1):
				lado[dado]++;
				break;
				
			case(2):
				lado[dado]++;
				break;

			case(3):
				lado[dado]++;
				break;

			case(4):
				lado[dado]++;
				break;

			case(5):
				lado[dado]++;
				break;
		}
	}

	for (i = 0; i < 6; i++)
	{
		porcentagem[i] = ((float) lado[i] / (float) ITERATIONS) * (float) 100;
		printf("Frequencia do lado %d: %.2f\n", i + 1, porcentagem[i]);
	}

	return 0;
}

/* Saida

Frequencia do lado 1: 16.63
Frequencia do lado 2: 16.68
Frequencia do lado 3: 16.66
Frequencia do lado 4: 16.66
Frequencia do lado 5: 16.67
Frequencia do lado 6: 16.69

*/
