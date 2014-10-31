#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

int matriz[22][22];
int visitado[22];
int nroCase, countRoutes;

void fireback(int inicio, int fim, std::string res)
{
	int i;
	visitado[inicio] = 1;

	if (inicio > 1)
	{
		std::stringstream sstm;
		sstm << res << " " << inicio;
		res = sstm.str();
	}
	else
	{
		std::stringstream sstm;
		sstm << res << inicio;
		res = sstm.str();
	}

	if (inicio == fim)
	{
		std::cout << res << std::endl;
		visitado[inicio] = 0;
		countRoutes++;
		return;
	}

	for (i = 1; i <= 21; i++)
	{
		if (!visitado[i])
		{
			if (matriz[inicio][i])
			{
				fireback(i, fim, res);
				continue;
			}
			if (matriz[i][inicio])
			{
				fireback(i, fim, res);
			}
		}
	}
	visitado[inicio] = 0;
}

int main()
{
	int streetcorners, x, y, i;
	std::string res;
	nroCase = 0;


	while (std::cin >> streetcorners)
	{
		nroCase++;
		countRoutes = 0;
		for (i = 1; i <= 21; i++)
		{
			visitado[i] = 0;
			for (int j = 1; j <= 21; j++)
			{
				matriz[i][j] = 0;
			}
		}

		do
		{
			std::cin >> x >> y;
			matriz[x][y] = 1;
		} while (x != 0 && y != 0);

		std::cout << "CASE " << nroCase << ":" << std::endl;
		fireback(1, streetcorners, res);
		std::cout << "There are " << countRoutes << " from the firestation to streetcorner " 
			<< streetcorners << "." << std::endl;
	}

	return 0;
	
}
