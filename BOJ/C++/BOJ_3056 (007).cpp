#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[21][21]{ 0 };

double DP[1 << 21]{ 0 };

// 굳이 배열을 DP[N][1 << N]으로 설정할 필요가 없었던 문제. 어차피 순차적으로 돌기 때문에 비트의 개수만 새줘도 전혀 문제없기 때문.

void Input_Init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Arr[i][j];
	}

	for (int i = 0; i < (1 << 21); i++)
		DP[i] = -1;
}

double solve(int Bit)
{
	if (Bit == (1 << N) - 1)
		return 1.0;

	double& ret = DP[Bit];

	if (ret != (double)-1)
		return ret;

	for (int i = 0; i < N; i++)
	{
		if (!(Bit & (1 << i)))
			ret = max(ret, solve(Bit | (1 << i)) * ((double)(Arr[__builtin_popcount(Bit)][i]) / (double)100));
	}

	return ret;
}

int main()
{
	fastio;

	Input_Init();

	cout.precision(6);

	cout << fixed << solve(0) * (double)100 << '\n';
}