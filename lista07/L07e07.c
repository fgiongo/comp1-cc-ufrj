/*
 * 	Programa: L07e07
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: O programa aloca dinamicamente um vetor de numeros inteiros,
 * 	os preenche com ints e depois imprime a soma de seus valores.
 */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int i, n, *pvetor;
    float media;

    printf("Quantos numeros?\n");
    scanf("%d", &n);

    pvetor = (int *) malloc(n * sizeof(int));
    if (!pvetor)
    {
        puts("Sem memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
        scanf("%d", pvetor + i);

    for (i = 0; i < n; i++)
        media += *(pvetor + i);

    printf("%f\n", media);

    free(pvetor);

	return 0;
}

/* Saida

Quantos numeros?
10
1
2
3
4
5
6
7
8
9
10
55.000000

*/

