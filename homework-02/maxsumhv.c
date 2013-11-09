// filename: maxsumhv.c
#include "./main.h"
int maxsumhv(int a[][COL], int row, int col)
{
	int i, j, start;
	int max_so_far, min_so_far, ret;
	int summax, summin, sumall;
	int sum[ROW][COL];

	ret = a[0][0];
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			ret = MAX(a[i][j], ret);

	if (ret < 0)
		return ret;

	for (start = 0; start < row; start++) {
		for (j = 0; j < col; j++) {
			for (i = start; i - start < row; i++) {
				if (i == start)
					sum[i % row][j] = a[i % row][j];
				else
					sum[i % row][j] =
					    a[i % row][j] +
					    sum[(i - 1) % row][j];
			}
		}
		for (i = start; i - start < row; i++) {
			max_so_far = min_so_far = sum[i % row][0];
			for (j = 0; j < col; j++) {
				max_so_far = MIN(sum[i % row][j], max_so_far);
				min_so_far = MAX(sum[i % row][j], min_so_far);
			}

			sumall = summax = summin = 0;
			for (j = 0; j < col; j++) {
				sumall += sum[i % row][j];
				summax += sum[i % row][j];
				summin += sum[i % row][j];
				max_so_far = MAX(max_so_far, summax);
				min_so_far = MIN(min_so_far, summin);
				summax = MAX(summax, 0);
				summin = MIN(summin, 0);
			}
			ret = MAX(ret, MAX(sumall - min_so_far, max_so_far));
		}
	}
	return ret;
}
