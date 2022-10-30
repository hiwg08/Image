#include <bits/stdc++.h>

using namespace std;

int N, Arr[11]{ 0 };

bool Vis_Comb[11]{ 0 }, Vis_Graph[11]{ 0 };

vector<vector<int>> Graphs;

vector<int> Q, W;

int Left, Q_Person, W_Person, MIN = INT_MAX;

void DFS(vector<int> params, int Idx, bool flag)
{
	Vis_Graph[Idx] = true;

	flag == false ? Q_Person += Arr[Idx] : W_Person += Arr[Idx];

	for (int i = 0; i < Graphs[Idx].size(); i++)
	{
		for (auto e : params)
		{
			if (!Vis_Graph[Graphs[Idx][i]] && Graphs[Idx][i] == e)
				DFS(params, Graphs[Idx][i], flag);
		}
	}
}

void solve(int A, int U)
{
	if (A == Left)
	{
		vector<int>().swap(Q);
		Q.clear();

		vector<int>().swap(W);
		W.clear();

		for (int i = 1; i <= N; i++)
			Vis_Comb[i] ? Q.push_back(i) : W.push_back(i);

		Q_Person = 0, W_Person = 0;
		memset(Vis_Graph, false, sizeof(Vis_Graph));
		DFS(Q, Q[0], false);
		DFS(W, W[0], true);

		for (auto e : Q)
		{
			if (!Vis_Graph[e])
				return;
		}
		for (auto e : W)
		{
			if (!Vis_Graph[e])
				return;
		}

		MIN = min(MIN, abs(Q_Person - W_Person));

		return;
	}

	for (int i = U; i <= N; i++)
	{
		if (Vis_Comb[i])
			continue;
		Vis_Comb[i] = true;
		solve(A + 1, U + 1);
		Vis_Comb[i] = false;
	}
}

int main()
{
	cin >> N;

	Graphs.resize(N + 1);

	for (int i = 1; i <= N; i++)
		cin >> Arr[i];

	for (int i = 1; i <= N; i++)
	{
		int a; cin >> a;
		for (int j = 0; j < a; j++)
		{
			int b; cin >> b;
			Graphs[i].push_back(b);
			Graphs[b].push_back(i);
		}
	}

	for (int i = 1; i <= N / 2; i++)
	{
		Left = i;
		solve(0, 1);
	}

	MIN == INT_MAX ? cout << -1 << '\n' : cout << MIN << '\n';
}