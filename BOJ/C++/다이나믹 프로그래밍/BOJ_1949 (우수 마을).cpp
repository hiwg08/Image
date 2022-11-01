#include <bits/stdc++.h>
#define pii pair<int, int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[10001]{ 0 }, Vis_Chk[10001]{ 0 }, Root;

pii DP[10001];

bool Vis[10001]{ 0 };

vector<vector<int>> Tree;

pii solve(int Num)
{
	pii& ret = DP[Num];

	if (ret.first != 0 || ret.second != 0)
		return ret;

	Vis[Num] = true;

	ret.first = Arr[Num], ret.second = 0;

	for (int i = 0; i < Tree[Num].size(); i++)
	{
		if (!Vis[Tree[Num][i]])
		{
			pii Params = solve(Tree[Num][i]);
			ret.first += Params.second;
			ret.second += max(Params.first, Params.second);
		}
	}

	return ret;
}

// 꽤 어려웠던 트리 DP였다.... pair 형 DP 테이블 생각은 꽤 좋았는데, 다시 풀라고 하면 못 풀듯;;

int main()
{
	fastio;

	cin >> N;

	Tree.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N - 1; i++)
	{
		int a, b; cin >> a >> b;
		Tree[a].push_back(b);
		Tree[b].push_back(a);
		Vis_Chk[a]++; Vis_Chk[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (Vis_Chk[i] == 1)
		{
			Root = i;
			break;
		}
	}

	pii Ans = solve(Root);

	cout << max(Ans.first, Ans.second) << '\n';
}