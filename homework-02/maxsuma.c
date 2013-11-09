// filename: maxsuma.c
#include "./main.h"
int visited[ROW][COL] = { 0 };

int maxsuma(int a[][COL], int x, int y, int row, int col)
{
	int ret;
	int n1, n2, n3;
	if (x >= row || y >= col)
		return 0;
	n1 = maxsuma(a, x + 1, y, row, col);
	n2 = maxsuma(a, x, y + 1, row, col);
	n3 = n1 + n2;
	ret = (n1 > n2) ? n1 : n2;
	ret = (ret > n3) ? ret : n3;
	ret += a[x][y];
	return ret;
}
