#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1000000000

using namespace std;

int N, M, Start, End;

bool Vis[100001]{ 0 };

vector<vector<pair<int, int>>> Graphs;

void DFS(int Idx, int Weight_Limit)
{
	Vis[Idx] = true;

	for (int i = 0; i < Graphs[Idx].size(); i++)
	{
		if (!Vis[Graphs[Idx][i].first] && Graphs[Idx][i].second >= Weight_Limit)
			DFS(Graphs[Idx][i].first, Weight_Limit);
	}
}

int Binary_Search()
{
	int lo = 0, hi = MAX + 1;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;

		memset(Vis, false, sizeof(Vis));

		DFS(Start, mid);

		if (!Vis[End])
			hi = mid;
		else
			lo = mid;
	}

	return lo;
}

int main()
{
	fastio;

	cin >> N >> M;

	Graphs.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		Graphs[a].push_back({ b, c });
		Graphs[b].push_back({ a, c });
	}

	cin >> Start >> End;

	cout << Binary_Search() << '\n';
}