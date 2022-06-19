/*
 * 	Programa: L07e10
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: O programa aloca dinamicamente um vetor de numeros inteiros,
 * 	os preenche com ints e depois imprime a soma de seus valores.
 */

#include <stdio.h>
#include <stdlib.h>

void sort_ascending(int *arr, int dim);
void print_arr_ints(int *arr, int dim);

int main (void)
{
    int i, n, *pvetor;
    float media = 0;

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

    media /= (float) n;
    printf("%f\n", media);

    sort_ascending(pvetor, n);
    print_arr_ints(pvetor, n);

    free(pvetor);

	return 0;
}

void sort_ascending(int *arr, int dim)
{
    int i, j = 0, temp;
    int changes_were_made;

    do{
        changes_were_made = 0;
        j++;
        for (i = 0; i < dim - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                changes_were_made = 1;
            }
        }
    }
    while (changes_were_made);
}

void print_arr_ints(int *arr, int dim)
{
    int i;

    for (i = 0; i < dim; i++)
    {
        if (i == dim - 1) printf("%d\n", arr[i]);
        else printf("%d, ", arr[i]);
    }
}

/* Saida

Quantos numeros?
10
1 3 2 10 5 4 9 6 7 8
5.500000
1, 2, 3, 4, 5, 6, 7, 8, 9, 10

*/

