/*
 * 	Programa: L05e06.c
 * 	Autor: Fernando Giongo
 * 	Data: 30/05/2022;
 * 	Descrição: Este programa le uma matriz 5 x 4 contendo as seguintes
 * 	informacoes na forma de numeros inteiros:
 *
 * 	primeira coluna: numero de matricula
 * 	segunda coluna: media das provas
 * 	terceira coluna: media dos trabalhos
 * 	quarta coluna: nota final
 *
 * 	o programa:
 * 	(a) le as tres primeiras informacoes de cada aluno
 * 	(b) calcula a nota final como a soma da media das provas e da media
 * 	    dos trabalhos
 * 	(c) imprime a matricula do aluno que obteve a maior nota final
 * 	    (assumendo que so existe uma maior nota)
 * 	(d) imprime a media aritmetica das notas finais
 */

#include <stdio.h>

#define LINES 5
#define COLUMNS 4

void matrix_input_notas(int line, int col, int *matrix);
void input_flush(void);

int main (void)
{
    int matriz[LINES][COLUMNS];

    matrix_input_notas(LINES, COLUMNS, &matriz[0][0]);
    return 0;
}

void matrix_input_notas(int line, int col, int *matrix)
{
    int i, j;

    printf("\nEntrada de dados:\n");
    printf("(1) Numero de matricula\n");
    printf("(2) Media das provas\n");
    printf("(3) Media dos trabalhos\n");

    for (i = 0; i < line; i++)
    {
        printf("\nInserir os %d valores(separados por espaco) para aluno no. %d:\n", col - 1, i + 1);
        for (j = 0; j < col; j++)
        {
            if (j == 3) continue;
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

void calcular_media(int lines, int cols, int *matrix)
{
    int i, j, *final;

    for (i = 0; i < lines; i++)
    {
        final_ptr = matrix + i * cols + (cols - 1);

        for (int j = 0; j < cols; j++)
        {
            if (j == 0 || j == cols - 1) continue;
            *final_ptr += *(matrix + i * cols + j);
        }
    }
}
