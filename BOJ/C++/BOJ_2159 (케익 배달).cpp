#include <bits/stdc++.h>
#define ll long long
#define MAX 100000
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

ll N, S_X, S_Y, DP[100001][5]{ 0 };

vector<pair<ll, ll>> V;

ll dx[]{ 1, 0, -1, 0, 0 };
ll dy[]{ 0, 1, 0, -1, 0 };

ll Menhatan(ll a, ll b, ll c, ll d)
{
	return abs(a - b) + abs(c - d);
}

ll Solve(ll Idx, ll Dir, ll x, ll y)
{
	if (Idx >= N)
		return 0;

	ll& ret = DP[Idx][Dir];

	if (ret != -1)
		return ret;

	ret = LLONG_MAX;

	for (ll d = 0; d < 5; d++)
	{
		ll nx = V[Idx].first + dx[d];
		ll ny = V[Idx].second + dy[d];

		if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX)
			continue;
		ret = min(ret, Solve(Idx + 1, d, nx, ny) + Menhatan(x, nx, y, ny));
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N;

	cin >> S_X >> S_Y;

	for (ll i = 0; i < N; i++)
	{
		ll a, b; cin >> a >> b;
		V.push_back({ a, b });
	}

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0, S_X, S_Y) << '\n';
}