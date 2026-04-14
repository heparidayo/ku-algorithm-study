#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int map[105][105];

// 1,1 -> n,m
int bfs(int n, int m)
{
    queue<pair<int, int>> q;
    q.push({ 1, 1 });
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (map[nx][ny] > 1 || map[nx][ny] == 0) continue;
            
            map[nx][ny] = map[cur.first][cur.second] + 1;
            if (nx == n && ny == m) return map[nx][ny];
            
            q.push({ nx, ny });
        }
    }
    
    return -1;
}

int main()
{
    int n, m; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &map[i][j]);
    
    cout << bfs(n, m);
}
