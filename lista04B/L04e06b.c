/*
 * 	Programa: L04e06b.c
 * 	Autor: Fernando Giongo
 * 	Data: 17/02/2022
 * 	Descrição: Programa de conversao de base numerica. Apresenta uma lista de opcoes
 * 	1. decimal para hex
 * 	2. hex para decimal
 * 	3. decimal para octal
 * 	4. octal para decimal
 * 	5. encerra
 *
 * 	O programa pede um numero na base escolhida e apresenta-lo na base desejada.
 * 	Em seguida, o programa pergunta ao usuario se ele deseja retornar ao menu
 * 	principal ou finalizar o programa.
 */

#include <stdio.h>
#include <math.h>

int main (void)
{
	int start = 1, c, match, opcao;
	long unsigned int entrada, mask;

	do
	{
		if (!start)
		{
			c = getchar();
			while (c != '\n') c = getchar();
			start = 0;
		}
		
		printf(
				"<Conversao de base>\n1. decimal para hexadecimal\n2. hexadecimal para decimal\n3. decimal para octal\n4. octal para decimal\n5. encerra\nEntre a opcao desejada: "
		      );
		match = scanf("%d", &opcao);

		if (match == 0)
		{
			c = getchar();
			while (c != '\n') c = getchar();
			continue;
		}

		if (opcao < 1 || opcao > 5) continue;

		if (opcao == 5) break;

		c = getchar();
		while (c != '\n') c = getchar();

		switch (opcao)
		{
			case 1:
				do
				{
					printf("Decimal: ");
					scanf("%lu", &entrada);
				}
				while (match == 0);

				mask = entrada & 0x8000000000000000;
				if (mask != 0x00)
					printf("Atencao: transbordamento ou numero negativo representado em complementacao a 2\n");
				printf("Hexadecimal: %lx\n", entrada);
				break;

			case 2:
				do
				{
					printf("Hexadecimal: ");
					scanf("%lx", &entrada);
				}
				while (match == 0);
				mask = entrada & 0x8000000000000000;
				if (mask != 0x00)
					printf("Atencao: transbordamento ou numero negativo representado em complementacao a 2\n");
				printf("Decimal: %lu\n", entrada);
				break;

			case 3:
				do
				{
					printf("Decimal: ");
					scanf("%lu", &entrada);
				}
				while (match == 0);

				mask = entrada & 0x8000000000000000;
				if (mask != 0x00)
					printf("Atencao: transbordamento ou numero negativo representado em complementacao a 2\n");
				printf("Octal: %lo\n", entrada);
				break;

			case 4:
				do
				{
					printf("Octal: ");
					scanf("%lo", &entrada);
				}
				while (match == 0);

				mask = entrada & 0x8000000000000000;
				if (mask != 0x00)
					printf("Atencao: transbordamento ou numero negativo representado em complementacao a 2\n");
				printf("Decimal: %lu\n", entrada);
				break;
		}
	}
	while (1);

	return 0;
}

/*

<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 1
Decimal: 20
Hexadecimal: 14
<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 2
Hexadecimal: ff
Decimal: 255
<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 3
Decimal: 10
Octal: 12
<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 4
Octal: 88
Decimal: 10
<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 4
Octal: 77
Decimal: 63
<Conversao de base>
1. decimal para hexadecimal
2. hexadecimal para decimal
3. decimal para octal
4. octal para decimal
5. encerra
Entre a opcao desejada: 5

*/
