#include <bits/stdc++.h>

using namespace std;

long long N, M, MAX = -2000000001;

long long Tree_Sum(const vector<long long>& Arr, long long x)
{
	long long SUM = 0;
	for (auto e : Arr)
	{
		if (e - x > 0)
			SUM += (e - x);
	}
	return SUM;
}

long long Binary_Search(const vector<long long>& Arr)
{
	long long lo = -1, hi = MAX + 1;
	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		if (Tree_Sum(Arr, mid) >= M)
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main()
{
	cin >> N >> M;

	vector<long long> Arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		MAX = max(MAX, Arr[i]);
	}

	cout << Binary_Search(Arr) << '\n';
}