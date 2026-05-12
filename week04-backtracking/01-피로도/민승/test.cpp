#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 던전 갯수는 최대 8개니까 걍 전부 탐색하면 될 듯

bool visited[8] = { false, };
int maxCount = 0;

int dfs(int currentCount, int currentK, vector<vector<int>> dungeons)
{
    if (currentCount > maxCount) maxCount = currentCount;

    for (int i = 0; i < dungeons.size(); i++)
    {
        // 이미 방문한 던전이거나 최소 피로도가 현재 피로도 미만이라면 자르기
        if (currentK < dungeons[i][0] || visited[i]) continue;

        visited[i] = true;

        dfs(currentCount + 1, currentK - dungeons[i][1], dungeons);

        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(0, k, dungeons);
    return maxCount;
}

int main()
{
    cout << solution(80, { {80,20}, {50, 40}, {30,10} });
}