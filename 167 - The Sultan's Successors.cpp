#include <cstdio>

#define TAM 8

int tabuleiro[TAM][TAM];
int posQueen[TAM];
int maior;

bool valida(int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (posQueen[i] == row ||
			posQueen[i] - i == row - col ||
			posQueen[i] + i == row + col)
		{
			return false;
		}
	}
	return true;
}

void queenBack(int col, int soma)
{
	if (col == TAM)
	{
		if (soma > maior)
		{
			maior = soma;
		}
		return;
	}
	for (int i = 0; i < TAM; i++)
	{
		if (valida(col, i))
		{
			posQueen[col] = i;
			queenBack(col + 1, soma + tabuleiro[col][i]);
			posQueen[col] = 0;
		}
	}
}

int main()
{
	int qtdeTabs;

	scanf("%d", &qtdeTabs);

	while (qtdeTabs--)
	{
		maior = 0;
		for (int i = 0; i < TAM; i++)
		{
			for (int j = 0; j < TAM; j++)
			{
				scanf("%d", &tabuleiro[i][j]);
			}
		}

		queenBack(0, 0);

		printf("%5d\n", maior);
	}
	return 0;
}
