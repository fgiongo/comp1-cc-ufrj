/*
 * 	Programa: ex05.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Este programa calcula a nota de um aluno de uma disciplina
 * 	cuja formula e a seguinte:
 * 
 * 	notaFinal = 0.8 * prova + 0.2 * (t1 + t2 + t3) / 3
 *
 * 	considerando o numero de testes igual a 3
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	float teste1, teste2, teste3, prova, notaFinal;
	int match;

	/* Aqui vao os comandos do programa */
	
	printf("Insira a nota do teste 1 (de 0.00 a 10.00):\n");
	match = scanf("%f", &teste1);

	if (!match || teste1 < 0 || teste1 > 10)
	{
		printf("Valor invalido.\n");
		return 1;
	}

	printf("Insira a nota do teste 2 (de 0.00 a 10.00):\n");
	match = 0;
	match = scanf("%f", &teste2);

	if (!match || teste2 < 0 || teste2 > 10)
	{
		printf("Valor invalido.\n");
		return 1;
	}

	printf("Insira a nota do teste 3 (de 0.00 a 10.00):\n");
	match = 0;
	match = scanf("%f", &teste3);

	if (!match || teste3 < 0 || teste3 > 10)
	{
		printf("Valor invalido.\n");
		return 1;
	}

	printf("Insira a nota da prova (de 0.00 a 10.00):\n");
	match = 0;
	match = scanf("%f", &prova);

	if (!match || prova < 0 || prova > 10)
	{
		printf("Valor invalido.\n");
		return 1;
	}

	notaFinal = 0.8 * prova + 0.2 * (teste1 + teste2 + teste3) / 3;

	printf("\n");
	printf("Prova : %.1f\n", prova);
	printf("Teste 1: %.1f\n", teste1);
	printf("Teste 2: %.1f\n", teste2);
	printf("Teste 3: %.1f\n", teste3);
	printf("Nota Final: %.1f\n", notaFinal);

	return 0;
}

/*
	Saídas:
	
	Em caso de valores válidos:

		Insira a nota do teste 1 (de 0.00 a 10.00):
		1.23
		Insira a nota do teste 2 (de 0.00 a 10.00):
		4.56
		Insira a nota do teste 3 (de 0.00 a 10.00):
		7.89
		Insira a nota da prova (de 0.00 a 10.00):
		10.00

		Prova : 10.0
		Teste 1: 1.2
		Teste 2: 4.6
		Teste 3: 7.9
		Nota Final: 8.9

	Em caso de valores inválidos:

		Insira a nota do teste 1 (de 0.00 a 10.00):
		75.00
		Valor invalido.
*/
