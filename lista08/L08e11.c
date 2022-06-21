/* Nome do arquivo: L08e11
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le os dados de 5 jogadores e os imprime na tela em
 * ordem decrescente
 */

#include <stdio.h>

typedef struct _JOGADOR
{
    int pontos;
    char nome[42];
} JOGADOR;

int entrada_int(int min, int max, char *prompt);
void input_flush(void);
void sort_jogadores(JOGADOR *arr, int dim);

#define MAX_32 2147483647

int main (void)
{
    int i;
    JOGADOR jogadores[5];

    for (i = 0; i < 5; i++)
    {
        printf("Dados de jogador %d:\nNome: ", i + 1);
        fgets(jogadores[i].nome, 42, stdin);
        jogadores[i].pontos = entrada_int(0, MAX_32, "Pontos: ");
        getchar();
    }

    sort_jogadores(jogadores, 5);
    
    printf("\n\n");

    for (i = 0; i < 5; i++)
    {
        printf("Dados de jogador %d:\nNome: ", i + 1);
        fputs(jogadores[i].nome, stdout);
        printf("Pontos: ");
        printf("%d\n\n", jogadores[i].pontos);
    }
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

void sort_jogadores(JOGADOR *arr, int dim)
{
    int i, j = 0, changes_made;
    JOGADOR buffer;

    do
    {
        j++;
        changes_made = 0;
        for (i = 0; i < dim - j; i++)
        {
            if (arr[i].pontos < arr[i + 1].pontos)
            {
                buffer = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buffer;
                changes_made = 1;
            }
        }
    }
    while (changes_made);
}

/*

Dados de jogador 1:
Nome: Chico Buarque
Pontos: 2
Dados de jogador 2:
Nome: Caetano Veloso
Pontos: 5
Dados de jogador 3:
Nome: Tom Jobim
Pontos: 11
Dados de jogador 4:
Nome: Luiz Melodia
Pontos: 3
Dados de jogador 5:
Nome: Luiz Bonfa
Pontos: 9


Dados de jogador 1:
Nome: Tom Jobim
Pontos: 11

Dados de jogador 2:
Nome: Luiz Bonfa
Pontos: 9

Dados de jogador 3:
Nome: Caetano Veloso
Pontos: 5

Dados de jogador 4:
Nome: Luiz Melodia
Pontos: 3

Dados de jogador 5:
Nome: Chico Buarque
Pontos: 2

*/

