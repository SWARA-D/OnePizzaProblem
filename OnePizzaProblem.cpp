#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool Found(string elem, vector<string> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		if (elem == items[i])
		{
			return true;
		}
	}
	return false;
}

bool Found(string elem, map<string, int> items)
{
	for (auto const &pair: items)
	{
		if (elem == pair.first)
		{
			return true;
		}
	}
	return false;
}

bool isAlphaNumeric(string elem)
{
	if (elem.length() == 0 || elem == " ")
	{
		return false;
	}
	int count = 0;
	for (int i = 0; i < elem.length(); i++)
	{
		if ((elem[i] >= 'a' && elem[i] <= 'z') || (elem[i] >= '0' && elem[i] <= '9'))
		{
			count++;
		}
	}
	
	if (count == elem.length())
	{
		return true;
	}
	return false;
}

int main()
{
	map<string, int> likedIngredients;
	map<string, int> dislikedIngredients;
	vector<string> finalToppings;

	ifstream fin("C:/Users/swara/Downloads/e_elaborate.in.txt");
	if (fin.fail())
	{
		cout << "ERROR! No input file found" << endl;
	}
	else
	{
		int numnberOfCustomers;
		while (fin.eof() == false)
		{
			fin >> numnberOfCustomers;
			int numberOfLikes;
			int numberOfDislikes;

			for (int i = 0; i < numnberOfCustomers; i++)
			{
				fin >> numberOfLikes;
				for (int j = 0; j < numberOfLikes; j++)
				{
					string ingredient;
					fin >> ingredient;
					if (isAlphaNumeric(ingredient))
					{
						if (Found(ingredient, likedIngredients))
						{
							likedIngredients.insert({ ingredient, likedIngredients[ingredient] + 1 });
						}
						else
						{
							likedIngredients.insert({ ingredient, 1 });
						}
					}
				}
				fin >> numberOfDislikes;
				for (int j = 0; j < numberOfDislikes; j++)
				{
					string ingredient;
					fin >> ingredient;
					if(isAlphaNumeric(ingredient))
					{
						if (Found(ingredient, dislikedIngredients))
						{
							dislikedIngredients.insert({ ingredient, dislikedIngredients[ingredient] + 1 });
						}
						else
						{
							dislikedIngredients.insert({ ingredient, 1 });
						}
					}
				}
			}
		}
	}
	fin.close();

	for (auto const& pair : likedIngredients)
	{
		string ingredient = pair.first;

		if (pair.second >= dislikedIngredients[ingredient])
		{
			finalToppings.push_back(ingredient);
		}
	}
	ofstream fout("Submission_E.out.txt");

	if (fout.fail())
	{
		cout << "ERROR! Could not create an output file found" << endl;
	}
	else
	{
		fout << finalToppings.size();

		for (int i = 0; i < finalToppings.size(); i++)
		{
			fout << " " << finalToppings[i] << " ";
		}
	}
	fout.close();

	system("pause");
	return 0;
}
