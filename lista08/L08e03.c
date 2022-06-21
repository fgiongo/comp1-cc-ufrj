/* Nome do arquivo: L08e03
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le as coordenadas de dois pontos e imprime a distancia
 * entre eles.
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

float distancia(PONTO a, PONTO b);

int main (void)
{
    PONTO p1, p2;

    printf("Entre com as coordenadas do ponto p1\n");
    scanf("%f %f", &p1.x, &p1.y);
    printf("Entre com as coordenadas do ponto p2\n");
    scanf("%f %f", &p2.x, &p2.y);

    printf("Distancia entre p1 e p2: %f\n", distancia(p1, p2));

    return 0;
}

float distancia(PONTO a, PONTO b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

/* saida

Entre com as coordenadas do ponto p1
1 -2
Entre com as coordenadas do ponto p2
4 2
Distancia entre p1 e p2: 5.000000

*/

