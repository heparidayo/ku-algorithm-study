#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> dp)
{
    int n = dp.size();
    for (int i = 1; i < n; i++)
    {
        dp[i][0] += max({ dp[i - 1][1], dp[i - 1][2], dp[i - 1][3] });
        dp[i][1] += max({ dp[i - 1][0], dp[i - 1][2], dp[i - 1][3] });
        dp[i][2] += max({ dp[i - 1][1], dp[i - 1][0], dp[i - 1][3] });
        dp[i][3] += max({ dp[i - 1][1], dp[i - 1][2], dp[i - 1][0] });
    }
    
    n--;
    return max({ dp[n][0], dp[n][1], dp[n][2], dp[n][3] });
}