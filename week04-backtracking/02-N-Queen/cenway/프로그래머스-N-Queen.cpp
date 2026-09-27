#include <string>
#include <vector>
#include <cstring>

using namespace std;

//12개이니 depth는 12가 최대. 그니까 그냥 다 해봐

//왼쪽 아래 대각선은 y-x(같은 y절편인지)가 같은지
//오른 아래 대각은 y+x(같은 y절편인지)가 같은지

int cnt;
int board[2][12];

//[1]어떤 x(index)에 y가 들어있는지
//[0]어떤 y(index)에 x가 들어있는지

void func(int n, int k)
{
    if(k == n) 
    {
        cnt++;
        return;
    }
    
    for(int i  = 0; i < n; i++)
    {
        if(board[1][i] != -1) continue;
        
        bool ldiag = false;
        for(int j = 0; j < k; j++)
        {
            if(j - board[0][j] == k - i)
            {
                ldiag = true;
                break;
            }
        }
        if(ldiag) continue;
        
        bool rdiag = false;
        for(int j = 0; j < k; j++)
        {
            if(j + board[0][j] == k + i)
            {
                rdiag = true;
                break;
            }
        }
        if(rdiag) continue;
        board[1][i] = k;
        board[0][k] = i;
        func(n, k+1);
        board[1][i] = -1;
        board[0][k] = -1;
    }
    
    
}


int solution(int n) {
    int answer = 0;

    memset(board, -1, sizeof(board));
    func(n, 0);
    
    answer = cnt;
    return answer;
}