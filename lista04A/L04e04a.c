/*
 * 	Programa: L04e04a.c
 * 	Autor: Fernando Giongo
 * 	Data: 18/05/2022
 * 	Descrição: Este programa mostra como podemos gerar numeros inteiros
 * 	radomicos em um intervalo.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
	int i, n;
	int max = 100;

	/* srand inicializa o gerador de numeros randomicos
	   ---- So precisa aparecer uma vez no inicio do programa.
	   ---- time(NULL) retorna o numero de segundos que aconteceram desde
	   01/01/1970
	   ---- srand deve receber um inteiro para inicializar o gerador de numeros
	   randomicos. Costuma-se usar o numero de segundos fornecidos por time(NULL).
	*/
	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		n = rand(); /* gera um numero inteiro entre 0 e RAND_MAX */
		n = n % max; /* passa este numero para o intervalo 0 - max */
		printf("%d\n", n);
	}
	return 0;
}

/* Saida

95
79
99
31
35
6
11
57
27
77

*/

