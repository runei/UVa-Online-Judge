#include <cstdio>

// baseado no subset sum com backtracking

int tamanho_fita, res;
int duracao_musicas[21];
int X[21], aux[21];
int qtde_musicas, distancia;

void cdback(int aux_indice, int soma)
{
    if (aux_indice != qtde_musicas) 
    {
        aux[aux_indice] = 1;
        cdback(aux_indice + 1, soma + duracao_musicas[aux_indice]);
        aux[aux_indice] = 0;
        cdback(aux_indice + 1, soma);
    }
    else
    {
        if (tamanho_fita - soma >= 0 && tamanho_fita - soma < distancia) 
        {
            distancia = tamanho_fita - soma;
            for (int i = 0; i < qtde_musicas; ++i)
                X[i] = aux[i];
        }
    }
}
 
int main() 
{
    int i, s;
    while(scanf("%d", &tamanho_fita) != EOF)
    {
        scanf("%d", &qtde_musicas);
        for (i = 0; i < qtde_musicas; ++i)
            scanf("%d", &duracao_musicas[i]);
        distancia = 10000000;
        s = 0;
        cdback(0, 0);
        for (i = 0; i < qtde_musicas; ++i)
        {
            if (X[i])
            {
                printf("%d ", duracao_musicas[i]);
                s += duracao_musicas[i];
            }
        }
        printf("sum:%d\n", s);
    }
    return 0;
}
