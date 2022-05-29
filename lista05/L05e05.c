/* Nome do arquivo: L05e05.c
 * Data: 29/05/2022
 * Autor: Fernando Giongo
 * Descricao: Este programa le dois vetores X e Y de 5 elementos e
 * calcula os vetores resultantes das seguintes operacoes:
 * (a) soma de cada elemento de X com o elemento da mesma posicao em Y
 * (b) multiplicacao de cada elemento de X com o elemento da mesma posicao em Y
 * (c) todos os elementos de X que nao existam em Y
 * (d) apenas os elementos que aparecem nos dois vetores
 * (e) todos os elementos de X e todos os elementos de Y que nao estao em X
 * 
 * obs.: assume-se que o usuario nao informa elementos repetidos no mesmo
 * vetor
 */

#include <stdio.h>

#define DIM 5

void matrix_input(int *matrix, int line, int col);
void input_flush(void);
void menu_print(void);
void matrix_print(int *matrix, int line, int col);
void array_sum(int *arr1, int *arr2, int dim, int *result);
void array_mult(int *arr1, int *arr2, int dim, int *result);
int array_diff(int *arr1, int *arr2, int dim, int *result);
int array_intersect(int *arr1, int *arr2, int dim, int *result);
int array_merge(int *arr1, int *arr2, int dim, int *result);

