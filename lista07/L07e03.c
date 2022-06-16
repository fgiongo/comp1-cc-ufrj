/*
 * 	Programa: L07e03
 * 	Autor: Fernando Giongo
 * 	Data: 16/02/2022
 * 	Descrição:
 * 	
 * 	O programa inicializa as variaveis do tipo int (i = 10, j = 20), declara
 * 	uma terceira variavel inteira (temp) e declara mais dois ponteiros para
 * 	inteiros (p1 e p2).
 *
 * 	Em seguida, p1 é incializado com o valor do endereço de i e p2 é iniciali-
 * 	zado com o valor do endereço de j. A variavel temp recebe o conteúdo de i
 * 	(o valor 10) por meio do uso do operador * em p1, que apontava para i.
 *
 * 	Em seguida, a variável i recebe o valor de j (20) por meio do uso do ope-
 * 	rador * em p2, que apontava para j, e também em p1, que apontava para i.
 *
 * 	Em seguida, o valor de temp (que é 10) é atribuído a j. Os valores de i e j
 * 	foram trocados um pelo outro em relação ao que eram no inicio da main.
 *
 * 	Finalmente, o programa imprime os valores de i e j (20 e 10, respectivamen-
 * 	te).
 */

#include <stdio.h>

int main (void)
{
    int i = 10, j = 20;
    int temp;
    int *p1, *p2;

    p1 = &i;
    p2 = &j;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("%d %d\n", i, j);

	return 0;
}

/* Saida

20 10

*/

