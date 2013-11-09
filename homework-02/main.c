// filename: main.c
#include "./main.h"
extern int maxsumv(int a[][COL], int row, int col);
extern int maxsumh(int a[][COL], int row, int col);
extern int maxsuma(int a[][COL], int row, int col);
extern int maxsumvh(int a[][COL], int row, int col);
int main(int argc, char *argv[])
{
	int a[ROW][COL];
	char *filename;
	int i, j, row, col;
	int vflag, hflag, aflag;
	FILE *in;
	vflag = hflag = aflag = 0;

	switch (argc) {
	case 1:
		printf("Usage: ./run [/v | /h] <filename>\n");
		return 0;
	case 2:
		filename = argv[1];
		printf("Error: give a parameter /v or /h or both!!!\n",
		       filename);
		return 0;
	case 3:
		switch (argv[1][1]) {
		case 'v':
			vflag = 1;
			break;
		case 'h':
			hflag = 1;
			break;
		case 'a':
			aflag = 1;
			break;
		default:
			printf("Error flag: %s\n", argv[1]);
			return 0;
		}
		filename = argv[2];
		break;
	case 4:
		switch (argv[1][1]) {
		case 'v':
			vflag = 1;
			break;
		case 'h':
			hflag = 1;
			break;
		case 'a':
			aflag = 1;
			break;
		default:
			printf("Error flag: %s", argv[1]);
			return 0;
		}
		switch (argv[2][1]) {
		case 'v':
			vflag = 1;
			break;
		case 'h':
			hflag = 1;
			break;
		case 'a':
			aflag = 1;
			break;
		default:
			printf("Error flag: %s", argv[2]);
			return 0;
		}
		filename = argv[3];
		break;
	default:
		printf("Too many parameters\n");
		return 0;
	}
	if ((in = fopen(filename, "r")) == NULL) {
		printf("Fail to open file: %s\n", filename);
		return 0;
	};
	fscanf(in, "%d,", &row);
	fscanf(in, "%d,", &col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (j != (col - 1))
				fscanf(in, "%d, ", &a[i][j]);
			else
				fscanf(in, "%d\n", &a[i][j]);
		}
	}
	fclose(in);
	if (col <= 0 | row <= 0) {
		printf("Bad row value or colunm value\n");
		return 0;
	}
	if (vflag && hflag) {
		if (row > col)
			printf("%d\n", maxsumvh(a, row, col));
		else
			printf("%d\n", maxsumhv(a, row, col));
	} else if (aflag)
		printf("%d\n", maxsuma(a, row, col));
	else if (vflag)
		printf("%d\n", maxsumv(a, row, col));
	else if (hflag)
		printf("%d\n", maxsumh(a, row, col));
	return 0;
}
