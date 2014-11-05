#include <cstdio>
#include <iostream>
#include <stack>

#define TAM 15

using namespace std;

int n;
int qtde;
int colQueen[TAM];
int rowQueen[TAM];
char board[TAM][TAM];
int passou[TAM][TAM];

bool valida(int col, int row)
{
	int i;
	if (board[col][row] == '*' || passou[col][row])
	{
		return false;
	}
	for (i = 0; i < col; i++)
	{
		if (colQueen[i] == row ||
			colQueen[i] - i == row - col ||
			colQueen[i] + i == row + col)
		{
			return false;
		}
	}
	return true;
}

bool forRow(stack<int> &pilha)
{
	int i;
	int top = pilha.top();
	for (i = 0; i < n; i++)
	{
		if (valida(top, i))
		{
			colQueen[top] = i;
			passou[top][i] = 1;
			pilha.push(top + 1);
			return true;
		}
	}
	return false;
}

void queenBack(int col)
{
	int i;
	stack<int> pilha;
	pilha.push(col);

	while (pilha.size() > 0)
	{
		int top = pilha.top();
		if (top == n)
		{
			qtde++;
			pilha.pop();
			continue;
		}
		if (forRow(pilha))
		{
			continue;
		}
		colQueen[top] = 0;
		for (i = 0; i < n; i++)
		{
			passou[top][i] = 0;
		}
		pilha.pop();
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
				passou[i][j] = 0;
			}
		}

		queenBack(0);

		printf("Case %d: %d\n", nroCasos, qtde);
		nroCasos++;
	}
	return 0;
}
