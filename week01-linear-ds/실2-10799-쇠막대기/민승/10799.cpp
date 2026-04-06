#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	int currentPipe = 0, totalPipe = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '(')
		{
			if (input[i + 1] == ')')
			{
				totalPipe += currentPipe;
			}
			else
			{
				currentPipe++;
			}
		}
		else
		{
			if (input[i - 1] != '(')
			{
				currentPipe--;
				totalPipe++;
			}
		}
	}
	cout << totalPipe;
}