/* Nome do arquivo: L08e05
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le duas quantidades de tempo e imprime a maior
 */

#include <stdio.h>

typedef struct _TEMPO
{
    int hora, minuto, segundo;
} TEMPO;

TEMPO ler_tempo(void);
void input_flush(void);

int main (void)
{
    TEMPO t1, t2;

    printf("Entre com tempo t1:\n");
    t1 = ler_tempo();

    printf("Entre com tempo t2:\n");
    t2 = ler_tempo();

    if (t1.hora > t2.hora)
    {
        printf("t1 e' maior\n");
        return 0;
    }
    else if (t2.hora > t1.hora)
    {
        printf("t2 e' maior\n");
        return 0;
    }
    
    if (t1.minuto > t2.minuto)
    {
        printf("t1 e' maior\n");
        return 0;
    }
    else if (t2.minuto > t1.minuto)
    {
        printf("t2 e' maior\n");
        return 0;
    }

    if (t1.segundo > t2.segundo)
    {
        printf("t1 e' maior\n");
        return 0;
    }
    else if (t2.segundo > t1.segundo)
    {
        printf("t2 e' maior\n");
        return 0;
    }
    else
        printf("t1 e t2 sao iguais\n");
    
    return 0;
}

TEMPO ler_tempo(void)
{
    TEMPO tempo;

    do
    {
        printf("Quantidade de horas: ");
        if(!(scanf("%d", &tempo.hora)))
        {
            input_flush();
            continue;
        }
    }
    while(tempo.hora < 0);

    do
    {
        printf("Quantidade de minutos (max 59): ");
        input_flush();
        if(!(scanf("%d", &tempo.minuto))) continue;
    }
    while(tempo.minuto < 0 || tempo.minuto > 59);
    
    do
    {
        printf("Quantidade de segundos (max 59): ");
        input_flush();
        if(!(scanf("%d", &tempo.segundo))) continue;
    }
    while(tempo.segundo < 0 || tempo.segundo > 59);

    return tempo;
}

void input_flush(void)
{
    int c;
    c = getchar();
    while (c != '\n' && c != '\r' && c != EOF) c = getchar();
}

/* saida

Entre com tempo t1:                 
Quantidade de horas: 10             
Quantidade de minutos (max 59): 23  
Quantidade de segundos (max 59): 11 
Entre com tempo t2:                 
Quantidade de horas: 9              
Quantidade de minutos (max 59): 59  
Quantidade de segundos (max 59): 59 
t1 e' maior                         

*/

