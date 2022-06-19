/*
 * 	Programa: L07e11
 * 	Autor: Fernando Giongo
 * 	Data: 19/06/2022
 * 	Descrição: O programa imprime uma string a partir de sua segunda palavra,
 * 	ou a partir do primeiro espaco.
 */

#include <stdio.h>

void misterio(char *n);

int main (void)
{
    char nome[41];
    gets(nome);

    misterio(nome);

	return 0;
}

void misterio(char *n)
{
    while(*n != ' ') n++;
    n++;
    puts(n);
}

/* saida

fernando giongo
giongo

*/

