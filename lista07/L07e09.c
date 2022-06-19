/*
 * 	Programa: L07e09
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: O programa aloca dinamicamente um vetor de numeros inteiros,
 * 	os preenche com ints e depois imprime a soma de seus valores.
 */

#include <stdio.h>
#include <stdlib.h>

int *maiores_que_n(int *entrada, int dim_entrada, float n);

int main (void)
{
    int i, n, *pvetor, *maiores;
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
        scanf("%i", (pvetor + i));

    for (i = 0; i < n; i++)
        media += *(pvetor + i);

    media /= (float) n;
    printf("Media: %.2f\n", media);
    printf("Numeros maiores que media:\n");

    maiores = maiores_que_n(pvetor, n, media);
    if (!maiores)
    {
        free(pvetor);
        return 1;
    }
    
    for (i = 0; i < *maiores; i++)
        printf("%d ", maiores[i + 1]);

    printf("\n");
    
    free(pvetor);
    free(maiores);

	return 0;
}

int *maiores_que_n(int *entrada, int dim_entrada, float n)
{
    int i, j = 0, dim_saida = 0, *saida;

    for (i = 0; i < dim_entrada; i++)
       if(entrada[i] > n) dim_saida++;

    saida = (int *) malloc(dim_saida * sizeof(int) + 1);
    if(!saida) return saida;

    saida[j] = dim_saida;
    for (i = 0; i < dim_entrada; i++)
    {
        if(entrada[i] > n) 
        {
            saida[j + 1] = entrada[i];
            j++;
        }
    }

    return saida;
}

/* Saida

Quantos numeros?                                                                              
10                                                                                            
1 2 3 4 5 6 7 8 9 10                                                                          
Media: 5.50                                                                                   
Numeros maiores que media:                                                                    
6 7 8 9 10 

*/

