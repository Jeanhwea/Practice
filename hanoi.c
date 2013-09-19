// filename: hanoi.c
// cmd to run: gcc hanoi.c && ./a.out <N> <M>
#include<stdio.h>
int hanoi(int N, int M);
int hanoi5(int n);
int hanoi7(int n);
int main(int argc, char *argv[])
{
	int N, M;
	if (argc != 3) {
		printf("usage: ./a.out <number_N> <number_M>\n");
		return 0;
	}
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	printf("(N, M) = (%d, %d)\n", N, M);
	printf("answer = %d\n", hanoi(N, M));
	return 0;
}

int hanoi(int N, int M)
{
	if (M == 5)
		return hanoi5(N);
	else if (M == 7)
		return hanoi7(N);
	else
		return -1;
}

int hanoi5(int n)
{
	int q, r;
	if (n < 5)
		return 2 * n - 1;
	q = n / 4;
	r = n % 4;
	return ((2 * ((4 - r) % 4) - 1) * hanoi5(q) + 2 * r * hanoi5(q + 1));
}

int hanoi7(int n)
{
	int q, r;
	if (n < 7)
		return 2 * n - 1;
	q = n / 6;
	r = n % 6;
	return ((2 * ((6 - r) % 7) - 1) * hanoi7(q) + 2 * r * hanoi7(q + 1));
}
