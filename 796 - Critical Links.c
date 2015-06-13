#include <stdio.h>
#include <stdlib.h>

#define TAM 100
#define IDA 1
#define RET 2
#define PRINTADO 3

int m[TAM][TAM];
int m2[TAM][TAM];
int visitado[TAM];
int nivel[TAM];
int lowpt[TAM];
int art[TAM];
int t;


void dfs(int v, int niv)
{
	visitado[v] = 1;
	nivel[v] = niv;
	int i = 0;
	for (i = 0; i < t; i++)
	{
		if (m[v][i] != 0 && visitado[i] == 0)
		{
			m2[v][i] = IDA;
			dfs(i, niv + 1);
		}
		else if (m[v][i] != 0 && visitado[i] == 1)
		{
			if (nivel[i] > nivel[v])
			{
				m2[i][v] = RET;
			}
		}
	}
}

void lowptB(int v)
{

	int i;
	lowpt[v] = v;
	for (i = 0; i < t; i++)
	{
		if (m2[v][i] == IDA)
		{
			if (lowpt[i] == -1)
			{
				lowptB(i);
			}
			if (nivel[lowpt[i]] < nivel[lowpt[v]])
			{
				lowpt[v] = lowpt[i];
			}
		}
		if (m2[v][i] == RET)
		{
			if (nivel[i] < nivel[lowpt[v]])
			{
				lowpt[v] = i;
			}
		}
	}
}

void articulacoes(int vert)
{
	int i = 0, j, nro = 0;

	for (i = 0; i < t; i++)
	{
		if (m2[vert][i] == IDA)
		{
			nro++;
		}
	}

	if (nro > 1)
	{
		art[vert] = 1;
	}

	for (i = 1; i < t; i++)
	{
		art[i] = 0;
		for (j = 0; j < t; j++)
		{
			if (m2[i][j] == IDA)
			{
				if ((lowpt[j] == j) || (lowpt[j] == i))
				{
					art[i] = 1;
				}
			}
		}
	}
}

int main()
{
	int i, j, ki, vert, lig, tmp, conexoes;
	while (scanf("%d", &t) != EOF)
	{
		conexoes = 0;
		for (ki = 0; ki < t; ki++)
		{
			visitado[ki] = 0;
			nivel[ki] = 0;
			art[ki] = 0;
			lowpt[ki] = -1;
			for (j = 0; j < t; j++)
			{
				m2[ki][j] = 0;
				m[ki][j] = 0;
			}
		}

		for (i = 0; i < t; i++)
		{
			scanf("%d (%d)", &vert, &lig);
			for (j = 0; j < lig; j++)
			{
				scanf("%d", &tmp);
				m[vert][tmp] = 1;
			}
		}

		for (i = 0; i < t; i++)
		{
			if (lowpt[i] == -1)
			{
				dfs(i, 0);
				lowptB(i);
				articulacoes(i);
			}
		}

		for (i = 0; i < t; i++)
		{
			for (j = 0; j < t; j++)
			{
				if (m2[i][j] == IDA && (lowpt[j] == j))
				{
					conexoes++;
				}
			}
		}

		printf("%d critical links\n", conexoes);

		for (i = 0; i < t; i++)
		{
			for (j = 0; j < t; j++)
			{
				if ((m2[i][j] == IDA && (lowpt[j] == j)) || (m2[j][i] == IDA && (lowpt[i] == i)))
				{
					if (i < j)
					{
						printf("%d - %d\n", i, j);
					}
					else
					{
						printf("%d - %d\n", j, i);
					}
					m2[j][i] = PRINTADO;
					m2[i][j] = PRINTADO;
				}
			}
		}
		printf("\n");
	}
	return(0);
}
