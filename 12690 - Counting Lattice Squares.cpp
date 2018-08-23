#include <iostream>
#include <algorithm>

int main()
{
	int m, n;

	while (1)
	{
		std::cin >> m >> n;

		if (!m && !n) return 0;

		const uint64_t max = std::max(m, n) + 1;
		const uint64_t min = std::min(m, n) + 1;

		uint64_t result = 0;
		for (uint64_t i = 2; i <= min; i += 2)
		{
			const uint64_t pow = min - i + 1;
			result += (i - 1) * ((min - i + 1) * (max - min) + (pow * pow));
		}
		std::cout << result << "\n";
	}
	return 0;
}
