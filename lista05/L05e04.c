/* Nome do arquivo: L05e04.c
 * Data: 29/05/2022
 * Autor: Fernando Giongo
 * Descricao: Este programa le duas matrizes 5 x 5 de numeros inteiros, as
 * multiplica e imprime o resultado.
 */

#include <stdio.h>
#define LINES 5
#define COLS 5

void matrix_input(int *matrix, int line, int col);
void input_flush(void);
int matrix_mult(int a_lines, int a_columns, int *factor_a, 
                int b_lines, int b_columns,int *factor_b,
                int *product);
void matrix_print(int *matrix, int line, int col);

int main (void)
{
    int matriz[3][LINES][COLS];

    matrix_input(&matriz[0][0][0], 5, 5);
    printf("\n");
    matrix_input(&matriz[1][0][0], 5, 5);
    
    matrix_mult(5, 5, &matriz[0][0][0], 5, 5, &matriz[1][0][0],
                &matriz[2][0][0]);

    printf("\n");
    matrix_print(&matriz[0][0][0], 5, 5);
    printf("\n");
    matrix_print(&matriz[1][0][0], 5, 5);
    printf("\n");
    matrix_print(&matriz[2][0][0], 5, 5);

    return 0;
}

void matrix_input(int *matrix, int line, int col)
{
    int i, j;

    printf("Entrada de dados: Matriz %d x %d\n", line, col);
    for (i = 0; i < line; i++)
    {
        printf("Inserir %d valores(separados por espaco) para linha %d:\n",
                col, i + 1);
        for (j = 0; j < col; j++)
        {
            scanf("%d", matrix + i * col + j);
        }
    input_flush();
    }
}

void input_flush(void)
{
    int c;
    c = getchar();
    while (c != '\n' && c != '\r' && c != EOF) c = getchar();
}

int matrix_mult(int a_lines, int a_columns, int *factor_a, 
                int b_lines, int b_columns,int *factor_b,
                int *product)
{
    int i, j, k;

    if (a_columns != b_lines)
        return 1;

    for (i = 0; i < a_lines; i++)
    {
        for (j = 0; j < b_columns; j++)
        {
            *(product + b_columns * i + j)  = 0;
            for (k = 0; k < a_columns; k++)
            {
                *(product + b_columns * i + j)
                    += *(factor_a + a_columns * i + k)
                    * *(factor_b + b_columns * k + j);
            }
        }
    }


    return 0;
}

void matrix_print(int *matrix, int line, int col)
{
    int i, j;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < col; j++)
            printf("%8d ", *(matrix + i * col + j)); 

        printf("\n");
    }
}

/* Saida

Entrada de dados: Matriz 5 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5
Inserir 5 valores(separados por espaco) para linha 2:
6 7 8 9 10
Inserir 5 valores(separados por espaco) para linha 3:
11 12 13 14 15
Inserir 5 valores(separados por espaco) para linha 4:
16 17 18 19 20
Inserir 5 valores(separados por espaco) para linha 5:
21 22 23 24 25

Entrada de dados: Matriz 5 x 5
Inserir 5 valores(separados por espaco) para linha 1:
26 27 28 29 30
Inserir 5 valores(separados por espaco) para linha 2:
31 32 33 34 35   
Inserir 5 valores(separados por espaco) para linha 3:
36 37 38 39 40 41
Inserir 5 valores(separados por espaco) para linha 4:
41 42 43 44 45
Inserir 5 valores(separados por espaco) para linha 5:
46 47 48 49 50

       1        2        3        4        5 
       6        7        8        9       10 
      11       12       13       14       15 
      16       17       18       19       20 
      21       22       23       24       25 

      26       27       28       29       30 
      31       32       33       34       35 
      36       37       38       39       40 
      41       42       43       44       45 
      46       47       48       49       50 

     590      605      620      635      650 
    1490     1530     1570     1610     1650 
    2390     2455     2520     2585     2650 
    3290     3380     3470     3560     3650 
    4190     4305     4420     4535     4650 

*/

