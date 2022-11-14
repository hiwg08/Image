#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N;

vector<int> V;

int solve()
{
	for (int i = N - 1; i >= 2; i--)
	{
		if (V[i - 2] + V[i - 1] > V[i])
			return V[i - 2] + V[i - 1] + V[i];
	}
	return -1;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0, a; i < N; i++)
	{
		cin >> a; V.push_back(a);
	}

	sort(V.begin(), V.end());

	cout << solve() << '\n';
}