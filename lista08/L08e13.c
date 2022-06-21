/* Nome do arquivo: L08e13
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le duas fracoes e imprime a sua soma, subtracao,
 * produto e divisao
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _FRACAO
{
    int numerador, denominador;
} FRACAO;

int entrada_int(int min, int max, char *prompt);
void input_flush(void);
FRACAO ler_fracao(void);
FRACAO soma(FRACAO a, FRACAO b);
FRACAO subtracao(FRACAO a, FRACAO b);
FRACAO multiplicacao(FRACAO a, FRACAO b);
FRACAO divisao(FRACAO a, FRACAO b);

#define MAX_32 2147483647

int main (void)
{
    FRACAO a, b, resultado;

    printf("Entrada de fracao a:\n");
    a = ler_fracao();
    printf("Entrada de fracao b:\n");
    b = ler_fracao();
    
    printf("\n\n");

    resultado = soma(a, b);
    printf("a + b = %d / %d\n", resultado.numerador, resultado.denominador);

    resultado = subtracao(a, b);
    printf("a - b = %d / %d\n", resultado.numerador, resultado.denominador);

    resultado = multiplicacao(a, b);
    printf("a * b = %d / %d\n", resultado.numerador, resultado.denominador);

    resultado = divisao(a, b);
    printf("a / b = %d / %d\n", resultado.numerador, resultado.denominador);

    return 0;
}

int entrada_int(int min, int max, char *prompt)
{
    int i;
    do
    {
        printf("%s", prompt);
        if (!(scanf("%d", &i)))
        {
            input_flush();
            continue;
        }
    }
    while(i < min || i > max);

    return i;
}

void input_flush(void)
{
    int c;
    c = getchar();
    while (c != '\n' && c != '\r' && c != EOF) c = getchar();
}

FRACAO ler_fracao(void)
{
    FRACAO fracao;

    fracao.numerador = entrada_int(-MAX_32, MAX_32, "Numerador: ");
    fracao.denominador = entrada_int(-MAX_32, MAX_32, "Denominador: ");
    if (fracao.denominador == 0)
    {
        printf("Denominador nao pode ser zero.\n");
        exit(1);
    }

    return fracao;
}

FRACAO soma(FRACAO a, FRACAO b)
{
    FRACAO soma;
    soma.denominador = a.denominador * b.denominador;
    soma.numerador = a.numerador * b.denominador + b.numerador * a.denominador;
    return soma;
}

FRACAO subtracao(FRACAO a, FRACAO b)
{
    FRACAO soma;
    soma.denominador = a.denominador * b.denominador;
    soma.numerador = a.numerador * b.denominador - b.numerador * a.denominador;
    return soma;
}

FRACAO multiplicacao(FRACAO a, FRACAO b)
{
    FRACAO mult;
    mult.denominador = a.denominador * b.denominador;
    mult.numerador = a.numerador * b.numerador;
    return mult;
}

FRACAO divisao(FRACAO a, FRACAO b)
{
    FRACAO div;
    div.denominador = a.denominador * b.numerador;
    div.numerador = a.numerador * b.denominador;
    return div;
}

/* saida

Entrada de fracao a: 
Numerador: 2         
Denominador: 3       
Entrada de fracao b: 
Numerador: 3         
Denominador: 5       
                     
                     
a + b = 19 / 15      
a - b = 1 / 15       
a * b = 6 / 15       
a / b = 10 / 9       

*/

