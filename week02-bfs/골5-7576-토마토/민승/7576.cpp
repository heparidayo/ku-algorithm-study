#include <iostream>
#include <queue>

// 일단 익은 토마토의 위치를 전부 큐에 담고 bfs 를 돌려야겠다.
// 익은 토마토는 어차피 안찾을거니까 map 에서 바로 반복 횟수로 바꿔버리는걸로

using namespace std;

int map[1001][1001];

queue<pair<int, int>> q;

int n, m;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int result = 0;

int bfs()
{
	int r, c, nr, nc;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr >= 0 && nr < n && nc >= 0 && nc < m)
			{
				if (map[nr][nc] == 0)
				{
					q.push({ nr, nc });
					map[nr][nc] = map[r][c] + 1;
					if (map[nr][nc] > result)
					{
						result = map[nr][nc];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				return -1;
			}
		}
	}
	if (result == 0)
	{
		return 0;
	}
	else 
	{
		// 1부터 시작했으므로 -1 해주기
		return result - 1;
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1) 
			{
				q.push({ i, j });
			}
		}
	}

	cout << bfs();

	return 0;
}