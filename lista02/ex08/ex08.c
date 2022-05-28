/*
 * 	Programa: ex08.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: calcula media de aluno e informa se ele foi aprovado ou nao.
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	float notaAluno, mediaAluno = 0.0;
	int notasLidas = 0, quantProvas, match;

	/* Aqui vao os comandos do programa */
	
	printf("Quantidade de provas: ");
	match = scanf("%d", &quantProvas);

	if (!match)
	{
		printf("Valor inválido\n");
		return 1;
	}

	while (notasLidas < quantProvas)
	{
		printf("Nota %d (de 0.0 a 10.0): ", notasLidas + 1);
		match = scanf("%f", &notaAluno);

		if (!match || notaAluno < 0 || notaAluno > 10)
		{
			printf("Valor invalido.\n");
			return 2;
		}

		mediaAluno += notaAluno;
		notasLidas++;
	}

	mediaAluno /= quantProvas;
	printf("A media do aluno foi %.1f\n", mediaAluno);

	if (mediaAluno >= 5.0)
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
	Saidas:

	Em caso de valores validos:

		Quantidade de provas: 4
		Nota 1 (de 0.0 a 10.0): 3.5
		Nota 2 (de 0.0 a 10.0): 6.4
		Nota 3 (de 0.0 a 10.0): 8.1
		Nota 4 (de 0.0 a 10.0): 5.5
		A media do aluno foi 5.9
		Aprovado

	Em caso de valores invalidos:

		Quantidade de provas: 4
		Nota 1 (de 0.0 a 10.0): 11
		Valor invalido.
*/
