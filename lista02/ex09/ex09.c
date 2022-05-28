/*
 * 	Programa: ex09.c
 * 	Autor: Fernando Giongo
 * 	Data: 01/05/2022
 * 	Descrição: Este programa le as datas de nascimento
 * 	de dois amigos e indica quem é o mais velho.
 */

#include <stdio.h>

#define MAX_DIA 31
#define MAX_MES 12
#define MAX_ANO 2022
#define DURACAO_MESES 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	int dia1, mes1, ano1;
	int dia2, mes2, ano2;
	int match;
	int duracao_do_mes[] = {DURACAO_MESES};

	/* Aqui vao os comandos do programa */

	/* entrada e validacao basica */
	printf("Entre com duas datas (dd mm aaaa):\n");
	match = scanf("%d %d %d", &dia1, &mes1, &ano1);

	if (match != 3)
	{
		printf("Formato: dia mes ano\n");
		return 1;
	}

	match =  scanf("%d %d %d", &dia2, &mes2, &ano2);

	if (match != 3)
	{
		printf("Formato: dia mes ano\n");
		return 1;
	}

	/* validando apenas valores positivos */
	if (
	    dia1 <= 0
	    || dia2 <= 0
	    || mes1 <= 0
	    || mes2 <= 0
	    || ano1 <= 0
	    || ano2 <= 0
	   )
	{
		printf("Data invalida\n");
		return 2;
	}

	/* validando valores de mes */
	if (mes1 > MAX_MES || mes2 > MAX_MES)
	{
		printf("Data invalida\n");
		return 2;
	}

	/* Anos bissextos: todos os anos multiplos de 400
	 *                 ou (todos os anos multiplos de 4
	 *                 e não multiplos de 100)
	 */

	/* ajustando valores para ano bissexto */
	if (ano1 % 400 == 0 || (ano1 % 4 == 0 && ano1 % 100 != 0))
	{
		duracao_do_mes[1] = 29;
	}
	else
	{
		duracao_do_mes[1] = 28;
	}

	/* validando valores de dia1 de acordo com duracao correta de meses */
	if (dia1 > duracao_do_mes[mes1 - 1])
	{
		printf("Data invalida\n");
		return 2;
	}

	/* ajustando valores para ano bissexto */
	if (ano2 % 400 == 0 || (ano2 % 4 == 0 && ano2 % 100 != 0))
	{
		duracao_do_mes[1] = 29;
	}
	else
	{
		duracao_do_mes[1] = 28;
	}

	/* validando valores de dia2 de acordo com duracao correta de meses */
	if (dia2 > duracao_do_mes[mes1 - 1])
	{
		printf("Data invalida\n");
		return 2;
	}

	/* verificando por criterio ano */
	if (ano1 < ano2)
	{
		printf("primeiro\n");
		return 0;
	}
	else if (ano2 < ano1)
	{
		printf("segundo\n");
		return 0;
	}
	
	/* verificando por criterio mes */
	if (mes1 < mes2)
	{
		printf("primeiro\n");
		return 0;
	}
	else if (mes2 < mes1)
	{
		printf("segundo\n");
		return 0;
	}

	/* verificando por criterio dia */
	if (dia1 < dia2)
	{
		printf("primeiro\n");
		return 0;
	}
	else if (dia2 < dia1)
	{
		printf("segundo\n");
		return 0;
	}
	else
	{
		printf("mesmo dia\n");
		return 0;
	}
}

/*
	Saidas:

	Em caso de entrada valida:

		Entre com duas datas (dd mm aaaa):
		7 8 1988
		6 8 1988
		segundo
		
		Entre com duas datas (dd mm aaaa):
		6 8 1988
		7 8 1988
		primeiro

		Entre com duas datas (dd mm aaaa):
		7 8 1988
		7 8 1988
		mesmo dia

	Em caso de entrada invalida:

		Entre com duas datas (dd mm aaaa):
		foo   
		Formato: dia mes ano

		Entre com duas datas (dd mm aaaa):
		29 2 1990
		7 8 1988
		Data invalida
*/

