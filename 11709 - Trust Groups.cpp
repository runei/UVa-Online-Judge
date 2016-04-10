#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <map>
#include <cstdio>

#define MAX 1050
using namespace std;

int visitados[MAX];
int niveis[MAX];
int ma[MAX][MAX];
int n, m, maxima_ordem;

void dfs_inverso(int vert){
	//busca com grafo invertido
    visitados[vert] = 1;
    for(int i = 1; i <= n; i++) {
       if (ma[i][vert] && !visitados[i]) {
            dfs_inverso(i);
		}
	}
}

void dfs(int vert){
	//dfs por ordem
    visitados[vert] = 1;
    for(int i = 1; i <= n; i++) {
        if (ma[vert][i] && !visitados[i]) {
			dfs(i);
		}
	}
    niveis[++maxima_ordem] = vert;
}

int main() {
    int i, j; 
	
	map<string,int> mapa;

    while(scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) {
			break;
		}
		mapa.clear();
        memset(ma, 0, sizeof(ma));
        
		cin.get();
        for(i=1; i<=n; i++) {
			string str, str2;
			cin>>str;
			cin>>str2;
			str = str + " " + str2;
			mapa[str] = i;
		}
        
        for (j = 0; j < m; j++) {
			string pessoa1, sobrenome1, pessoa2, sobrenome2;
			cin>>pessoa1;
			cin>>sobrenome1;
			cin>>pessoa2;
			cin>>sobrenome2;
			pessoa1 = pessoa1 +" " + sobrenome1;
			pessoa2 = pessoa2 +" " + sobrenome2;
            ma[mapa[pessoa1]][mapa[pessoa2]] = 1;
        }

        
        memset(visitados, 0, sizeof(visitados));
		memset(niveis, 0, sizeof(niveis));


		maxima_ordem = 0;
        
		//dfs normal
        for(i = 1; i <= n; i++) {
            if(!visitados[i]) {
				dfs(i);
			}
		}

        memset(visitados, 0, sizeof(visitados));

        int grupos = 0;
        for(i = n; i > 0; i--) {
            if (!visitados[niveis[i]]) {
        		dfs_inverso(niveis[i]);
        		grupos++;
			}
		}
		printf("%d\n", grupos);
    }
    return 0;
}
