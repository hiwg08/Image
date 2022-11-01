#include <bits/stdc++.h>
#define piiii pair<pair<int, int>, pair<int, int>>

using namespace std;

int N, Price_MIN = INT_MAX;

int mp, mf, ms, mv;

vector<piiii> V;
vector<int> Price, Params, Ans;

void solve(int Idx, int p, int f, int s, int v, int Money) // 2^15 (32768). 무난하게 시간 안에 들어옴
{
	if ((mp <= p && mf <= f && ms <= s && mv <= v) && Price_MIN > Money)
	{
		Price_MIN = Money;

		vector<int>().swap(Ans);
		Ans.clear();

		for (auto e : Params)
			Ans.push_back(e);
	}
	if (Idx >= N)
		return;

	Params.push_back(Idx + 1);
	solve(Idx + 1, p + V[Idx].first.first, f + V[Idx].first.second, s + V[Idx].second.first, v + V[Idx].second.second, Money + Price[Idx]);
	Params.pop_back();

	solve(Idx + 1, p, f, s, v, Money);
}

int main()
{
	cin >> N >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++)
	{
		int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
		V.push_back({ {a, b}, {c, d} });
		Price.push_back(e);
	}

	solve(0, 0, 0, 0, 0, 0);

	if ((int)Ans.size() == 0)
	{
		cout << -1 << '\n';
		exit(0);
	}

	cout << Price_MIN << '\n';

	for (auto e : Ans)
		cout << e << " ";
	cout << '\n';
}