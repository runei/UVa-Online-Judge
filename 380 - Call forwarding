#include <cstdio>

#define MAX 8784

int M[10000][MAX];
int I;

int callfor(int y, int z, int h)
{
	if (I && z == h)
		return 9999;
	I = 1;
	if (M[z][y] != 0 && M[z][y] != -1)
		return callfor(y, M[z][y], h);
	return z;
}

int main()
{
	printf("CALL FORWARDING OUTPUT\n");
	int n;
	scanf("%d", &n);
	for (int N = 1; N <= n; ++N)
	{
		int verifica[10000];
		for (int i = 0; i < 10000; ++i)
		{
			verifica[i] = 0;
			for (int x = 0; x <= MAX; ++x)
				M[i][x] = -1;
		}
		int a, b, c, d;
		int x;
		for (;;)
		{
			scanf("%d", &a);
			if (!a)
				break;
			scanf("%d %d %d", &b, &c, &d);
			if (!verifica[a])
			{
				verifica[a] = 1;
				for (x = b + c + 1; x <= MAX; ++x)
					M[a][x] = 0;
				for (x = 0; x < b - 1; ++x)
					M[a][x] = 0;
			}
			for (x = b; x <= b + c; ++x)
				M[a][x] = d;
		}
		printf("SYSTEM %d\n", N);
		int y, z;
		while (scanf("%d", &y) && y != 9000 && scanf("%d", &z))
		{
			I = 0;
			printf("AT %04d CALL TO %04d RINGS %04d\n", y, z, callfor(y, z, z));
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
