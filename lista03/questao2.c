#include <stdio.h>

int main (void)
{
	/* item a */
	if ((10 > 5) || (5 > 10))
	{
		printf("a) TRUE\n");
	}
	else
	{
		printf("a) FALSE\n");
	}

	/* item b */
	if (!(5 == 6) && (5 != 6) && ((2 > 1) || (5 <= 4)))
	{
		printf("b) TRUE\n");
	}
	else
	{
		printf("b) FALSE\n");
	}

	/* item c */
	if ((11 > 2) && (5 > 30))
	{
		printf("c) TRUE\n");
	}
	else
	{
		printf("c) FALSE\n");
	}

	/* item d */
	if ((11 > 2) || (3 > 30))
	{
		printf("d) TRUE\n");
	}
	else
	{
		printf("d) FALSE\n");
	}

	return 0;
}
