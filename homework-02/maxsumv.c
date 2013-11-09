// filename: maxsumv.c
#include "./main.h"
int maxsumv(int a[][COL], int row, int col)
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

	for (start = 0; start < col; start++) {
		for (i = 0; i < row; i++) {
			for (j = start; j < col; j++) {
				if (j == start)
					sum[i][j] = a[i][j];
				else
					sum[i][j] = a[i][j] + sum[i][j - 1];
			}
		}
		for (j = start; j < col; j++) {
			max_so_far = min_so_far = sum[0][j];
			for (i = 0; i < row; i++) {
				max_so_far = MIN(sum[i][j], max_so_far);
				min_so_far = MAX(sum[i][j], min_so_far);
			}

			sumall = summax = summin = 0;
			for (i = 0; i < row; i++) {
				sumall += sum[i][j];
				summax += sum[i][j];
				summin += sum[i][j];
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
