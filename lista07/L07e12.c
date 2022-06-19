/*
 * 	Programa: L07e12
 * 	Autor: Fernando Giongo
 * 	Data: 19/06/2022
 * 	Descrição:
 */

#include <stdio.h>

void converter(int numBase10, int numBase2[32]);

int main (void)
{
    int nb10, nb2[32], i, teste = 1;

    while (1)
    {
        scanf("%d", &nb10);
        if (nb10 < 0) break;

        converter(nb10, nb2);

        printf("Teste %d\n", teste++);
        printf("%d\n", nb10);

        for (i = 31; i > 0; i--)
            printf("%d", nb2[i]);

        printf("\n\n");
    }
    
	return 0;
}

void converter (int numBase10, int numBase2[32])
{
    int i;

    for (i = 0; i < 32; i++)
        numBase2[i] = 0;

    for (i = 1; numBase10 > 0; i++)
    {
        if (i > 31) break;
        numBase2[i] = numBase10 % 2;
        numBase10 /= 2;
    }
}

/* saida

5
Teste 1
0000000000000000000000000000101

9
Teste 2
9
0000000000000000000000000001001

13
Teste 3
13
0000000000000000000000000001101

0
Teste 4
0
0000000000000000000000000000000

-1

*/
