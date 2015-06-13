#include <stdio.h>
#include <stdlib.h>

int ultVetor, idFila, tam, matriz[26][26], vertAnterior[26];
char vetor[26], filaVertices[26], filaTemp[26];

int procuraIndice(char pos)
{
	int i;
	for (i = 0; i < ultVetor; i++)
	{
		if (vetor[i] == pos)
		{
			return i;
		}
	}
	vetor[ultVetor] = pos;
	ultVetor++;
	return ultVetor - 1;
}

void bfs(char c1, char c2)
{
	int k, i1, l, j;

	filaVertices[0] = c1;
	vertAnterior[0] = -1;
	idFila = 1;
	k = 0;

	while (k < tam)
	{
		i1 = procuraIndice(filaVertices[k]);
		for (j = 0; j < tam; j++)
		{
			if (matriz[i1][j] == 1)
			{
				l = 0;
				while (l < idFila)
				{
					if (filaVertices[l] == vetor[j])
					{
						break;
					}
					l++;
				}
				if (l == idFila)
				{
					filaVertices[idFila] = vetor[j];
					vertAnterior[idFila] = k;
					idFila++;
					if (vetor[j] == c2)
					{
						return;
					}
				}
			}
		}
		k++;
	}
}

int main()
{
	int m, n, i1, i2, k, j, i, qtde, q;
	char c1[50], c2[50];

	scanf("%d", &qtde);
	q = 0;
	while (q < qtde)
	{

		scanf("%d %d\n", &m, &n);

		tam = m + 1;
		ultVetor = 0;

		for (i = 0; i < tam; i++)
		{
			for (j = 0; j < tam; j++)
			{
				matriz[i][j] = 0;
			}
		}

		for (i = 0; i < m; i++)
		{
			scanf("%s %s", c1, c2);
			i1 = procuraIndice(c1[0]);
			i2 = procuraIndice(c2[0]);
			matriz[i1][i2] = 1;
			matriz[i2][i1] = 1;
		}

		for (i = 0; i < n; i++)
		{
			scanf("%s %s", c1, c2);

			bfs(c1[0], c2[0]);

			k = idFila - 1;
			j = 0;
			while (k != -1)
			{
				filaTemp[j] = filaVertices[k];
				j++;
				k = vertAnterior[k];
			}

			for (k = j - 1; k >= 0; k--)
			{
				printf("%c", filaTemp[k]);
			}

			printf("\n");
		}
		
		q++;
		if (q != qtde)
		{
			printf("\n");
		}
	}
	return 0;
}
