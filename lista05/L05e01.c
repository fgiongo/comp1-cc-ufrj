/* Nome do arquivo: L05e01.c
 * Data: 28/05/2022
 * Autor: Fernando Giongo
 * Descricao: Este programa le duas strings do teclado e faz:
 * (a) mostra as strings invertidas;
 * (b) copia / concatena as strings em outro vetor, imprimindo a resposta;
 * (c) compara duas strings e informa qual e' a maior;
 * (d) informa a string de maior tamanho;
 * (e) identifica a ocorrencia de determinado caractere na string e informa
 *     a sua posicao
 */

#include <stdio.h>

#define STR_MAX 1000000 * sizeof(char)

void print_menu(void);
void get_string(char *string, long size);
void print_inverted_string(char *string);
int string_length(char *string);
void string_cat(char *string_a, char *string_b, char *string_dest);
int string_subtract(char *string_a, char *string_b);
int string_char_position(char *string, char c);

int main (void)
{
    char strings[3][STR_MAX];
    char opcao; 

    printf("Entre com a primeira string:\n");
    get_string(strings[0], STR_MAX);

    printf("\nEntre com a segunda string:\n");
    get_string(strings[1], STR_MAX);

    print_menu();
    scanf("%c", &opcao);

    switch (opcao)
    {
        case 'a':
            print_inverted_string(strings[0]);
            printf("\n");
            print_inverted_string(strings[1]);
            printf("\n");
            break;
            
        case 'b':
            string_cat(strings[0], strings[1], strings[2]);
            printf("%s\n", strings[2]);
            break;

        case 'c':
            if (string_length(strings[0]) > string_length(strings[1]))
                printf("Primeira string e' mais longa\n");

            else if (string_length(strings[0]) < string_length(strings[1]))
                printf("Segunda string e' mais longa\n");

            else
                printf("Strings tem a mesma dimensao\n");

            break;

        case 'd':
            if (string_subtract(strings[0], strings[1]) > 0)
                printf("Primeira string tem maior valor\n");
            else if (string_subtract(strings[0], strings[1]) < 0)
                printf("Segunda string tem maior valor\n");
            else
                printf("Strings tem o mesmo valor\n");
            break;
            
        case 'e':
            getchar();
            printf("Insira o caractere desejado: ");
            scanf("%c", &opcao);
            if (string_char_position(strings[0], opcao) == 0)
                printf("Caractere nao encontrado na primeira string\n");
            else
                printf("Primeira string: caractere na posicao %d\n",
                        string_char_position(strings[0], opcao));

            if (string_char_position(strings[1], opcao) == 0)
                printf("Caractere nao encontrado na segunda string\n");
            else
                printf("Segunda string: caractere na posicao %d\n",
                        string_char_position(strings[1], opcao));
            break;

        default:
            printf("Opcao invalida\n");
            return 1;
    }

    return 0;
}

void print_menu(void)
{
    char *titulo = "Menu Principal\n";
    char *a = "(a) Inverter strings\n";
    char *b = "(b) Concatenar strings\n";
    char *c = "(c) Comparar dimensao de strings\n";
    char *d = "(d) Informar string de maior valor ASCII\n";
    char *e = "(e) Identificar posicao de caractere nas strings\n";
    char *enunc = "Selecione a opcao desejada: ";
    printf("\n%s%s%s%s%s%s%s", titulo, a, b, c, d, e, enunc);
}

void get_string(char *string, long size)
{
    int c, i = 0;
    do
    {
        c = getchar();
        
        if (c == '\n' || c == '\r' || c == EOF)
        {
            string[i] = '\0'; 
            break;
        }

        if (i >= size - 2)
        {
            string[i] = '\0'; 
            break;
        }

        string[i] = c;
        i++;
    }
    while(1);
}

void print_inverted_string(char *string)
{
    int i, length = string_length(string);
    
    for (i = length - 1; i >= 0; i--)
        putchar(string[i]);
}

int string_length(char *string)
{
    int i;

    for (i = 0; ; i++)
        if (string[i] == '\0') return i;

    return 0;
}

void string_cat(char *string_a, char *string_b, char *string_dest)
{
    int i, j;

    for (i = 0; string_a[i] != '\0'; i++)
        string_dest[i] = string_a[i];

    for (j = 0; string_b[j] != '\0'; j++, i++)
        string_dest[i] = string_b[j];

    string_dest[i] = '\0';
}

int string_subtract(char *string_a, char *string_b)
{
    int i, sum = 0;

    for (i = 0; string_a[i] != '\0'; i++)
            sum += string_a[i];

    for (i = 0; string_b[i] != '\0'; i++)
            sum -= string_b[i];

    return sum;
}

int string_char_position(char *string, char c)
{
    int i;

    for (i = 0; string[i] != '\0'; i++)
        if (string[i] == c) return ++i;

    return 0;
}

/* Saidas

Entre com a primeira string:
Esta string sera invertida

Entre com a segunda string:
e esta aqui tambem

Menu Principal
(a) Inverter strings
(b) Concatenar strings
(c) Comparar dimensao de strings
(d) Informar string de maior valor ASCII
(e) Identificar posicao de caractere nas strings
Selecione a opcao desejada: a
aditrevni ares gnirts atsE
mebmat iuqa atse e

***************************************************

Entre com a primeira string:
Esta primeira string esta imcompleta, ela prec

Entre com a segunda string:
isa ser concatenada com esta segunda.                   

Menu Principal
(a) Inverter strings
(b) Concatenar strings
(c) Comparar dimensao de strings
(d) Informar string de maior valor ASCII
(e) Identificar posicao de caractere nas strings
Selecione a opcao desejada: b
Esta primeira string esta imcompleta, ela precisa ser concatenada com esta segunda.

*****************************************************
Entre com a primeira string:
Esta e' uma pequena string.

Entre com a segunda string:
Esta segunda string e' consideravelmente maior do que a primeira.

Menu Principal
(a) Inverter strings
(b) Concatenar strings
(c) Comparar dimensao de strings
(d) Informar string de maior valor ASCII
(e) Identificar posicao de caractere nas strings
Selecione a opcao desejada: c
Segunda string e' mais longa

*******************************************************************************

Entre com a primeira string:
Esta e' uma pequena string.

Entre com a segunda string:
Esta segunda string e' consideravelmente maior do que a primeira. 

Menu Principal
(a) Inverter strings
(b) Concatenar strings
(c) Comparar dimensao de strings
(d) Informar string de maior valor ASCII
(e) Identificar posicao de caractere nas strings
Selecione a opcao desejada: d
Segunda string tem maior valor

*******************************************************************************

Entre com a primeira string:
O 'X' nessa string esta logo no inicio.

Entre com a segunda string:
Na segunda string contudo, o caractere 'X' mais pro final.

Menu Principal
(a) Inverter strings
(b) Concatenar strings
(c) Comparar dimensao de strings
(d) Informar string de maior valor ASCII
(e) Identificar posicao de caractere nas strings
Selecione a opcao desejada: e
Insira o caractere desejado: X
Primeira string: caractere na posicao 4
Segunda string: caractere na posicao 41

*/

