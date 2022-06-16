/*
 * 	Programa: L07e01
 * 	Autor: Fernando Giongo
 * 	Data: 16/06/2022
 * 	Descrição: 
 *
 * 	O programa inicializa uma variavel var do tipo inteiro e um
 * 	ponteiro varPtr que aponta para essa variavel. O programa entao imprime o
 * 	endereco de var usando o operador & na variavel var, e imprime o valor de
 * 	varPtr, que é também o endereço de var printado anteriormente.
 *
 * 	Em seguida, o programa imprime o valor de var de duas maneiras: usando a
 * 	var e usando o ponteiro varPtr em conjuncao com o operador *.
 *
 * 	Em seguida, o programa imprime o endereço de var e de duas maneiras usando
 * 	os operadores &* (endereço do conteudo de) em varPtr, e *& (conteudo do
 * 	endereço de) em varPtr;
 *
 */

#include <stdio.h>

int main (void)
{
    int var;
    int *varPtr;

    var = 7;
    varPtr = &var;

    printf("O endereco de var e %p\n"
            "O valor de varPtr e %p\n", &var, varPtr);

    printf("O valor de var e %d\n"
            "O valor que varPtr aponta e %d\n", var, *varPtr);

    printf("Mostrando que * e & sao complementares\n"
            "&*varPtr = %p\n"
            "*&varPtr = %p\n",
            &*varPtr, *&varPtr);

	return 0;
}

/* Resposta do exercício: ver a descricao no cabecalho desde fonte
 *
 * Saidas:

O endereco de var e 0x7fff0756999c
O valor de varPtr e 0x7fff0756999c
O valor de var e 7
O valor que varPtr aponta e 7
Mostrando que * e & sao complementares
&*varPtr = 0x7fff0756999c
*&varPtr = 0x7fff0756999c

*/

