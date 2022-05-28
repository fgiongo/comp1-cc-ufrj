/*
 * 	Programa: ex03.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/04/2022
 * 	Descrição: Este programa calcula a area de um circulo de raio igual
 * 	a 7.325.
 */

#include <stdio.h>

int main (void)
{
	/* Aqui vao as declaracoes das variaveis */

	float raio, pi, area;

	/* Aqui vao os comandos do programa */

	raio = 7.325;
	pi = 3.142;
	area = pi * raio * raio;
	
	printf("Area do circulo e %.3f\n", area);

	return 0;
}
