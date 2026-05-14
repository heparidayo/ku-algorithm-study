#include <iostream>
#include <vector>
using namespace std;

int maxValue[100001][4];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    maxValue[0][0] = land[0][0];
    maxValue[0][1] = land[0][1];
    maxValue[0][2] = land[0][2];
    maxValue[0][3] = land[0][3];

    for(int i = 1; i < land.size(); i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int max = 0;
            for(int k = 0; k < 4; k++)
            {
                if(j == k) continue;

                if(maxValue[i-1][k] > max) max = maxValue[i-1][k];
            }
            maxValue[i][j] = land[i][j] + max;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(answer > maxValue[land.size() - 1][i])
        {
            answer = maxValue[land.size() - 1][i]
        }
    }
    return answer;
}