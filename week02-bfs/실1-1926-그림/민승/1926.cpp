#include <iostream>
#include <queue>

using namespace std;

int map[504][504];

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int maxSize = 0;
int drawCnt = 0;

void bfs(int n, int m)
{
	int r, c, nr, nc;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 1)
			{
				q.push({ i,j });
				map[i][j] = 0;
				int currentSize = 0;
				drawCnt++;
				while (!q.empty())
				{
					r = q.front().first;
					c = q.front().second;
					q.pop();
					currentSize++;
					for (int cnt = 0; cnt < 4; cnt++)
					{
						nr = r + dr[cnt];
						nc = c + dc[cnt];
						if (nr >= 0 && nr < n && nc >= 0 && nc < m)
						{
							if (map[nr][nc] == 1)
							{
								q.push({ nr, nc });
								map[nr][nc] = 0;
							}
						}
					}
				}
				if (maxSize < currentSize)
				{
					maxSize = currentSize;
				}
			}
		}
	}
	cout << drawCnt << "\n" << maxSize;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m; cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	bfs(n, m);

	return 0;
}