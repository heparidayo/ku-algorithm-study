#include <string>
#include <vector>

using namespace std;

long long arr[2001];

//k 번째는 k-1에서 1칸 점프, k-2에서 두 칸 점프


long long solution(int n) {
    long long answer = 0;
    
    arr[0] = (long long)0;
    arr[1] = (long long)1;
    arr[2] = (long long)2;
    
    for(int i = 3; i <= n; i++)
    {
        arr[i] = (arr[i-1] + arr[i-2])%(long long)1234567;
    }
    answer = arr[n];
    return answer;
}