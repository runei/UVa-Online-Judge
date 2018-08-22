#include <stdio.h>
#include <limits.h>
#include <string.h>

#define EMPTY -1

struct Item
{
	int price;
	int favour;
};

int m, n;
struct Item items[101];
int flag[101][10001];

int max(const int a, const int b)
{
	return a ^ ((a ^ b) & -(a < b));
}

int maxFavour(const int i, const int sum)
{

	if (sum > m && m < 1800)
	{
		return INT_MIN;
	}

	if (sum > m + 200)
	{
		return INT_MIN;
	}

	if (i >= n)
	{
		if (sum > 2000 || sum <= m)
		{
			return 0;
		}
		return INT_MIN;
	}

	if (flag[i][sum] != EMPTY)
	{
		return flag[i][sum];
	}

	// const int f1 = maxFavour(i + 1, sum);
	// const int f2 = items[i].favour + maxFavour(i + 1, sum + items[i].price);

	flag[i][sum] = max(maxFavour(i + 1, sum), items[i].favour + maxFavour(i + 1, sum + items[i].price));

	return flag[i][sum];
}

int main()
{
	while(scanf("%d %d", &m, &n) == 2)
	{
		int i;
		for(i = 0; i < n; i++)
		{
			scanf("%d %d", &items[i].price, &items[i].favour);
		}
		memset(flag, EMPTY, sizeof flag);

		printf("%d\n", maxFavour(0, 0));
	}

	return 0;
}
