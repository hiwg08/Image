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
	// 조합의 가짓수가 long long형 또한 넘길 수도 있다는 사실을 간과하고 있었다... K 또한 최대가 10억이었으므로, 간과할 만도 했다... 이 점 유의하자.
	// 다른 사람들과는 달리, 문자열 출력 시 재귀를 사용하여 문제를 해결해서 뿌듯 ㅎㅎ
}

void Solve(ll N, ll M, ll Idx)
{
	if (N == 0)
	{
		while (M--) cout << 'z';
		return;
	} // a가 없으면 남은 z만 출력하면 됨.
	if (M == 0)
	{
		while (N--) cout << 'a';
		return;
	} // 반대로, z가 없으면 남은 a만 출력하면 됨.
	 
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