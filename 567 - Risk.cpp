#include <cstdio>

#define TAM 21

int m[TAM][TAM];
int t;
int calcularDist(int origem, int destino) {
	int i = 0, j, k, tam = 0, nivelAtual = 1;
	int vetor[TAM], nivel[TAM];

	for (j = 0; j < TAM; j++) {
		nivel[j] = -1;
	}

	nivel[origem] = 0;

	vetor[tam++] = origem;
	while (i < TAM) {
		j = vetor[i];
		for (k = 1; k < TAM; k++) {
			if (m[j][k] == 1 && nivel[k] == -1) {
				if (k == destino) {
					return nivel[j] + 1;
				}
				vetor[tam++] = k;
				nivel[k] = nivel[j] + 1;
			}
		}
		i++;
	}
}


int main()
{
	int i, j, res, casosTeste, origem, destino, vizinho, ind = 1;
	while (true) {

		for (i = 1; i < TAM; i++) {
			for (j = 1; j < TAM; j++) {
				m[i][j] = 0;
			}
		}

		for (i = 1; i < (TAM - 1); i++) {
			if (scanf("%d", &t) == EOF) {
				return 0;
			}
			for (j = 0; j < t; j++) {
				scanf("%d", &vizinho);
				m[i][vizinho] = 1;
				m[vizinho][i] = 1;
			}
		}


		scanf("%d", &casosTeste);
		printf("Test Set #%d\n", ind);
		for (i = 0; i < casosTeste; i++) {
			scanf("%d %d", &origem, &destino);
			printf("%2d to %2d:%2d\n", origem, destino, calcularDist(origem, destino));
		}
		printf("\n");
		ind++;
	}
	return 0;
}
