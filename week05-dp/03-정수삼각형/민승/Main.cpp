#include <string>
#include <vector>

using namespace std;

int maxValue[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    maxValue[0][0] = triangle[0][0];

    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int max = 0;
            if(j == 0)
            {
                maxValue[i][j] = triangle[i][j] + maxValue[i-1][j];
                continue;
            } else if(j == i)
            {
                maxValue[i][j] = triangle[i][j] + maxValue[i-1][j-1];
                continue;
            }

            max = (maxValue[i-1][j] > maxValue[i-1][j-1]) ? maxValue[i-1][j] : maxValue[i-1][j-1];
            maxValue[i][j] = triangle[i][j] + max;
        }
    }

    for(int i = 0; i < triangle.size(); i++)
    {
        if(answer < maxValue[triangle.size()-1][i])
        {
            answer = maxValue[triangle.size()-1][i];
        }
    }

    return answer;
}