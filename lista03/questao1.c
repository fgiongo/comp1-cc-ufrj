#include <stdio.h>

int item_a(int a, int c);
int item_b(int c);
float item_c_float(int b, int c, float d);
int item_c(int b, int c, float d);
float item_d_float(int a, int b, int c, float d);
int item_d(int a, int b, int c, float d);
int item_e(int a, int b, int c, int l);
int item_f(int a, int b, int c, int l);

int main (void)
{
	int A = 5;
	int B = 10;
	int C = -8;
	float D = 1.5;
	int L = 0;

	printf("Questao 1:\n");

	printf("a) %d\n", item_a(A, C));

	printf("b) %d\n", item_b(C));

	printf("c) se int,  %d\n", item_c(B, C, D));
	printf("c) se float, %f\n", item_c_float(B, C, D));

	printf("d) se float, %f\n", item_d_float(A, B, C, D));
	printf("d) se int,  %d\n", item_d(A, B, C, D));

	printf("e) %d\n", item_e(A, B, C, L));
	printf("f) %d\n", item_f(A, B, C, L));

	return 0;
}

int item_a(int a, int c)
{
	int x = 2 * a % 3 - c;
	return x;
}

int item_b(int c)
{
	int x = (-2 * c) / 4;
	return x;
}

int item_c(int b, int c, float d)
{
	int x = ((b / 3) / 3) + d * c / 2;
	return x;
}

float item_c_float(int b, int c, float d)
{
	float x = ((b / 3) / 3) + d * c / 2;
	return x;
}

int item_d(int a, int b, int c, float d)
{
	int x = (-c * 2) + (d + b) / a;
	return x;
}

float item_d_float(int a, int b, int c, float d)
{
	float x = (-c * 2) + (d + b) / a;
	return x;
}

int item_e(int a, int b, int c, int l)
{
	int x = a * c & (l | b);
	return x;
}

int item_f(int a, int b, int c, int l)
{
	int x = (!l + a < c | c + c * b >= 1 & 1);
	return x;
}
