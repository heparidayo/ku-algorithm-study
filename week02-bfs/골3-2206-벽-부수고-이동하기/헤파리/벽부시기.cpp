#include <iostream>
#include <queue> 
#include <tuple> 
using namespace std;

int map[1002][1002];
int dist[1005][1005][2];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
 
int main() 
{ 
    int n, m;
    cin >> n >> m; 
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < m; j++)
            map[i][j] = s[j] - '0';
    }

    queue<tuple<int, int, int>> q;
    q.push({ 0, 0, 0 });
    dist[0][0][0] = 1; 
    
    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        int cx = get<0>(cur);
        int cy = get<1>(cur);
        int cz = get<2>(cur);

        // 도착
        if (cx == n - 1 && cy == m - 1)
        {
            cout << dist[cx][cy][cz] << '\n';
            return 0;
        }
        
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            
            // 벽 X, 첫방문
            if (map[nx][ny] == 0 && dist[nx][ny][cz] == 0)
            {
                dist[nx][ny][cz] = dist[cx][cy][cz] + 1;
                q.push({ nx, ny, cz });
            }
            // 벽 O, 벽부시기 가능, 첫 방문
            else if (map[nx][ny] == 1 && cz == 0 && dist[nx][ny][1] == 0)
            {
                dist[nx][ny][1] = dist[cx][cy][0] + 1;
                q.push({ nx, ny, 1 });
            }
        }
    }
    
    cout << -1 << '\n';
    return 0;
}
