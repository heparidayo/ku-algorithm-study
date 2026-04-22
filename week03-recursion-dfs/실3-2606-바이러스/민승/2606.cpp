#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[101];

bool isVirus[101] = { false, };

int n_virus;

void dfs(int n)
{
	isVirus[n] = true;
	for (int i : vec[n])
	{
		if (!isVirus[i])
		{
			// 첫번째 컴퓨터에 의해 바이러스에 걸리는 pc 수니까 여기서 더함
			n_virus++;
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e; cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int ln, rn; cin >> ln >> rn;
		vec[ln].push_back(rn);
		vec[rn].push_back(ln);
	}
	dfs(1);
	cout << n_virus;
	return 0;
}