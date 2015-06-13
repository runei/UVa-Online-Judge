#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int valor;
	struct nodo *prox;
};

struct nodo *inicio = NULL, *fim = NULL;

void insere(int valor)
{
	struct nodo *novo;
	novo = (struct nodo*)malloc(sizeof(struct nodo));
	novo->valor = valor;
	novo->prox = NULL;

	if (inicio == NULL)
	{
		inicio = novo;
		fim = novo;
	}
	else
	{
		fim->prox = novo;
		fim = novo;
	}
}

int verificaM(int m, int valor)
{
	int res, regioes[101], aux, count;

	for (int i = 1; i <= valor; i++)
	{
		regioes[i] = 0;
	}

	count = 0;
	res = 1;
	for (int i = 1; i <= valor; i++)
	{
		regioes[res] = 1;
		count++;
		aux = 0;

		if (res == 13)
		{
			if (count == valor)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

		while (aux < m)
		{
			res++;
			if (res > valor)
			{
				res = 1;
			}
			if (regioes[res] == 0)
			{
				aux++;
			}
		}

	}
}

int main()
{
	int valor, m;

	do
	{
		scanf("%d", &valor);
		insere(valor);
	} while (valor > 0);

	while (inicio->valor != 0)
	{

		m = 1;

		while (verificaM(m, inicio->valor) == 0)
		{
			m++;
		}
		printf("%d\n", m);
		inicio = inicio->prox;
	}

	system("pause");
}
