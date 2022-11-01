#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int T;

string A, B;

int Find_Sosu[10001]{ 0 };

map<int, bool> Vis;

void Eratos()
{
	int CHK = 2;

	while (CHK < 10000)
	{
		if (Find_Sosu[CHK] == -1)
		{
			CHK++;
			continue;
		}
		for (int i = CHK * 2; i < 10000; i += CHK)
			Find_Sosu[i] = -1;
		CHK++;
	}
}

int BFS(string A, string B)
{
	int CNT = 2;

	string temp = A;

	queue<pair<string, int>> Q;

	Q.push({ A, 0 });

	while (!Q.empty())
	{
		pair<string, int> st1 = Q.front();
		string st2 = st1.first;
		Q.pop();

		if (st1.first == B)
			return st1.second;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (i == 0 && j == 0)
					continue;
				if (j == (int)(st1.first[i] - '0'))
					continue;
				st2[i] = (char)(j + '0');
				if (Find_Sosu[stoi(st2)] == -1)
					continue;
				if (Vis[stoi(st2)])
					continue;
				Vis[stoi(st2)] = true;
				Q.push({ st2, st1.second + 1 });
			}
			st2 = st1.first;
		}
	}

	return -1;
}

int main()
{
	Eratos();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		Vis.clear();

		cin >> A >> B;

		int Ans = BFS(A, B);

		if (Ans == -1)
			cout << "Impossible" << '\n';
		else
			cout << Ans << '\n';
	}
}