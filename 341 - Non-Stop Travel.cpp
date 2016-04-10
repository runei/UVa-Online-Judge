#include <stdio.h>
#include <stdlib.h>

#define INF 999
#define TAM 25
int m[TAM][TAM];
int dist[TAM][TAM];
int caminho[TAM][TAM];
int nroNodos;

void zerarmtriz() {
	int i, j;
	for (i = 0; i < TAM; i++) {
		for (j = 0; j < TAM; j++) {
			m[i][j] = INF;
			caminho[i][j] = 0;
			dist[i][j] = INF;
		}
	}
}

void caminho_floyd(int origem,int destino)
{
    if(caminho[origem][destino]==origem)
    {
        printf("%d",caminho[origem][destino] + 1);
        return;
    }

    else
    {
        caminho_floyd(origem,caminho[origem][destino]);
        printf(" %d",caminho[origem][destino] + 1);
    }
}

int main()
{
    int i, j, vertice, valor, adjacentes;
	int k, origem, destino, nroCaso = 1;
 
	while ((scanf("%d",&nroNodos) != EOF) && (nroNodos != 0)) {
        zerarmtriz();
		for(i=0; i<nroNodos; i++){
            scanf("%d",&adjacentes);
            for(j=1; j<=adjacentes; j++)
            {
            	
                scanf("%d %d", &vertice,&valor);
				vertice = vertice - 1;
                //m[i][vertice]=valor;
				dist[i][vertice] = valor;
            }
        }
		
		for(i=0; i<nroNodos; i++)
        {
            for(j=0; j<nroNodos; j++)
            {
                if(dist[i][j] != INF && i!=j)
					caminho[i][j] = i;
            }
        }

		for (k = 0; k < nroNodos; k++) {
			  for (i = 0; i < nroNodos; i++){
				  for (j = 0; j < nroNodos; j++) {
					  if (dist[i][j] > (dist[i][k] + dist[k][j])) {         
						 dist[i][j] = dist[i][k] + dist[k][j];
						 caminho[i][j]=caminho[k][j];
					  }
				  } 
			  }
		  }

		scanf("%d %d",&origem,&destino);
		origem = origem -1;
		destino = destino -1;

		printf("Case %d: Path = ", nroCaso);
		caminho_floyd(origem, destino);
		printf(" %d; ", (destino + 1));
		printf("%d second delay\n", dist[origem][destino]);
		nroCaso = nroCaso +1;
	}
    return 0;
}
