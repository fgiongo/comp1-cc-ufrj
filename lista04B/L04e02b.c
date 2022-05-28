/*
 * 	Programa: L04e02b.c
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: Este programa le a idade de um numero indeterminado de pessoas e
 * 	calcula o numero de pessoas, a idade media do grupo, a menor idade e a
 * 	maior idade.
 */

#include <stdio.h>

int main (void)
{
	int i, match, numPessoas = 0, idadeMedia = 0, menorIdade, maiorIdade;

	do
	{
		printf("Entre com o valor da idade: ");
		match = scanf("%d", &i);
		if (match == 0) continue;
		if (i < 0) continue;
		if (i == 0) break;
		idadeMedia += i;
		if (numPessoas == 0)
		{
			menorIdade = i;
			maiorIdade = i;
		}
		menorIdade = (menorIdade > i) ? i : menorIdade;
		maiorIdade = (maiorIdade < i) ? i : maiorIdade;
		numPessoas++;
	}
	while (1);

	idadeMedia /= numPessoas;

	printf("Numero de pessoas: %d\n", numPessoas);
	printf("Idade media do grupo: %d\n", idadeMedia);
	printf("Menor idade: %d\n", menorIdade);
	printf("Maior idade: %d\n", maiorIdade);

	return 0;
}

/* Saida

   Entre com o valor da idade: 10
   Entre com o valor da idade: 20
   Entre com o valor da idade: 40
   Entre com o valor da idade: 0
   Numero de pessoas: 3
   Idade media do grupo: 23
   Menor idade: 10
   Maior idade: 40

*/

