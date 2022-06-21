/* Nome do arquivo: L08e10
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le os dados de 5 jogadores e os imprime na tela na
 * ordem em que foram lidos
 */

#include <stdio.h>

typedef struct _JOGADOR
{
    int pontos;
    char nome[42];
} JOGADOR;

int entrada_int(int min, int max, char *prompt);
void input_flush(void);

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

/* saida

Dados de jogador 1:
Nome: Jose da Silva
Pontos: 3
Dados de jogador 2:
Nome: Mario de Almeida
Pontos: 5
Dados de jogador 3:
Nome: Luiz Felipe
Pontos: 1
Dados de jogador 4:
Nome: Fernando Giongo
Pontos: 2
Dados de jogador 5:
Nome: Cristiano Ronaldo
Pontos: 4


Dados de jogador 1:
Nome: Jose da Silva
Pontos: 3

Dados de jogador 2:
Nome: Mario de Almeida
Pontos: 5

Dados de jogador 3:
Nome: Luiz Felipe
Pontos: 1

Dados de jogador 4:
Nome: Fernando Giongo
Pontos: 2

Dados de jogador 5:
Nome: Cristiano Ronaldo
Pontos: 4

*/

