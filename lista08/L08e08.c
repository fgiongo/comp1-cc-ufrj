/* Nome do arquivo: L08e08
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le os tempos gastos em ate 50 tarefas as imprime em
 * ordem crescente de tempo gasto
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _TEMPO
{
    int hora, minuto, segundo;
} TEMPO;

TEMPO ler_tempo(void);
void input_flush(void);
int compara_tempo(TEMPO a, TEMPO b);
int entrada_int(int min, int max, char *prompt);
void sort_tempos(TEMPO *tempo, int dim);
void imprime_tempos(TEMPO *tempo, int dim);

#define MAX 50
#define MAX_32 2147483647

int main (void)
{
    int i, num_tarefas;
    TEMPO *tarefas;

    num_tarefas = entrada_int(0, MAX, "Numero de tarefas (max 50): ");
    tarefas = (TEMPO *) malloc(num_tarefas * sizeof(TEMPO));
    if(!tarefas)
    {
        printf("Sem memoria.\n");
        return 1;
    }
    
    for (i = 0; i < num_tarefas; i++)
    {
        printf("Tempo para tarefa %d:\n", i + 1);
        tarefas[i].hora = entrada_int(0, MAX_32, "Horas: ");
        tarefas[i].minuto = entrada_int(0, 59, "Minutos (max 59): ");
        tarefas[i].segundo = entrada_int(0, 59, "Segundos (max 59): ");
    }

    sort_tempos(tarefas, num_tarefas);
    imprime_tempos(tarefas, num_tarefas);

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

void sort_tempos(TEMPO *tempo, int dim)
{
    int i, j = 0, changes_made;
    TEMPO buffer;

    do
    {
        j++;
        changes_made = 0;
        for (i = 0; i < dim - j; i++)
        {
            if (compara_tempo(tempo[i], tempo[i + 1]) > 0)
            {
                buffer = tempo[i];
                tempo[i] = tempo[i + 1];
                tempo[i + 1] = buffer;
                changes_made = 1;
            }
        }
    }
    while (changes_made);
}

void imprime_tempos(TEMPO *tempo, int dim)
{
    int i;

    for (i = 0; i < dim; i++)
    {
        printf("Tarefa %d: %dH, %dMIN, %dSEG\n", i + 1, tempo[i].hora,
                tempo[i].minuto, tempo[i].segundo);
    }
}

/* saida

Numero de tarefas (max 50): 5
Tempo para tarefa 1:
Horas: 12
Minutos (max 59): 10
Segundos (max 59): 43
Tempo para tarefa 2:
Horas: 16
Minutos (max 59): 5
Segundos (max 59): 21
Tempo para tarefa 3:
Horas: 8
Minutos (max 59): 10
Segundos (max 59): 20
Tempo para tarefa 4:
Horas: 10
Minutos (max 59): 30
Segundos (max 59): 15
Tempo para tarefa 5:
Horas: 15
Minutos (max 59): 44
Segundos (max 59): 3
Tarefa 1: 8H, 10MIN, 20SEG
Tarefa 2: 10H, 30MIN, 15SEG
Tarefa 3: 12H, 10MIN, 43SEG
Tarefa 4: 15H, 44MIN, 3SEG
Tarefa 5: 16H, 5MIN, 21SEG

*/

