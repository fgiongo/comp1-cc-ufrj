/*
 * 	Programa: ex03.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Este programa recebe do usuário um valor referente ao raio de um
 * 	circulo e calcula a sua area
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	double raio, pi, area;
	int match;

	/* Aqui vao os comandos do programa */

	printf("Raio do circulo?\n");
	match = scanf("%lf", &raio);

	if (!match || raio < 0)
	{
		printf("Valor inválido.\n");
		return 1;
	}

	pi = 3.1415926535;
	area = pi * raio * raio;
	
	printf("Area do circulo e %f\n", area);

	return 0;
}
