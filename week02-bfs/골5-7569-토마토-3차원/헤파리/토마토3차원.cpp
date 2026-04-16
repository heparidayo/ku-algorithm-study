#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int map[105][105][105];
int dx[6] = { 1, 0, 0, -1, 0, 0 };
int dy[6] = { 0, 1, 0, 0, -1, 0 };
int dz[6] = { 0, 0, 1, 0, 0, -1 };

int main()
{
    int n, m, h;
    cin >> m >> n >> h;
    
    // h n m
    queue<tuple<int, int, int>> q;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> map[k][i][j];
                if (map[k][i][j] == 1) q.push({ k, i, j });
            }
        }
    }
    
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            
            if (nx < 0 || ny < 0 || nz < 0) continue;
            if (nx >= h || ny >= n || nz >= m) continue;
            if (map[nx][ny][nz] != 0) continue;
            
            map[nx][ny][nz] = map[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push({ nx, ny, nz });
        }
    }
    
    int ans = 0;
    for (int k = 0; k < h; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[k][i][j] == 0)
                {
                    cout << -1;
                    return 0;
                }
                
                ans = max(ans, map[k][i][j]);
            }
        }
    } 
    
    cout << ans - 1;
    return 0;
}