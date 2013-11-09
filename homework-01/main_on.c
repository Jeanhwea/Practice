// filename: main_on.c
// cmd for running: gcc main.c && ./a.out
#include<stdio.h>
int max_subseq(int *a, int n)
{
	int i;
	int max, sum;
	for (i = 0; i < n; i++) {
		if (a[i] < max)
			max = a[i];
	}
	sum = 0;
	for (i = 0; i < n; i++) {
		sum += a[i];
		max = (sum > max) ? sum : max;
		if (sum < 0)
			sum = 0;
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
