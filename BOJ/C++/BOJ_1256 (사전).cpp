#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000000

using namespace std;

ll N, M, K, DP[101][101]{ 0 };

void Init()
{
	for (ll j = 1; j <= 100; j++)
	{
		DP[0][j] = 1;
		DP[j][0] = 1;
	}

	for (ll i = 1; i <= 100; i++)
	{
		for (ll j = 1; j <= 100; j++)
		{
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
			if (DP[i][j] > MAX)
				DP[i][j] = MAX;
		}
	}
	// ****************************
	// ������ �������� long long�� ���� �ѱ� ���� �ִٴ� ����� �����ϰ� �־���... K ���� �ִ밡 10���̾����Ƿ�, ������ ���� �ߴ�... �� �� ��������.
	// �ٸ� �������� �޸�, ���ڿ� ��� �� ��͸� ����Ͽ� ������ �ذ��ؼ� �ѵ� ����
}

void Solve(ll N, ll M, ll Idx)
{
	if (N == 0)
	{
		while (M--) cout << 'z';
		return;
	} // a�� ������ ���� z�� ����ϸ� ��.
	if (M == 0)
	{
		while (N--) cout << 'a';
		return;
	} // �ݴ��, z�� ������ ���� a�� ����ϸ� ��.
	 
	ll a_first = DP[N - 1][M];

	if (Idx <= a_first)
	{
		cout << 'a';
		Solve(N - 1, M, Idx);
	}
	else
	{
		cout << 'z';
		Solve(N, M - 1, Idx - a_first);
	}
}

int main()
{
	cin >> N >> M >> K;

	Init();

	if (K > DP[N][M])
	{
		cout << -1 << '\n';
		exit(0);
	}

	Solve(N, M, K);

	cout << '\n';
}