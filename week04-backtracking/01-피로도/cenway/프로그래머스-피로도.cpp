#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
int ans;

void func(int stamina, int visit, int cnt)
{
    if(ans < cnt) ans = cnt;
    
    for(int i = 0; i < v.size(); i++)
    {
        if(visit & (1 << i)) continue;
        
        int nstamina = stamina;
        int ncnt = cnt;
        if(stamina >= v[i][0]) 
        {
            nstamina -= v[i][1];
            ncnt += 1;
        }
        int nvisit = visit | (1 << i);
        
        func(nstamina, nvisit, ncnt);
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    v = dungeons;
    func(k, 0, 0);
    
    return ans;
}