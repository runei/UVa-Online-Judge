#include <cstdio>
#include <iostream>

#define TAM 15

using namespace std;

int n;
int qtde;
int colQueen[TAM];
int rowQueen[TAM];
int board[TAM][TAM];

bool valida(int col, int row)
{
	int i;
	if (board[col][row] == '*' || rowQueen[row])
	{
		return false;
	}
	for (i = 0; i < col; i++)
	{
		if (colQueen[i] - i == row - col ||
			colQueen[i] + i == row + col)
		{
			return false;
		}
	}
	return true;
}

void queenBack(int col)
{
	int i;
	if (col == n)
	{
		qtde++;
		return;
	}
	for (i = 0; i < n; i++)
	{
		if (valida(col, i))
		{
			colQueen[col] = i;
			rowQueen[i] = 1;
			queenBack(col + 1);
			colQueen[col] = 0;
			rowQueen[i] = 0;
		}
	}
}

int main()
{
	int i, j;
	int nroCasos = 0;
	int testCases[10] = {0,0,0,0,0,0,0,0,0,0};

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

		queenBack(0);
		testCases[nroCasos] = qtde;
		nroCasos++;
	}

	i = 0;
	while (testCases[i] != 0)
	{
		printf("Case %d: %d\n", i+1, testCases[i]);
		i++;
	}
	
	return 0;
}
