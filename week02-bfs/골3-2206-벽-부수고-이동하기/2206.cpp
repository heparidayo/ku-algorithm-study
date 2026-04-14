#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Wall
{
	int r, c, dist;
	bool isBroke;
};

int map[1001][1001];

// 벽을 부스고 이동하는 걸 감지하는 2차원 배열이랑 
// 안부수고 이동하는 걸 감지하는 배열 2개를 사용해서 해결함
bool visited[2][1001][1001] = { false, };

queue<Wall> q;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int n, m;

int solve()
{
	int r, c, nr, nc, dist;
	bool isBroke;
	while (!q.empty())
	{
		r = q.front().r;
		c = q.front().c;
		dist = q.front().dist;
		isBroke = q.front().isBroke;
		q.pop();
		
		if (r == n - 1 && c == m - 1)
		{
			return dist;
		}

		for (int i = 0; i < 4; i++)
		{
			nr = r + dr[i];
			nc = c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < n && nc < m)
			{
				if (map[nr][nc] == 0 && !visited[isBroke][nr][nc])
				{
					visited[isBroke][nr][nc] = true;
					q.push({ nr,nc,dist + 1, isBroke });
				}
				else if (map[nr][nc] == 1 && !isBroke && !visited[1][nr][nc])
				{
					visited[1][nr][nc] = true;
					q.push({ nr,nc,dist + 1, true });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string inp; cin >> inp;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = inp[j] - '0';
		}
	}

	q.push({ 0,0,1,false });

	cout << solve() << "\n";
}