#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


//A is rock, B is paper, C is scissors
//X is rock, Y is paper, Z is Scissors


int main()
{
	std::string line{};
	std::ifstream aoc;
	int total_score_pt1{0};
	int total_score_pt2{0};
	aoc.open("aoc2.txt");
	if (aoc.is_open())
		// part 2 forces me to choose, now X means i need to lose, Y means draw and Z means win
	{
		while (std::getline(aoc, line))
		{
			char* char_line = &line[0];
			if (char_line[2] == 'X')
				total_score_pt1+=1;
			if (char_line[2] == 'Y')
				total_score_pt1+=2;
			if (char_line[2] == 'Z')
				total_score_pt1+=3;
			//didnt use switch() because i couldnt get it to work hehe
			//part 1
			{ 
				if (char_line[0] == 'A' && char_line[2] == 'Y' || char_line[0] == 'B' && char_line[2] == 'Z' || char_line[0] == 'C' && char_line[2] == 'X')
					total_score_pt1 += 6;
				if (char_line[0] == 'A' && char_line[2] == 'X' || char_line[0] == 'B' && char_line[2] == 'Y' || char_line[0] == 'C' && char_line[2] == 'Z')
					total_score_pt1 += 3;
			}
			//part 2

					//A is rock, B is paper, C is scissors
					//X is rock, Y is paper, Z is Scissors	
					//1 point for rock, 2 points for paper, 3 points for scissors
			{
				if (char_line[2] == 'X') // i have to lose
				{
					total_score_pt2 += 0;
					switch(char_line[0])
					{
						case 'A': total_score_pt2 += 3; break;
						case 'B': total_score_pt2 += 1; break;
						case 'C': total_score_pt2 += 2; break;
					}
				}
				if (char_line[2] == 'Y') // i have to draw
				{
					total_score_pt2 += 3;
					switch (char_line[0])
					{
					case 'A': total_score_pt2 += 1; break;
					case 'B': total_score_pt2 += 2; break;
					case 'C': total_score_pt2 += 3; break;
					}
				}
				if (char_line[2] == 'Z') // i have to win
				{
					total_score_pt2 += 6;
					switch (char_line[0])
					{
					case 'A': total_score_pt2 += 2; break;
					case 'B': total_score_pt2 += 3; break;
					case 'C': total_score_pt2 += 1; break;
					}
				}
			}
			
		}
		std::cout << "Part 1 score is: " << total_score_pt1 << " Part 2 score is: " << total_score_pt2;
		return 0;
	}

}