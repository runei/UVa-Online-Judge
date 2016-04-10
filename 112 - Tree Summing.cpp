#include <cstdio>
#include <string>

int somaFinal, flag;
char tk;

using namespace std;

void leToken()
{
	do
	{
		scanf("%c", &tk);
	} while (tk == ' ' || tk == '\n');
}

int NUM()
{
	if ((tk >= '0' && tk <= '9') || tk == '-') { 
		string num;
		num = tk;
		leToken();
		while (tk >= '0' && tk <= '9')
		{
			num = num + tk;
			leToken();
		}
		return stoi(num);
	}
}

int S(int soma)
{
	int n = NUM();
	int novaSoma = n + soma;

	if (tk == '(') 
	{
		leToken();
		if (tk == ')')
		{
			leToken();
			if (tk == '(')
			{
				leToken();
				if (tk == ')')
				{
					leToken();
					if (somaFinal == novaSoma) {
						//printf("%d\n", novaSoma);
						flag = 1;
					}
					return 1;
				}
				S(novaSoma);
				if (tk == ')')
				{
					leToken();
					return 1;
				}
			}
		}
		S(novaSoma);
		if (tk == ')')
		{
			leToken();
			if (tk == '(')
			{
				leToken();
				S(novaSoma);
				if (tk == ')')
				{
					leToken();
					return 1;
				}
			}
		}
	}
}

void leArvore()
{
	if (tk == '(')
	{
		leToken();
		S(0);
		if (tk == ')')
		{
			//leToken();
		}
	}
}

int main()
{
	while (scanf("%d", &somaFinal) != EOF) 
	{
		flag = 0;
		//scanf("%c", tokens);
		leToken();
		leArvore();
		if (flag)
		{
			printf("yes\n");
		} else {
			printf("no\n");
		}
	}
	return 0;
}
