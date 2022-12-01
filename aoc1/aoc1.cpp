#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
int main()
{
	std::string line{};
	std::ifstream aoc;
	int buffer{ 0 };
	std::vector<int> list_of_int;
	aoc.open("aoc1.txt");
	if (aoc.is_open())
	{
		while (std::getline(aoc, line))
		{

			if (!line.empty())
			{
				buffer += stoi(line);
			}
			else
			{
				buffer = 0;
			}
			list_of_int.push_back(buffer);
		}
	}
	std::cout << *std::max_element(list_of_int.begin(), list_of_int.end());
	return 0;
}