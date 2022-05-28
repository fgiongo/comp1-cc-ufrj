/* Aluno: Fernando Giongo Oliveira */

#include <stdio.h>

int main(void)
{
	float nota, buffer;

	printf("Este programa lê duas notas de um aluno e imprime a sua média.\n");
	printf("O programa imprime se o aluno foi aprovado ou reprovado.\n");
	printf("O critério para aprovação é média maior ou igual a 5.00\n");

	printf("Entre com a primeira nota (valor de 0.00 a 10.00): ");
	int i = scanf("%f", &nota); 
	if (i == 0 || nota > 10 || nota < 0)
	{
		printf("Este programa só aceita valores entre 0.00 e 10.00\n");
		return 1;
	}

	char c;
	if ((c = getc(stdin)) != EOF && c != '\n')
	{
		printf("Este programa só aceita um valor por vez (sem espaços).\n");
		return 2;
	}

	buffer = 0.00;
	buffer += nota;

	printf("Entre com a segunda nota (valor de 0.00 a 10.00): ");
	i = scanf("%f", &nota); 
	if (i == 0 || nota > 10 || nota < 0)
	{
		printf("Este programa só aceita valores entre 0.00 e 10.00\n");
		return 1;
	}

	if ((c = getc(stdin)) != EOF && c != '\n')
	{
		printf("Este programa só aceita um valor por vez (sem espaços).\n");
		return 2;
	}

	buffer += nota;
	nota = buffer / 2;
	printf("Média: %2.2f\n", nota);
	
	if (nota >= 5.00)
	{
		printf("Aluno aprovado.\n");
	}
	else
	{
		printf("Aluno reprovado.\n");
	}

	return 0;
}

/*
Output em caso de entrada correta:

	Este programa lê duas notas de um aluno e imprime a sua média.
	O programa imprime se o aluno foi aprovado ou reprovado.
	O critério para aprovação é média maior ou igual a 5.00
	Entre com a primeira nota (valor de 0.00 a 10.00): 7.9
	Entre com a segunda nota (valor de 0.00 a 10.00): 4.5
	Média: 6.20
	Aluno aprovado.

Output em caso de entrada incorreta:

	Este programa lê duas notas de um aluno e imprime a sua média.
	O programa imprime se o aluno foi aprovado ou reprovado.
	O critério para aprovação é média maior ou igual a 5.00
	Entre com a primeira nota (valor de 0.00 a 10.00): oito
	Este programa só aceita valores entre 0.00 e 10.00
*/
