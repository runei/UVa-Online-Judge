#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct person {
	std::string name;
	int parent;
	std::vector<int> children;
};

struct search {
	explicit search(std::string str) : _str(str) {}
	inline bool operator () (const person & p) { return p.name == _str; }

private:
	std::string _str;
};

int pos_in_vector(std::vector<struct person> & vector, const std::string & str)
{
	struct search search_in_vector(str);
	auto f = std::find_if(vector.begin(), vector.end(), search_in_vector);
	if (f == vector.end())
	{
		struct person p { str, -1, {} };
		vector.push_back(p);
		return vector.size() - 1;
	}

	return std::distance(vector.begin(), f);
}

int insert(std::vector<struct person> & vector, const std::string & child, const std::string & parent)
{
	if (child == "no.child")
	{
		return 0;
	}

	const int pos_parent = pos_in_vector(vector, parent);

	const int pos_child = pos_in_vector(vector, child);

	vector[pos_parent].children.push_back(pos_child);

	vector[pos_child].parent = pos_parent;

	return 1;
}

int depth(std::vector<struct person> people, int pos)
{
	int d{ 0 };

	while (people[pos].parent >= 0)
	{
		pos = people[pos].parent;
		d++;
	}
	return d;
}

int findLowestCommonAncestor(std::vector<struct person> people, int pos_first, int depth_first, int pos_second, int depth_second)
{
	while (depth_first != depth_second && depth_first >= 0 && depth_second >= 0)
	{
		if (depth_first > depth_second)
		{
			pos_first = people[pos_first].parent;
			depth_first--;
		}
		else
		{
			pos_second = people[pos_second].parent;
			depth_second--;
		}
	}

	if (depth_first < 0 || depth_second < 0)
	{
		return -1;
	}

	while (pos_first != pos_second)
	{
		pos_first = people[pos_first].parent;
		pos_second = people[pos_second].parent;
	}

	return pos_first;
}

int main()
{
	std::string child;
	std::string parent;

	std::vector<struct person> people{};

	do {
		std::cin >> child >> parent;
	} while (insert(people, child, parent));


	while (std::cin >> child >> parent)
	{
		int pos_child{ pos_in_vector(people, child) };
		int pos_parent{ pos_in_vector(people, parent) };

		int depth_child{ depth(people, pos_child) };
		int depth_parent{ depth(people, pos_parent) };

		int lca{ findLowestCommonAncestor(people, pos_child, depth_child, pos_parent, depth_parent) };

		int dist{ std::abs(depth_child - depth_parent) };

		if (lca >= 0)
		{
			std::string res{ "" };
			if (lca == pos_child)
			{
				res = "parent";
			}
			else if (lca == pos_parent)
			{
				res = "child";
			}
			else
			{
				int depth_lca{ depth(people, lca) };
				int dist_n{ std::abs(depth_lca - depth_child) - 1 };
				int dist_m{ std::abs(depth_lca - depth_parent) - 1 };

				int k{ std::min(dist_n, dist_m) };
				int j{ std::abs(dist_n - dist_m) };

				if (!k && !j)
				{
					std::cout << "sibling" << std::endl;
				}
				else
				{
					std::cout << k << " cousin";

					if (j) {
						std::cout << " removed " << j;
					}

					std::cout << std::endl;
				}

				continue;
			}

			if (--dist)
			{
				res = "grand " + res;
			}

			while (--dist > 0)
			{
				res = "great " + res;
			}
			std::cout << res << std::endl;
		}
		else
		{
			std::cout << "no relation" << std::endl;
		}
	}

	return 0;
}
