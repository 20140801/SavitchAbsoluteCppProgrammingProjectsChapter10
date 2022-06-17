#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
	vector <int> grade;
	int score;
	int max = -77;
	cout << "Enter Score. If you enter -1 then inputing stops.\n";
	while (1)
	{
		cin >> score;
		if (score == -1)
		{
			break;
		}
		if (score >= 0) 
		{
			grade.push_back(score);
			if (score > max)
			{
				max = score;
			}
		}
	}
	
	if (max >= 0) 
	{
		int* histo;
		histo = new int[max + 1];
		for (int i = 0; i <= max; i++)
		{
			histo[i] = 0;
		}
		for (int i = 0; i < grade.size(); i++)
		{
			histo[grade[i]]++;
		}
		for (int i = 0; i <= max; i++)
		{
			cout << histo[i] << " grade(s) of " << i << endl;
		}
		for (int i = 0; i <= max; i++)
		{
			cout << " grade(s) "; 
			cout << right << setw(4) << i;
			cout<< " histogram ";
			for (int j = 0; j < histo[i]; j++)
			{
				cout << "#";
			}
			cout << '\n';
		}
		delete[] histo;
	}
	return 0;
}