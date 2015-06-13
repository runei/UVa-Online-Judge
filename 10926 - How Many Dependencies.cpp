#include <stdio.h>
#include <stdlib.h>

#define TAM 110

int m[TAM][TAM];
int visitado[TAM];
int count[TAM];
int t;


void dfs(int v)
{
	visitado[v] = 1;
	
	int i;
	for (i = 1; i <= t; i++)
	{
		if (m[v][i] != 0 && visitado[i] == 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	int i, j, lig, tmp, maior, posMaior;
	while (scanf("%d", &t) != EOF && t > 0)
	{
		for (i = 1; i <= t; i++)
		{
			visitado[i] = 0;
			count[i] = 0;
			for (j = 1; j <= t; j++)
			{
				m[i][j] = 0;
			}
		}

		for (i = 1; i <= t; i++)
		{
			scanf("%d", &lig);
			for (j = 0; j < lig; j++)
			{
				scanf("%d", &tmp);
				m[i][tmp] = 1;
			}
		}

		for (i = 1; i <= t; i++)
		{
				dfs(i);
				for (j = 1; j <= t; j++)
				{
					if (visitado[j])
					{
						count[i]++;
						visitado[j] = 0;
					}
				}
		}

		maior = -1;
		posMaior = -1;
		for (j = 1; j <= t; j++) {
			if (count[j] > maior) {
				maior = count[j];
				posMaior = j;
			}
		}
		printf("%d\n", posMaior);
	}
	return(0);
}
