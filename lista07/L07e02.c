/*
 * 	Programa: L07e02
 * 	Autor: Fernando Giongo
 * 	Data: 16/06/2022
 * 	Descrição:
 *
 *  O programa usa uma funcao chamada troca para receber os enderecos de duas
 *  variaveis de tipo inteiro. Ele usa uma variavel local (temp) para guardar
 *  o conteudo de um dos enderecos recebidos e desta forma pode trocar os
 *  conteudos dos dois enderecos um pelo outro.
 *
 *  Finalmente o programa imprime os valores trocados.
 */

#include <stdio.h>

void troca (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main (void)
{
    int x, y;

    scanf("%d %d", &x, &y);
    troca(&x, &y);
    printf("Troquei ----> %d %d\n", x, y);
	return 0;
}

/* Saida

3 4
Troquei ----> 4 3

*/

