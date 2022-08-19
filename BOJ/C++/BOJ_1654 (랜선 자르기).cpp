#include <bits/stdc++.h>

using namespace std;

int K, N;

long long I1;

vector<long long> LAN;

long long Solve()
{
	long long lo = 0, hi = LAN[LAN.size() - 1] + 1;

	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2, CNT = 0;

		for (int i = 0; i < LAN.size(); i++)
			CNT += (LAN[i] / mid);

		if (CNT >= N)
			lo = mid;
		else
			hi = mid;
	}

	return lo;
}

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> I1;
		LAN.push_back(I1);
	}

	sort(LAN.begin(), LAN.end());

	cout << Solve() << '\n';
}