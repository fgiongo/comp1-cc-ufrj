/*
 * 	Programa: L04e03b.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: Este programa le 3 notas e imprime a media. O programa termina
 * 	quando o usuario inclui uma nota negativa.
 */

#include <stdio.h>

int main (void)
{
	float media = 0.0, nota = 0.0;
	int numNotas = 0, match, c;
	while (numNotas < 3)
	{
		printf("Inserir nota: ");
		match = scanf("%f", &nota);
		if (nota < 0) return 1;
		media += nota;
		c = getchar();
		while (c != '\n') c = getchar();
		if (match == 0) continue;
		numNotas++;
	}

	media /= numNotas;
	printf("Media: %.2f\n", media);
	return 0;
}

/* Saida

   Inserir nota: 30
   Inserir nota: 90
   Inserir nota: 75
   Media: 65.00

*/

