#include <string>
#include <vector>

using namespace std;

long long arr[2001] = { 0, 1, 2,};

long long dp(int n)
{
    if(n < 2) return arr[n];

    for(int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i-2] + arr[i-1]) % 1234567;
    }
    return arr[n];
}

long long solution(int n) {
    long long answer = 0;
    answer = dp(n);
    return answer;
}