int main (void)
{
    int X[DIM], Y[DIM], resultante[DIM * 2], r_dim;
    char opcao;

    printf("Matriz X: ");
    matrix_input(X, 1, DIM);
    printf("\nMatriz Y: ");
    matrix_input(Y, 1, DIM);
    printf("\n");
    
    menu_print();
    scanf("%c", &opcao);
    
    switch (opcao)
    {
        case 'a':
            array_sum(X, Y, DIM, resultante);
            printf("\nVetor resultante:\n");
            matrix_print(resultante, 1, DIM);
            break;

        case 'b':
            array_mult(X, Y, DIM, resultante);
            printf("\nVetor resultante:\n");
            matrix_print(resultante, 1, DIM);
            break;

        case 'c':
            r_dim = array_diff(X, Y, DIM, resultante);
            printf("\nVetor resultante:\n");
            matrix_print(resultante, 1, r_dim);
            break;

        case 'd':
            r_dim = array_intersect(X, Y, DIM, resultante);
            printf("\nVetor resultante:\n");
            matrix_print(resultante, 1, r_dim);
            break;

        case 'e':
            r_dim = array_merge(X, Y, DIM, resultante);
            printf("\nVetor resultante:\n");
            matrix_print(resultante, 1, r_dim);
            break;

        default:
            printf("Opcao invalida\n");
            return 1;
    }

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

void menu_print(void)
{
    char *title = "Menu Principal\n";
    char *a = "(a) somar de cada elemento de X com o\
 elemento da mesma posicao em Y\n";
    char *b = "(b) multiplicar cada elemento de X com\
 o elemento da mesma posicao em Y\n";
    char *c = "(c) todos os elementos de X que nao existam em Y\n";
    char *d = "(d) apenas os elementos que aparecem nos dois vetores\n";
    char *e = "(e) todos os elementos de X e todos os elementos de\
 Y que nao estao em X\n";
    char *enunc = "Escolha uma opção: ";

    printf("%s\n%s%s%s%s%s\n%s", title, a, b, c, d, e, enunc);
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

void array_sum(int *arr1, int *arr2, int dim, int *result)
{
    int i;
    for (i = 0; i < dim; i++)
        result[i] = arr1[i] + arr2[i];
}

void array_mult(int *arr1, int *arr2, int dim, int *result)
{
    int i;
    for (i = 0; i < dim; i++)
        result[i] = arr1[i] * arr2[i];
}

int array_diff(int *arr1, int *arr2, int dim, int *result)
{
    int i, j, k, flag;
    for (i = 0, j = 0, flag = 0; i < dim; i++, flag = 0)
    {
        for (k = 0; k < dim; k++)
        {
            if (arr1[i] == arr2[k])
            {
                flag++;
                break;
            }
        }
        if (flag == 0)
        {
            result[j] = arr1[i];
            j++;
        }
    }

    return j;
}

int array_intersect(int *arr1, int *arr2, int dim, int *result)
{
    int i, j, k;
    for (i = 0, j = 0; i < dim; i++)
    {
        for (k = 0; k < dim; k++)
        {
            if (arr1[i] == arr2[k])
            {
                result[j] = arr1[i];
                j++;
                break;
            }
        }
    }

    return j;
}

int array_merge(int *arr1, int *arr2, int dim, int *result)
{
    int i, j, k, is_double;

    for (i = 0, j = 0, is_double = 0; i < dim; i++, is_double = 0)
    {
        result[j] = arr1[i];
        j++;

        for (k = 0; k < dim; k++)
        {
            if (arr2[i] == arr1[k])
            {
                is_double = 1;
                break;
            }
        }

        if (is_double == 0)
        {
            result[j] = arr2[i];
            j++;
        }
    }

    return j;
}

/* Saidas

Matriz X: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5

Matriz Y: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
6 7 8 9 10

Menu Principal

(a) somar de cada elemento de X com o elemento da mesma posicao em Y
(b) multiplicar cada elemento de X com o elemento da mesma posicao em Y
(c) todos os elementos de X que nao existam em Y
(d) apenas os elementos que aparecem nos dois vetores
(e) todos os elementos de X e todos os elementos de Y que nao estao em X

Escolha uma opção: a

Vetor resultante:
       7        9       11       13       15 

*******************************************************************************

Matriz X: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5

Matriz Y: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
6 7 8 9 10

Menu Principal

(a) somar de cada elemento de X com o elemento da mesma posicao em Y
(b) multiplicar cada elemento de X com o elemento da mesma posicao em Y
(c) todos os elementos de X que nao existam em Y
(d) apenas os elementos que aparecem nos dois vetores
(e) todos os elementos de X e todos os elementos de Y que nao estao em X

Escolha uma opção: b

Vetor resultante:
       6       14       24       36       50 

*******************************************************************************
Matriz X: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5

Matriz Y: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
3 4 5 6 7

Menu Principal

(a) somar de cada elemento de X com o elemento da mesma posicao em Y
(b) multiplicar cada elemento de X com o elemento da mesma posicao em Y
(c) todos os elementos de X que nao existam em Y
(d) apenas os elementos que aparecem nos dois vetores
(e) todos os elementos de X e todos os elementos de Y que nao estao em X

Escolha uma opção: c

Vetor resultante:
       1        2 
       
*******************************************************************************
       
Matriz X: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5

Matriz Y: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
3 4 5 6 7

Menu Principal

(a) somar de cada elemento de X com o elemento da mesma posicao em Y
(b) multiplicar cada elemento de X com o elemento da mesma posicao em Y
(c) todos os elementos de X que nao existam em Y
(d) apenas os elementos que aparecem nos dois vetores
(e) todos os elementos de X e todos os elementos de Y que nao estao em X

Escolha uma opção: d

Vetor resultante:
       3        4        5

*******************************************************************************

Matriz X: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
1 2 3 4 5

Matriz Y: Entrada de dados: Matriz 1 x 5
Inserir 5 valores(separados por espaco) para linha 1:
3 4 5 6 7

Menu Principal

(a) somar de cada elemento de X com o elemento da mesma posicao em Y
(b) multiplicar cada elemento de X com o elemento da mesma posicao em Y
(c) todos os elementos de X que nao existam em Y
(d) apenas os elementos que aparecem nos dois vetores
(e) todos os elementos de X e todos os elementos de Y que nao estao em X

Escolha uma opção: e

Vetor resultante:
       1        2        3        4        6        5        7 

*/

