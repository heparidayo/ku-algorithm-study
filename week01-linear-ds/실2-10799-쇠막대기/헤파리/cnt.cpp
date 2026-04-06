// 스택 안쓰는 풀이

#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    
    int cnt = 0;
    int ans = 0;
    
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(') cnt++; // 막대 + 1
        else 
        {
            cnt--;
            
            if (s[i - 1] == '(') ans += cnt; // 레이저
            else ans += 1; // 막대 -1
        }
    }
    
    cout << ans;  
}