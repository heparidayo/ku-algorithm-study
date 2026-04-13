#include <iostream>
#include <queue>

using namespace std;

int map[101][101][101];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

int m, n, h;

struct Grid
{
	int z, y, x;
};

queue<Grid> q;

int solve()
{
	int x, y, z, nx, ny, nz;

	int loopTime = 0;
	while (!q.empty())
	{
		z = q.front().z;
		y = q.front().y;
		x = q.front().x;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			nz = z + dz[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h)
			{
				if (map[nz][ny][nx] == 0)
				{
					q.push({ nz, ny, nx });
					map[nz][ny][nx] = map[z][y][x] + 1;
					if (map[nz][ny][nx] > loopTime)
					{
						loopTime = map[nz][ny][nx];
					}
				}
			}
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[i][j][k] == 0)
				{
					return -1;
				}
			}
		}
	}
	if (loopTime == 0)
	{
		return 0;
	}
	else
	{
		return loopTime - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
				{
					q.push({ i, j, k });
				}
			}
		}
	}

	cout << solve();
}