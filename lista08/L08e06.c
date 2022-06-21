/* Nome do arquivo: L08e06
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao:
 */

#include <stdio.h>

typedef struct _TEMPO
{
    int hora, minuto, segundo;
} TEMPO;

TEMPO ler_tempo(void);
void input_flush(void);
TEMPO soma_tempo(TEMPO a, TEMPO b);

int main (void)
{
    TEMPO t1, t2, t3;

    printf("Entre com tempo t1:\n");
    t1 = ler_tempo();
    
    printf("Entre com tempo t2:\n");
    t2 = ler_tempo();
    
    t3 = soma_tempo(t1, t2);
    printf("t3: %dh:%dmin:%dseg\n", t3.hora, t3.minuto, t3.segundo);

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

TEMPO soma_tempo(TEMPO a, TEMPO b)
{
    TEMPO soma;
    int vai1 = 0;

    soma.segundo = (a.segundo + b.segundo) % 60;
    if ((a.segundo + b.segundo) > 59) vai1 = 1;

    soma.minuto = (a.minuto + b.minuto + vai1) % 60;
    if ((a.minuto + b.minuto + vai1) > 59) vai1 = 1;
    else vai1 = 0;

    soma.hora = a.hora + b.hora + vai1;

    return soma;
}

/* saida

Entre com tempo t1:                 
Quantidade de horas: 10             
Quantidade de minutos (max 59): 53  
Quantidade de segundos (max 59): 42 
Entre com tempo t2:                 
Quantidade de horas: 25             
Quantidade de minutos (max 59): 49  
Quantidade de segundos (max 59): 51 
t3: 36h:43min:33seg                 

*/

