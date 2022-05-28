/*
 * 	Programa: L04e07a.c
 * 	Autor: Fernando Giongo
 * 	Data: 19/05/2022
 * 	Descrição: Este programa usa um gerador de numeros aleatorios para calcular pi.
 * 	Ele faz isso gerando pontos em um grafico bidimensional de numeros reais entre
 * 	0 e 1, depois contando o numero de pontos para os quais x^2 + y^2 <= 1 .
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define ITERATIONS_MIN 1000000
#define ITERATIONS_MAX 9999999

int main (void)
{
	float ponto[2], x;
	int i, dentro = 0;

	srand(time(NULL));
	for (i = 0; i < ITERATIONS_MIN; i++)
	{
		ponto[0] = (rand() % ITERATIONS_MIN + 1) / (float) ITERATIONS_MIN; 
		ponto[1] = (rand() % ITERATIONS_MIN + 1) / (float) ITERATIONS_MIN; 

		if (pow(ponto[0], 2) + pow(ponto[1], 2) <= 1.00) dentro++;
	}

	x = (4 * dentro) / (float) ITERATIONS_MIN;
	printf("a) X = %f\n", x);

	dentro = 0;
	for (i = 0; i < ITERATIONS_MAX; i++)
	{
		ponto[0] = (rand() % ITERATIONS_MIN + 1) / (float) ITERATIONS_MIN; 
		ponto[1] = (rand() % ITERATIONS_MIN + 1) / (float) ITERATIONS_MIN; 

		if (pow(ponto[0], 2) + pow(ponto[1], 2) <= 1.00) dentro++;
	}


	x = (4 * dentro) / (float) ITERATIONS_MAX;
	printf("b) X = %f\n", x);

	return 0;
}

/* Saida

a) X = 3.143132
b) X = 3.141763

*/
