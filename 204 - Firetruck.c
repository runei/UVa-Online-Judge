#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct par {
	int x, y;
};

int matriz[22][22];
int visitado[22];

void fireback(int inicio, int fim, char res[], int idres)
{
	visitado[inicio] = 1;
	/*if (inicio > 9)
	{
		int x = inicio;
		char b[1], b2[1];
		sprintf(b, "%d", inicio/10);
		res[idres++] = (char)b;
		sprintf(b2, "%d", x % 10);
		res[idres] = (char)b2;
	}
	else 
	{
		char buffer[1];
		sprintf(buffer, "%d", inicio);
		res[idres] = (char)buffer;
	}
	/*strcat(res, buffer);
	strcat(res, " ");*/

	if (inicio == fim)
	{
		res = res + '\0';
		printf("%s\n", res);
		visitado[inicio] = 0;
		return;
	}

	for (int i = 1; i <= 21; i++)
	{
		if (visitado[i] == 0)
		{
			if (matriz[inicio][i])
			{
				fireback(i, fim, res + '1', idres++);
				continue;
			}
			if (matriz[i][inicio])
			{
				fireback(i, fim, res + '1', idres++);
			}
		}
	}
	visitado[inicio] = 0;
}

int main()
{
	int streetcorners, x, y, i;

	scanf("%d", &streetcorners);

	for (int i = 1; i <= 21; i++)
	{
		visitado[i] = 0;
		for (int j = 1; j <= 21; j++)
		{
			matriz[i][j] = 0;
		}
	}

	do
	{
		scanf("%d %d", &x, &y);
		matriz[x][y] = 1;
	} while (x != 0 && y != 0);

	char res[42];
	strcpy(res, "");
	fireback(1, streetcorners, res, 0);

	system("pause");
	return 0;
}
