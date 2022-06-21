/* Nome do arquivo: L08e02
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le a medida e a posicao de um circulo
 */

#include <stdio.h>

typedef struct _PONTO
{
    float x, y;
} PONTO;

typedef struct _CIRCUNFERENCIA
{
    float raio;
    PONTO centro;
} CIRCUNFERENCIA;

int main (void)
{
    CIRCUNFERENCIA c1;

    printf("Entre com o raio do circulo c1\n");
    scanf("%f", &c1.raio);
    printf("Entre com as coordenadas do centro do circulo c1\n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);
    printf("Dados lidos\n");
    printf("Circulo c1: raio = %f, x = %f, y = %f\n", c1.raio, c1.centro.x,
            c1.centro.y);

    return 0;
}

/* saida

Entre com o raio do circulo c1                          
15                                                      
Entre com as coordenadas do centro do circulo c1        
4                                                       
5                                                       
Dados lidos                                             
Circulo c1: raio = 15.000000, x = 4.000000, y = 5.000000

*/

