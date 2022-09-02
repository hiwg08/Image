#include <bits/stdc++.h>

using namespace std;

int N, K, Arr[101][2]{ 0 }, DP[101][100001]{ 0 };

int Solve(int Idx, int Money)
{
	if (Idx == N)
		return 0;

	int& ret = DP[Idx][Money];

	if (ret != -1)
		return ret;

	ret = 0;

	if (Money - Arr[Idx][0] >= 0)
		ret = max(ret, Solve(Idx + 1, Money - Arr[Idx][0]) + Arr[Idx][1]);
	ret = max(ret, Solve(Idx + 1, Money));

	return ret;
}

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Arr[i][0] >> Arr[i][1];

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, K) << '\n';
}