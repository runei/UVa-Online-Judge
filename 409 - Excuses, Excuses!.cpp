#include <iostream>
#include <string>
#include <algorithm>

size_t findCaseInsensitive(std::string data, std::string toSearch, size_t pos = 0)
{
	// Convert complete given String to lower case
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	// Convert complete given Sub String to lower case
	std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
	// Find sub string in given string
	return data.find(toSearch, pos);
}

int main()
{
	int n = 1;
	int k, e;
	// const std::string ponctuation {"\".,!? "};

	while (std::cin >> k >> e)
	{
		std::string keyword[20];
		std::string excuse[20];

		for (int i = 0; i < k; ++i)
		{
			std::cin >> keyword[i];
		}

		for (int i = 0; i < e; ++i)
		{
			do
			{
				getline(std::cin, excuse[i]);
			} while (excuse[i].empty());
			// std::cout << excuse[i] << "\n";
		}

		int worst_excuse[20];
		int worst_excuse_occur = -1;
		int we_id = 0;

		for (int i = 0; i < e; ++i)
		{
			int occur = 0;
			for (int j = 0; j < k; ++j)
			{
				std::size_t incidence = -1;
				do {
					incidence = findCaseInsensitive(excuse[i], keyword[j], incidence + 1);
					if (incidence != std::string::npos)
					{
						if ((incidence == 0 || !std::isalpha(excuse[i][incidence-1])) && (incidence + keyword[j].length() >= excuse[i].length() || !std::isalpha(excuse[i][incidence + keyword[j].length()])))
						{
							++occur;
						}
					}
				} while (incidence != std::string::npos);
			}
			if (occur > worst_excuse_occur)
			{
				worst_excuse_occur = occur;
				we_id = 0;
				worst_excuse[we_id] = i;
				++we_id;
			}
			else if (occur == worst_excuse_occur)
			{
				worst_excuse[we_id] = i;
				++we_id;
			}
			// std::cout << occur << "\t" << excuse[i] << "\n";
		}

		std::cout << "Excuse Set #" << n << "\n";

		for (int i = 0; i < we_id; ++i)
		{
			std::cout << excuse[worst_excuse[i]] << "\n";
		}

		std::cout << "\n";

		++n;
	}

	return 0;
}
