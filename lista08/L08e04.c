/* Nome do arquivo: L08e04
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: o programa le as coordenadas de um ponto p1 e os dados de uma
 * circunferencia c1 e imprime se o ponto esta contido dentro da circunferencia
 */

#include <stdio.h>
#include<math.h>

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
    PONTO p1;
    CIRCUNFERENCIA c1;

    printf("Entre com as coordenadas do ponto p1\n");
    scanf("%f %f", &p1.x, &p1.y);

    printf("Entre com o raio do circulo c1\n");
    scanf("%f", &c1.raio);
    printf("Entre com as coordenadas do centro do circulo c1\n");
    scanf("%f %f", &c1.centro.x, &c1.centro.y);

    if (distancia(p1, c1.centro) > c1.raio)
        printf("O ponto está fora do circulo\n");
    else printf("O ponto está dentro do circulo\n");
    
    return 0;
}

float distancia(PONTO a, PONTO b)
{
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

/* saida

Entre com as coordenadas do ponto p1                                            
0 0                                                                             
Entre com o raio do circulo c1                                                  
4                                                                               
Entre com as coordenadas do centro do circulo c1                                
3 4                                                                             
O ponto está fora do circulo                                                    
          
***

Entre com as coordenadas do ponto p1                                            
1 1                                                                             
Entre com o raio do circulo c1                                                  
4                                                                               
Entre com as coordenadas do centro do circulo c1                                
3 4                                                                             
O ponto está dentro do circulo                                                  

*/
