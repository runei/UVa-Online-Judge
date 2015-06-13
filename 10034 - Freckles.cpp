#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 99999999

struct ponto
{
	float X, Y;
};

int nroSardas;

float distancia(struct ponto pontoA, struct ponto pontoB)
{
	float dist, dX, dY;

	dX = (pontoB.X - pontoA.X);
	dX = pow(dX, 2);

	dY = (pontoB.Y - pontoA.Y);
	dY = pow(dY, 2);

	dist = dX + dY;
	dist = sqrt(dist);

	return dist;
}

int menor(float vetor[])
{
	int idMenor, i, j;
	float menor;

	i = 0;
	do{
		menor = vetor[i];
		idMenor = i;
		i++;
	} while (vetor[i - 1] == -1 && i < nroSardas);

	for (j = i; j < nroSardas; j++)
	{
		if (menor > vetor[j] && vetor[j] != -1)
		{
			menor = vetor[j];
			idMenor = j;
		}
	}
	return idMenor;
}

void prim(struct ponto sardas[], float prim[])
{
	int i, j, min, k;
	float dist, vetor[100];

	prim[0] = 0;
	vetor[0] = -1;
	for (i = 1; i < nroSardas; i++)
	{
		vetor[i] = INF;
	}

	k = 0;
	for (i = 0; i < nroSardas - 1; i++)
	{
		for (j = 1; j < nroSardas; j++)
		{
			if (k != j)
			{
				dist = distancia(sardas[k], sardas[j]);
				if (vetor[j] > dist)
				{
					vetor[j] = dist;
				}
			}
		}
		k = menor(vetor);
		prim[k] = vetor[k];
		vetor[k] = -1;
	}
}

int main()
{
	int qtdeCasos, q, i, j;
	float vetorPrim[100], soma;
	struct ponto sardas[100];

	scanf("%d", &qtdeCasos);

	for (q = 0; q < qtdeCasos; q++)
	{
		scanf("%d", &nroSardas);
		for (i = 0; i < nroSardas; i++)
		{
			scanf("%f %f", &sardas[i].X, &sardas[i].Y);
		}

		prim(sardas, vetorPrim);

		soma = 0;
		for (i = 0; i < nroSardas; i++)
		{
			soma += vetorPrim[i];
		}
		if (q > 0) {
			printf("\n");
		}
		printf("%.2f\n", soma);
	}
	return 0;
}
