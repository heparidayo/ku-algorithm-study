#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int map[505][505];
int ans, cnt;
int n, m;

// x,y 확산
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    map[x][y] = 0;
    
    int area = 1;
    
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (map[nx][ny] == 0) continue;
            
            q.push({ nx, ny });
            map[nx][ny] = 0;
            
            area += 1;
        }
    }
    
    ans = max(ans, area);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
            
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 1) 
            {
                bfs(i, j);
                cnt += 1;
            }
        }
    }
    
    cout << cnt << '\n' << ans;
}
