#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int T, K, DP[101][10001]{ 0 };

vector<pair<int, int>> V;

int Solve(int Idx, int Cost)
{
	if (Cost == 0)
		return 1;

	if (Idx >= K)
		return 0;

	int& ret = DP[Idx][Cost];

	if (ret != -1)
		return ret;

	ret = 0;

	ret += Solve(Idx + 1, Cost);

	for (int i = 1; i <= V[Idx].second; i++)
	{
		if (Cost - (V[Idx].first * i) >= 0)
			ret += Solve(Idx + 1, Cost - (V[Idx].first * i));
	}

	return ret;
}

int main()
{
	fastio;

	cin >> T >> K;

	for (int i = 0; i < K; i++)
	{
		int a, b; cin >> a >> b;
		V.push_back({ a, b });
	}

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, T) << '\n';
}s