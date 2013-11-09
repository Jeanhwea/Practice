// filename: main.c
// cmd for running: gcc main.c && ./a.out
#include<stdio.h>
int max_subseq(int *a, int n)
{
	int i, j;
	int max, sum;
	if (n <= 0)
		return 0;
	else
		max = a[0];
	for (i = 0; i < n; i++) {
		if (a[i] < max)
			max = a[i];
	}
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = i; j < n; j++) {
			sum += a[j];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}

int main()
{
	int a[99999];
	int i, n;
	FILE *in;
	in = fopen("data.in", "r");
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
		fscanf(in, "%d", &a[i]);
	printf("%d\n", max_subseq(a, n));
	fclose(in);
}
