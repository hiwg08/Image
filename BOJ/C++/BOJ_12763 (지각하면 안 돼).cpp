#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long N, T, M, L;

bool Vis[101]{ 0 };

class DFS_Info
{
public:
	long long Des, Tim, Pri;
	DFS_Info(long long _Des, long long _Tim, long long _Pri)
		:Des(_Des), Tim(_Tim), Pri(_Pri)
	{}
};

vector<vector<DFS_Info>> Graphs;

long long DFS(long long Idx, long long K, long long U)
{
	if (K > T)
		return INT_MAX;
	if (U > M)
		return INT_MAX;
	if (Idx == N)
		return 0;

	Vis[Idx] = true;

	long long Ans = INT_MAX;

	for (int i = 0; i < Graphs[Idx].size(); i++)
	{
		if (!Vis[Graphs[Idx][i].Des])
			Ans = min(Ans, DFS(Graphs[Idx][i].Des, K + Graphs[Idx][i].Tim, U + Graphs[Idx][i].Pri) + Graphs[Idx][i].Pri);
	}

	Vis[Idx] = false;

	return Ans;
}

int main()
{
	fastio;

	cin >> N >> T >> M >> L;

	Graphs.resize(N + 1);

	for (long long i = 0; i < L; i++)
	{
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		Graphs[a].push_back(DFS_Info(b, c, d));
		Graphs[b].push_back(DFS_Info(a, c, d));
	}

	long long Result = DFS(1, 0, 0);

	if (Result >= INT_MAX)
		cout << -1 << '\n';
	else
		cout << Result << '\n';
}