#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[21][21]{ 0 };

double DP[1 << 21]{ 0 };

// ���� �迭�� DP[N][1 << N]���� ������ �ʿ䰡 ������ ����. ������ ���������� ���� ������ ��Ʈ�� ������ ���൵ ���� �������� ����.

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