#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 4000000

using namespace std;

ll N, K, DP[4000001]{ 0 };

void fact()
{
	DP[0] = 1;

	for (ll Idx = 1; Idx <= MAX; Idx++)
		DP[Idx] = ((Idx % MOD) * (DP[Idx - 1] % MOD)) % MOD;
}

ll solve(ll param, ll power)
{
	if (power == 0) return 1;

	if (power % 2 != 0)
		return ((param % MOD) * (solve(param, power - 1) % MOD)) % MOD;

	ll ret = solve(param, power / 2) % MOD;

	return (ret * ret) % MOD;
}

int main()
{
	cin >> N >> K;

	fact();

	ll Parent = DP[N] % MOD, Child = solve(((DP[K] % MOD) * (DP[N - K] % MOD)) % MOD, MOD - 2);

	cout << (Parent * Child) % MOD << '\n';
}