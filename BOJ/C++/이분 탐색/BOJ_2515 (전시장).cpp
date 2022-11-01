#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

using PP = pair<long long, long long>;

long long N, S, DP[300001]{ 0 };

vector<PP> Draw;

long long Solve(long long Idx)
{
	if (Idx >= N)
		return 0;

	long long& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = Solve(Idx + 1);

	ret = max(ret, Solve((long long)(lower_bound(Draw.begin(), Draw.end(), PP(Draw[Idx].first + S, 0)) - Draw.begin())) + Draw[Idx].second);

	return ret;
}

int main()
{
	fastio;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
	{
		long long a, b; cin >> a >> b;
		Draw.push_back({ a, b });
	}

	sort(Draw.begin(), Draw.end());

	memset(DP, -1, sizeof(DP));

	cout << Solve(0) << '\n';
}