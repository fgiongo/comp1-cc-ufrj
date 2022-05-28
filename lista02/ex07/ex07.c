/*
 * 	Programa: ex07.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Le tres notas de um aluno, calcula sua media
 * 	e informa se ele foi aprovado ou nao.
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	float notaAluno, mediaAluno;
	int match;

	/* Aqui vao os comandos do programa */

	printf("Nota 1 (de 0 a 10): ");
	match = scanf("%f", &notaAluno);

	if (!match || notaAluno < 0 || notaAluno > 10)
	{
		printf("Nota invalida.\n");
		return 1;
	}
       	
	mediaAluno = 0;
	mediaAluno += notaAluno;

	printf("Nota 2 (de 0 a 10): ");
	match = 0;
	match = scanf("%f", &notaAluno);

	if (!match || notaAluno < 0 || notaAluno > 10)
	{
		printf("Nota invalida.\n");
		return 1;
	}

	mediaAluno += notaAluno;

	printf("Nota 3 (de 0 a 10): ");
	match = 0;
	match = scanf("%f", &notaAluno);

	if (!match || notaAluno < 0 || notaAluno > 10)
	{
		printf("Nota invalida.\n");
		return 1;
	}

	mediaAluno += notaAluno;
	mediaAluno = mediaAluno / 3;

	if (mediaAluno >= 5)
	{
		printf("Aprovado\n");
	}
	else
	{
		printf("Reprovado\n");
	}

	return 0;
}

/*
	Saídas:

	Em caso de valores validos:

		Nota 1 (de 0 a 10): 4.6
		Nota 2 (de 0 a 10): 3.2
		Nota 3 (de 0 a 10): 7.8
		Aprovado

	Em caso de valores invalidos:

		Nota 1 (de 0 a 10): 46
		Nota invalida.
*/
