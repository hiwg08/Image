\#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, X, Y, Idx, Parent[2001]{ 0 }, Level[2001]{ 0 };

bool Vis[2001]{ 0 };

string S;

stack<int> Q;

vector<vector<int>> Graphs;

vector<int> W, Ans;

int Find_LCA(int a, int b)
{
	if (Level[a] < Level[b])
		swap(a, b);

	while (Level[a] != Level[b])
		a = Parent[a];

	while (a != b)
	{
		a = Parent[a];
		b = Parent[b];
	}

	return a;
}

void DFS(int Idx, int Before, int L)
{
	Parent[Idx] = Before, Level[Idx] = L;

	Vis[Idx] = true;

	for (int i = 0; i < Graphs[Idx].size(); i++)
	{
		if (!Vis[Graphs[Idx][i]])
			DFS(Graphs[Idx][i], Idx, L + 1);
	}
}

int main()
{
	fastio;

	cin >> N >> S >> X >> Y;

	Graphs.resize(N + 1);

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '0')
		{
			Idx++;
			if (Q.size() >= 1)
			{
				Graphs[Q.top()].push_back(Idx);
				Graphs[Idx].push_back(Q.top());
			}
			Q.push(Idx);

			if (i == X - 1 || i == Y - 1)
				W.push_back(Q.top());
		}
		else
		{
			if (i == X - 1 || i == Y - 1)
				W.push_back(Q.top());
			Q.pop();
		}
	}

	DFS(1, 0, 1);

	int LCA = Find_LCA(W[0], W[1]);

	Idx = 0;

	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] == '0')
		{
			Q.push(++Idx);
			if (Q.top() == LCA)
				Ans.push_back(i + 1);
		}
		else
		{
			if (Q.top() == LCA)
				Ans.push_back(i + 1);
			Q.pop();
		}
	}

	cout << Ans[0] << " " << Ans[1] << '\n';
}