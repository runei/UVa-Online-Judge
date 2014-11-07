#include <cstdio>

#define TAM 14

int n;
int qtde;
int colQueen[TAM];
int rowQueen[TAM];
int diagonalNeg[TAM * 2];
int diagonalPos[TAM * 2];
char board[TAM][TAM];

void queenBack(int col, int inicio, int fim)
{
	int i, iniTmp, fimTmp;
	if (col == n)
	{
		qtde++;
		return;
	}
	for (i = inicio; i < fim; i++)
	{
		if (!(board[col][i] == '*' || rowQueen[i] || diagonalNeg[i - col + n] || diagonalPos[i + col]))
		{
			colQueen[col] = i;
			rowQueen[i] = 1;
			diagonalNeg[i - col + n] = 1;
			diagonalPos[i + col] = 1;

			iniTmp = inicio;
			fimTmp = fim;

			if (i == inicio)
			{
				while (rowQueen[iniTmp] != 0)
				{
					iniTmp++;
				}
			}
			else if (i == fim - 1)
			{
				while (rowQueen[fimTmp] != 0)
				{
					fimTmp--;
				}
			}

			queenBack(col + 1, iniTmp, fimTmp);

			colQueen[col] = 0;
			rowQueen[i] = 0;
			diagonalNeg[i - col + n] = 0;
			diagonalPos[i + col] = 0;
		}
	}
}

int main()
{
	int i, j;
	int nroCasos = 1;

	while (scanf("%d", &n) != EOF && n != 0)
	{
		qtde = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf(" %c", &board[i][j]);
			}
		}

		queenBack(0, 0, n);

		printf("Case %d: %d\n", nroCasos, qtde);
		nroCasos++;
	}
	return 0;
}
