/*
 * 	Programa: L07e05
 * 	Autor: Fernando Giongo
 * 	Data: 16/06/2022
 * 	Descrição:
 *
 * 	O programa pega uma cadeia e retorna a segunda palavra desta cadeia.
 * 	Isso e' feito por meio de uma funcao que percorre a cadeia e retorna um
 * 	ponteiro para o endereco apos o primeiro espaco.
 *
 * 	O programa entao imprime a cadeia, usando como endereco de referencia o
 * 	retorno da funcao. Desta forma, o programa imprime a cadeia a partir da
 * 	segunda palavra.
 */

#include <stdio.h>

char * acheSobrenome(char nome[])
{
    char *pnome;
    int i = 0;

    while (nome[i] != ' ')
    {
        i++;
    }
    i++;
    pnome = &nome[i];
    return pnome;
}

int main (void)
{
    char nomeCompleto[80];
    char *p;

    puts("Entre com o seu nome e um sobrenome.");
    gets(nomeCompleto);

    p = acheSobrenome(nomeCompleto);

    puts(p);

	return 0;
}

/* Saida

Entre com o seu nome e um sobrenome.
Fernando Giongo
Giongo

*/

