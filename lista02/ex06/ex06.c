/*
 * 	Programa: ex06.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Este programa imprime a soma de todos os números inteiros
 * 	entre 0 e N (não inclusive). O valor de N é lido do teclado.
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	long n, soma;
	int match;

	/* Aqui vao os comandos do programa */

	printf("Inserir um numero inteiro: ");
	match = scanf("%li", &n);

	if (!match)
	{
		printf("Valor invalido.\n");
		return 1;
	}

	if (n < 2 && n > -2)
	{
		soma = 0;
		printf("Soma de todos os numeros inteiros entre 0 e %li (nao incluindo %li) = %li\n", n, n, soma);
		return 0;
	}

	if (n > 1)
	{
		soma = n + n * (n - 3) / 2;
		printf("Soma de todos os numeros inteiros entre 0 e %li (não incluindo %li) = %li\n", n, n, soma);
		return 0;
	}

	if (n < -1)
	{
		soma = n - n * (n + 3) / 2;
		printf("Soma de todos os numeros inteiros entre 0 e %li (não incluindo %li) = %li\n", n, n, soma);
		return 0;
	}

	return 2;
}

/*
	Saidas:
	
	Em caso de entrada valida:

		Inserir um numero inteiro: 10
		Soma de todos os numeros inteiros entre 0 e 10 (não incluindo 10) = 45
	
	Em caso de entrada invalida:

		Inserir um numero inteiro: sete
		Valor invalido.
*/

