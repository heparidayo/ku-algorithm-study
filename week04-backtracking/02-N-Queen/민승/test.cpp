#include <string>
#include <iostream>
#include <vector>

using namespace std;

int nqueenCount = 0;
bool canQueenCol[12];
bool canQueenAddDig[24];
bool canQueenSuvDig[24];

void dfs(int row, int n)
{
    if (row == n)
    {
        nqueenCount++;
        return;
    }

    // n*n 크기에 n 개의 퀸이 들어가야 하는데 퀸은 같은 줄엔 못 놓으니까 각 줄마다 퀸이 존재
    for (int i = 0; i < n; i++)
    {
        // 해당 열에 퀸 배치가 가능하고 대각선에 퀸이 있는지도 체크하기
        if (!canQueenCol[i] && !canQueenAddDig[row + i] && !canQueenSuvDig[row - i + 12])
        {
            canQueenCol[i] = true;
            canQueenAddDig[row + i] = true;
            canQueenSuvDig[row - i + 12] = true;

            dfs(row + 1, n);

            canQueenCol[i] = false;
            canQueenAddDig[row + i] = false;
            canQueenSuvDig[row - i + 12] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    dfs(0, n);
    answer = nqueenCount;
    return answer;
}

int main()
{
    cout << solution(4);
}