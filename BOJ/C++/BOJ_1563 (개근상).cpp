#include <bits/stdc++.h>
#define MOD 1000000

using namespace std;

int N, DP[1001][3][3]{ 0 };

int Solve(int Idx, int Late, int Absent)
{
	if (Late >= 2 || Absent >= 3)
		return 0;
	if (Idx == N)
		return 1;

	int& ret = DP[Idx][Late][Absent];

	if (ret != -1)
		return ret;

	return ret = (Solve(Idx + 1, Late + 1, 0) + Solve(Idx + 1, Late, Absent + 1) + Solve(Idx + 1, Late, 0)) % MOD;
}

int main()
{
	cin >> N;

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0, 0) << '\n';
}