#include <bits/stdc++.h>

using namespace std;

int DP[2][101][21]{ 0 };

string T, S[2];

int Solve(bool a, int b, int c)
{
	if (c == T.size())
		return 1;

	int& ret = DP[a][b][c];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int i = b; i < S[a].size(); i++)
	{
		if (S[a][i] == T[c])
			ret += Solve(!a, i + 1, c + 1);
	}
	return ret;
}

int main()
{
	cin >> T >> S[0] >> S[1];

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0, 0) + Solve(1, 0, 0) << '\n';
}