/* Nome do arquivo: L05e02.c
 * Data: 28/05/2022
 * Autor: Fernando Giongo
 * Descricao: Este programa le duas matrizes 2 x 3 de numeros inteiros e
 * imprime a sua soma.
 */

#include <stdio.h>

int main (void)
{
    int matriz[3][2][3], i, j, k;

    for (i = 0; i < 2; i++)
    {
        printf("Matriz %d (2 x 3):\n", i + 1);
        for (j = 0; j < 2; j++)
        {
            printf("Inserir 3 valores(separados por espaco) para linha %d: ",
                    j + 1);
            scanf("%d %d %d", &matriz[i][j][0], &matriz[i][j][1],
                    &matriz[i][j][2]);
        }
    }

    /* removendo o lixo */
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 3; k++)
                matriz[2][j][k] = 0;
    
    /* executando a soma */
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            for (k = 0; k < 3; k++)
                matriz[2][j][k] += matriz[i][j][k];

    printf("\nMatriz soma de Matriz 1 e Matriz 2\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%03d ", matriz[2][i][j]);

        printf("\n");
    }
    return 0;
}

/* Saida

Matriz 1 (2 x 3):
Inserir 3 valores(separados por espaco) para linha 1: 1 2 3
Inserir 3 valores(separados por espaco) para linha 2: 4 5 6
Matriz 2 (2 x 3):
Inserir 3 valores(separados por espaco) para linha 1: 7 8 9
Inserir 3 valores(separados por espaco) para linha 2: 10 11 12

Matriz soma de Matriz 1 e Matriz 2
008 010 012
014 016 018

*/

