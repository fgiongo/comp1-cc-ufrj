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
 * 	    (assumindo que so existe uma maior nota)
 * 	(d) imprime a media aritmetica das notas finais
 */

#include <stdio.h>

#define LINES 5
#define COLUMNS 4

void matrix_input_notas(int line, int col, int *matrix);
void input_flush(void);
void calcular_media(int lines, int cols, int *matrix);
void matrix_print(int line, int col, int *matrix);
int matricula_maior_nota_final(int lines, int cols, int *matrix);
float media_notas_finais(int lines, int cols, int *matrix);

int main (void)
{
    int matriz[LINES][COLUMNS];

    matrix_input_notas(LINES, COLUMNS, &matriz[0][0]);
    calcular_media(LINES, COLUMNS, &matriz[0][0]);
    printf("\n");
    matrix_print(LINES, COLUMNS, &matriz[0][0]);
    printf("\nMatricula do aluno com maior nota final: %d\n",
            matricula_maior_nota_final(LINES, COLUMNS, &matriz[0][0]));
    printf("\nMedia aritmetica das notas finais: %.2f\n",
            media_notas_finais(LINES, COLUMNS, &matriz[0][0]));
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
    int i, j, *final_ptr;

    for (i = 0; i < lines; i++)
    {
        final_ptr = matrix + i * cols + (cols - 1);
        *final_ptr = 0;

        for (j = 0; j < cols; j++)
        {
            if (j == 0 || j == cols - 1) continue;
            *final_ptr += *(matrix + i * cols + j);
        }
    }
}

void matrix_print(int line, int col, int *matrix)
{
    int i, j;
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < col; j++)
            printf("%8d ", *(matrix + i * col + j)); 

        printf("\n");
    }
}

int matricula_maior_nota_final(int lines, int cols, int *matrix)
{
    int i, final, matricula, *matricula_ptr, *final_ptr;
    final = 0;

    for (i = 0; i < lines; i++)
    {
        matricula_ptr = matrix + i * cols;
        final_ptr = matrix + i * cols + (cols - 1);
        if (*final_ptr > final)
        {
            final = *final_ptr;
            matricula = *matricula_ptr;
        }
    }
    return matricula;
}

float media_notas_finais(int lines, int cols, int *matrix)
{
    int i, final, *final_ptr;
    final = 0;

    for (i = 0; i < lines; i++)
    {
        final_ptr = matrix + i * cols + (cols - 1);
        final += *final_ptr;
    }

    return final / (float) lines;
}

/* Saidas

Entrada de dados:
(1) Numero de matricula
(2) Media das provas
(3) Media dos trabalhos

Inserir os 3 valores(separados por espaco) para aluno no. 1:
101 23 48

Inserir os 3 valores(separados por espaco) para aluno no. 2:
102 39 42

Inserir os 3 valores(separados por espaco) para aluno no. 3:
103 18 33

Inserir os 3 valores(separados por espaco) para aluno no. 4:
104 49 41

Inserir os 3 valores(separados por espaco) para aluno no. 5:
105 26 30

     101       23       48       71 
     102       39       42       81 
     103       18       33       51 
     104       49       41       90 
     105       26       30       56 

Matricula do aluno com maior nota final: 104

Media aritmetica das notas finais: 69.80

*/

