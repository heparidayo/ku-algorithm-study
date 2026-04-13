#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int bfsMaze(vector<vector<int>>& maze, int N, int M)
{
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	queue<pair<int, int>> q;
	vector<vector<int>> dis(N, vector<int>(M, 0));

	// 큐에 시작 위치인 1,1 (0,0) 입력하고 해당 위치는 첫번째 시도이니 1로 설정함
	q.push({ 0,0 });
	dis[0][0] = 1;

	while (!q.empty())
	{
		int cnt = dis[q.front().first][q.front().second];
		for (int i = 0; i < 4; i++)
		{
			int x = q.front().first + dr[i];
			int y = q.front().second + dc[i];
			q.pop();
			if (x > -1 && x < N && y > -1 && y < M)
			{
				if (maze[x][y] != 0 && dis[x][y] == 0)
				{
					q.push({x,y});
					dis[x][y] = cnt + 1;
					if (x == N - 1 && y == M - 1)
					{
						return dis[x][y];
					}
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M; cin >> N; cin >> M;

	vector<vector<int>> maze(N, vector<int>(M));

	for (int i = 0; i < N; i++)
	{
		string inp;
		cin >> inp;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = inp[j] - '0';
		}
	}

	cout << bfsMaze(maze, N, M);
	
	return 0;
}
