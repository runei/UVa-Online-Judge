#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

char rule[256];
string words[101];
int n, m;

void back(int pos, string password)
{
	int i;
	if (rule[pos] == '\0')
	{
		cout <<  password << '\n';
		return;
	}
	if (rule[pos] == '#')
	{
		for (i = 0; i < n; i++)
		{
			back(pos + 1, password + words[i]);
		}
	}
	else
	{
		for (i = 0; i < 10; i++)
		{
			back(pos + 1, password + char('0' + i));
		}
	}
}

int main()
{
	int i;

	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			cin >> words[i];
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%s", rule);

			printf("--\n");
			
			back(0, "");

		}

	}
	return 0;
}
