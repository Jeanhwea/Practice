// filename: maxsumvh.c
#include "./main.h"
int maxsumvh(int a[][COL], int row, int col)
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
			for (j = start; j - start < col; j++) {
				if (j == start)
					sum[i][j % col] = a[i][j % col];
				else
					sum[i][j % col] =
					    a[i][j % col] +
					    sum[i][(j - 1) % col];
			}
		}
		for (j = start; j - start < col; j++) {
			max_so_far = min_so_far = sum[0][j % col];
			for (i = 0; i < row; i++) {
				max_so_far = MIN(sum[i][j % col], max_so_far);
				min_so_far = MAX(sum[i][j % col], min_so_far);
			}

			sumall = summax = summin = 0;
			for (i = 0; i < row; i++) {
				sumall += sum[i][j % col];
				summax += sum[i][j % col];
				summin += sum[i][j % col];
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
