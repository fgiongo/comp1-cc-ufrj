/* Nome do arquivo: L08e07
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
int compara_tempo(TEMPO a, TEMPO b);

int main (void)
{
    TEMPO t1, t2;

    printf("Entre com tempo t1:\n");
    t1 = ler_tempo();

    printf("Entre com tempo t2:\n");
    t2 = ler_tempo();

    if (compara_tempo(t1, t2) < 0) printf("t2 e' maior\n");
    if (compara_tempo(t1, t2) > 0) printf("t1 e' maior\n");
    if (compara_tempo(t1, t2) == 0) printf("t1 e t2 sao iguais\n");

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

int compara_tempo(TEMPO a, TEMPO b)
{
    if ((a.hora - b.hora) != 0) return a.hora - b.hora;
    if ((a.minuto - b.minuto) != 0) return a.minuto - b.minuto;
    if ((a.segundo - b.segundo) != 0) return a.segundo - b.segundo;
    else return 0;
}

/* saida

Entre com tempo t1:                
Quantidade de horas: 10            
Quantidade de minutos (max 59): 10 
Quantidade de segundos (max 59): 11
Entre com tempo t2:                
Quantidade de horas: 10            
Quantidade de minutos (max 59): 10 
Quantidade de segundos (max 59): 10
t1 e' maior                        

***

Entre com tempo t1:                
Quantidade de horas: 10            
Quantidade de minutos (max 59): 10 
Quantidade de segundos (max 59): 10
Entre com tempo t2:                
Quantidade de horas: 10            
Quantidade de minutos (max 59): 10 
Quantidade de segundos (max 59): 11
t2 e' maior                        

***

Entre com tempo t1:
Quantidade de horas: 10
Quantidade de minutos (max 59): 10
Quantidade de segundos (max 59): 10
Entre com tempo t2:
Quantidade de horas: 10
Quantidade de minutos (max 59): 10
Quantidade de segundos (max 59): 10
t1 e t2 sao iguais

*/

