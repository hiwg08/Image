#include <bits/stdc++.h>

using namespace std;

int N, B[21][21]{ 0 }, MIN = INT_MAX;

vector<int> L, S;

void solve(int Idx)
{
	if (Idx > N)
	{
		int L_S = 0, R_S = 0;

		for (int i = 0; i < (int)L.size(); i++)
		{
			for (int j = i + 1; j < (int)L.size(); j++)
				L_S += (B[L[j]][L[i]] + B[L[i]][L[j]]);
		}

		for (int i = 0; i < (int)S.size(); i++)
		{
			for (int j = i + 1; j < (int)S.size(); j++)
				R_S += (B[S[j]][S[i]] + B[S[i]][S[j]]);
		}

		MIN = min(MIN, abs(L_S - R_S));

		return;
	}

	L.push_back(Idx);
	solve(Idx + 1);
	L.pop_back();

	if (Idx != 1)
	{
		S.push_back(Idx);
		solve(Idx + 1);
		S.pop_back();
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			cin >> B[i][j];
	}

	vector<int> L, S;

	solve(1);

	cout << MIN << '\n';
}