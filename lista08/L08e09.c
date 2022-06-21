/* Nome do arquivo: L08e09
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: este programa recebe de entrada dados de duas circunferencias
 * e informa se elas sao internas, externas, tangentes externas ou secantes
 */

#include <stdio.h>
#include <math.h>

typedef struct _PONTO
{
    float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA
{
    float raio;
    PONTO centro;
} CIRCUNFERENCIA;

float entrada_float(float min, float max, char *prompt);
void input_flush(void);
float distancia(PONTO a, PONTO b);

#define MAX_VALUE 1000

int main (void)
{
    CIRCUNFERENCIA c1, c2;
    float dist;

    c1.raio = entrada_float(0, MAX_VALUE, "Raio de c1: ");
    c1.centro.x = entrada_float(-MAX_VALUE, MAX_VALUE, "c1: posição X: ");
    c1.centro.y = entrada_float(-MAX_VALUE, MAX_VALUE, "c1: posição Y: ");

    c2.raio = entrada_float(0, MAX_VALUE, "Raio de c2: ");
    c2.centro.x = entrada_float(-MAX_VALUE, MAX_VALUE, "c2: posição X: ");
    c2.centro.y = entrada_float(-MAX_VALUE, MAX_VALUE, "c2: posição Y: ");
    
    dist = distancia(c1.centro, c2.centro);

    if (dist - (c1.raio + c2.raio) < 0.00001
            && dist - (c1.raio + c2.raio) > -0.00001)
    {
        printf("Circunferencias tangentes externas.\n");
        return 0;
    }

    if (dist < (c1.raio - c2.raio))
    {
        printf("Uma circunferencia interna a outra\n");
        return 0;
    }

    if (dist < (c1.raio + c2.raio))
    {
        printf("Circunferencias secantes\n");
        return 0;
    }

    if (dist > (c1.raio + c2.raio))
    {
        printf("Circunferencias externas uma a outra\n");
        return 0;
    }
    
    return 0;
}

float entrada_float(float min, float max, char *prompt)
{
    float i;
    do
    {
        printf("%s", prompt);
        if (!(scanf("%f", &i)))
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

float distancia(PONTO a, PONTO b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

/* saida

Raio de c1: 4
c1: posição X: 5
c1: posição Y: 5
Raio de c2: 2
c2: posição X: 4
c2: posição Y: 4
Uma circunferencia interna a outra

***

Raio de c1: 4
c1: posição X: 5
c1: posição Y: 5
Raio de c2: 3
c2: posição X: -2
c2: posição Y: 5
Circunferencias tangentes externas.

***

Raio de c1: 4
c1: posição X: 5
c1: posição Y: 5
Raio de c2: 3
c2: posição X: 1
c2: posição Y: 1
Circunferencias secantes

***

Raio de c1: 4
c1: posição X: 5
c1: posição Y: 5
Raio de c2: 3
c2: posição X: -3
c2: posição Y: -4
Circunferencias externas uma a outra

*/

