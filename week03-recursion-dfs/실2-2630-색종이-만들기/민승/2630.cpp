#include <iostream>

using namespace std;

bool map[129][129];

int bluePaper = 0, whitePaper = 0;

bool isFilled(int r, int c, int size)
{
	bool firstColor = map[r][c];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[r+i][c+j] != firstColor)
			{
				return false;
			}
		}
	}
	return true;
}

void divide(int r, int c, int size)
{
	if (isFilled(r, c, size))
	{
		if (map[r][c] == 0)
		{
			whitePaper++;
		}
		else
		{
			bluePaper++;
		}
		return;
	}
	else
	{
		divide(r, c, size /2);
		divide(r + (size / 2), c, size / 2);
		divide(r, c + (size / 2), size / 2);
		divide(r + (size / 2) , c + (size / 2), size / 2);
	}
}

int main()
{
	int N; cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool inp; cin >> inp;
			map[i][j] = inp;
		}
	}

	divide(0, 0, N);

	cout << whitePaper << "\n" << bluePaper;

	return 0;
}