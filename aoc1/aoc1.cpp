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
	int part1_answer{ *std::max_element(list_of_int.begin(), list_of_int.end()) };
	int part2_answer{};
	for (int i = 0; i < 3; ++i)
	{
		int biggest_elem = *std::max_element(list_of_int.begin(), list_of_int.end());
		part2_answer += biggest_elem;
		list_of_int.erase(std::remove(list_of_int.begin(), list_of_int.end(), biggest_elem), list_of_int.end());
	}
	std::cout << "Part 1 answer is: " << part1_answer << " Part 2 answers is: " << part2_answer << std::endl;
	return 0;
}
