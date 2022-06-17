/*
 * 	Programa: L07e08
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição: O programa tenta alocar o máximo de memória possível na máquina
 * 	e imprime o resultado
 */

#include <stdio.h>
#include <stdlib.h>

long max_malloc(long min_size)
{
    char *ptr;
    long step = 1;

    if (!(ptr = (char *) malloc(min_size + step))) return min_size;
    free(ptr);
    
    while ((ptr = (char *) malloc(min_size + step)))
    {
        step *= 2;
        free(ptr);
    }

    step /= 2;
    return max_malloc(min_size + step);
}

int main (void)
{
    printf("%li\n", max_malloc(0));
    return 0;
}

