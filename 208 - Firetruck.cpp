#include <cstdio>
#include <algorithm>

int matriz[22][22];
int aux[22][22];
int visitado[22];
int nroCase, countRoutes, streetcorners;
int max = 0;
int nros[22];

void fireback(int inicio, int fim)
{
	int i;
	if (fim == streetcorners)
	{
            countRoutes++;
            for(i = 0; i < inicio; i++)
            {
                if(i)
                    std::printf(" ");
                std::printf("%d", nros[i]);
            }
            std::puts("");
            return;
	}

	for (i = 1; i <= max; ++i)
	{
            if (visitado[i])
                continue;
            if(!matriz[fim][i])
                continue;
            if(!aux[i][streetcorners])
                continue;
            visitado[i] = 1;
            nros[inicio] = i;
            fireback(inicio+1, i);
            visitado[i] = 0;
        }
}

int main()
{
    int x, y, i, k, j;
    nroCase = 0;

    while(scanf("%d",&streetcorners)!=EOF)
    {
            nroCase++;
            countRoutes = 0;
            max = 0;
            for (i = 1; i <= 21; i++)
            {
                for (int j = 1; j <= 21; j++)
                {
                    matriz[i][j] = 0;
                    aux[i][j] = 0;
                }
            }
            while(scanf("%d %d",&x,&y),x||y)
            {
                max = std::max(max,std::max(x,y));
                matriz[x][y] = matriz[y][x] = 1;
                aux[x][y] = aux[y][x] = 1;
            }
            
            for(k = 1;k <= max; k++)
            {
                for(i = 1;i <= max; i++)
                {
                    for(j = 1;j <= max; j++)
                    {
                        if(aux[i][k] && aux[k][j])
                        {
                            aux[i][j] = 1;
                        }
                    }
                }
            }
            
            visitado[1] = 1;
            nros[0] = 1;
            std::printf("CASE %d:\n", nroCase);
            fireback(1, 1);
            std::printf("There are %d routes from the firestation to streetcorner %d.\n", countRoutes, streetcorners);
    }

    return 0;
	
}
