/* Nome do arquivo: L08e01
 * Data: 20/06/2022
 * Autor: Fernando Giongo
 * Descricao: este programa le as coordenadas de um ponto
 */

#include <stdio.h>

typedef struct _PONTO
{
    float x, y;
} PONTO;

int main (void)
{
    PONTO p;

    printf("Entre com as coordenadas do ponto p\n");
    scanf("%f %f", &p.x, &p.y);
    printf("Dados lidos\n");
    printf("Ponto p: x = %f, y = %f\n", p.x, p.y);
    return 0;
}

/* saida

Entre com as coordenadas do ponto p  
10                                   
20                                   
Dados lidos                          
Ponto p: x = 10.000000, y = 20.000000

*/

