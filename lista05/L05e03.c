/* Nome do arquivo: L05e03.c
 * Data: 28/05/2022
 * Autor: Fernando Giongo
 * Descricao: Este programa le uma sequencia de 10 numeros inteiros e informa:
 * (a) o maior valor da lista
 * (b) o menor valor da lista
 * (c) quantos valores sao pares
 * (d) a soma de todos os valores
 * (e) ao usuario se um determinado valor esta no vetor ou nao
 */

#include <stdio.h>

#define DIM 10

void fill_array(int *array, int size);
void print_menu(void);
int array_greatest(int *arr, int dim);
int array_lowest(int *arr, int dim);
int array_sum(int *arr, int dim);
int array_pairs_amt(int *arr, int dim);
int array_search(int query, int *arr, int dim);

int main (void)
{
    int valores[DIM], query;
    char opcao;

    fill_array(valores, DIM);
    print_menu();
    getchar();
    scanf("%c", &opcao);

    switch (opcao)
    {
        case 'a':
            printf("%d\n", array_greatest(valores, DIM));
            break;

        case 'b':
            printf("%d\n", array_lowest(valores, DIM));
            break;

        case 'c':
            printf("%d\n", array_pairs_amt(valores, DIM));
            break;

        case 'd':
            printf("%d\n", array_sum(valores, DIM));
            break;

        case 'e':
            getchar();
            printf("Qual valor deseja buscar? ");
            scanf("%d", &query);
            if (array_search(query, valores, DIM) == 0)
                printf("Valor nao encontrado.\n");
            else
                printf("Valor %d encontrado na posicao %d\n",
                        query, array_search(query, valores, DIM));
            break;

        default:
            printf("Opcao invalida\n");
            return 1;
    }

    return 0;
}

void fill_array(int *array, int size)
{
    int i, match;
    for (i = 0; i < size; i++)
    {
        printf("Entre valor no. %d: ", i + 1);
        do
        {
            match = scanf("%d", &array[i]);
        }
        while (match == 0);
    }
}

void print_menu(void)
{
    char *title = "\nMenu Principal\n";
    char *a = "(a) exibir maior valor da lista\n";
    char *b = "(b) exibir menor valor da lista\n";
    char *c = "(c) exibir numero de valores pares\n";
    char *d = "(d) exibir soma de todos os valores\n";
    char *e = "(e) buscar valor na lista\n";
    char *enunc = "\nSelecione uma opcao: ";
    printf("%s%s%s%s%s%s%s", title, a, b, c, d, e, enunc);
}


int array_greatest(int *arr, int dim)
{
    int i, greatest;
    for (i = 0, greatest = 0; i < dim; i++)
        if (arr[i] > greatest) greatest = arr[i];

    return greatest;
}

int array_lowest(int *arr, int dim)
{
    int i, lowest;
    for (i = 0, lowest = arr[0]; i < dim; i++)
        if (arr[i] < lowest) lowest = arr[i];

    return lowest;
}

int array_pairs_amt(int *arr, int dim)
{
    int i, pairs;
    for (i = 0, pairs = 0; i < dim; i++)
        if (arr[i] % 2 == 0) pairs++;

    return pairs;
}

int array_sum(int *arr, int dim)
{
    int i, sum;
    for (i = 0, sum = 0; i < dim; i++)
        sum += arr[i];

    return sum;
}

int array_search(int query, int *arr, int dim)
{
    int i;
    for (i = 0; i < dim; i++)
        if (arr[i] == query) return i + 1;

    return 0;
}

/* Saida

Entre valor no. 1: 45
Entre valor no. 2: 234
Entre valor no. 3: 567
Entre valor no. 4: 23
Entre valor no. 5: 76
Entre valor no. 6: 123
Entre valor no. 7: 7631
Entre valor no. 8: 76
Entre valor no. 9: 42
Entre valor no. 10: 1352

Menu Principal
(a) exibir maior valor da lista
(b) exibir menor valor da lista
(c) exibir numero de valores pares
(d) exibir soma de todos os valores
(e) buscar valor na lista

Selecione uma opcao: a
7631

*******************************************************************************

Entre valor no. 1: 123
Entre valor no. 2: 5
Entre valor no. 3: 3476
Entre valor no. 4: 23435
Entre valor no. 5: 37567
Entre valor no. 6: 34
Entre valor no. 7: 7
Entre valor no. 8: 324  
Entre valor no. 9: 7537
Entre valor no. 10: 2371

Menu Principal
(a) exibir maior valor da lista
(b) exibir menor valor da lista
(c) exibir numero de valores pares
(d) exibir soma de todos os valores
(e) buscar valor na lista

Selecione uma opcao: b
5

*******************************************************************************

Entre valor no. 1: 1
Entre valor no. 2: 2
Entre valor no. 3: 3
Entre valor no. 4: 4
Entre valor no. 5: 5
Entre valor no. 6: 6
Entre valor no. 7: 7
Entre valor no. 8: 8
Entre valor no. 9: 9
Entre valor no. 10: 10

Menu Principal
(a) exibir maior valor da lista
(b) exibir menor valor da lista
(c) exibir numero de valores pares
(d) exibir soma de todos os valores
(e) buscar valor na lista

Selecione uma opcao: c
5

*******************************************************************************

Entre valor no. 1: 1
Entre valor no. 2: 2
Entre valor no. 3: 3
Entre valor no. 4: 4
Entre valor no. 5: 5
Entre valor no. 6: 6
Entre valor no. 7: 7
Entre valor no. 8: 8
Entre valor no. 9: 9
Entre valor no. 10: 10

Menu Principal
(a) exibir maior valor da lista
(b) exibir menor valor da lista
(c) exibir numero de valores pares
(d) exibir soma de todos os valores
(e) buscar valor na lista

Selecione uma opcao: d
55

*******************************************************************************

Entre valor no. 1: 7854
Entre valor no. 2: 234
Entre valor no. 3: 8754
Entre valor no. 4: 248
Entre valor no. 5: 85
Entre valor no. 6: 2548
Entre valor no. 7: 2
Entre valor no. 8: 4578
Entre valor no. 9: 8537
Entre valor no. 10: 1000

Menu Principal
(a) exibir maior valor da lista
(b) exibir menor valor da lista
(c) exibir numero de valores pares
(d) exibir soma de todos os valores
(e) buscar valor na lista

Selecione uma opcao: e
Qual valor deseja buscar? 2548
Valor 2548 encontrado na posicao 6

*/

