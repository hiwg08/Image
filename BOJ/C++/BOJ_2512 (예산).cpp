#include <bits/stdc++.h>

using namespace std;

long long N, I1, C;

vector<long long> Yesan;

// 110 120 140 150

// 485는 고정

// 상한선을 높일 수록 가격을 더 많이 책정하게 된다.

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> I1;
		Yesan.push_back(I1);
	}

	cin >> C;

	sort(Yesan.begin(), Yesan.end());

	long long lo = 0, hi = Yesan[Yesan.size() - 1] + 1;

	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2, CNT = 0;

		for (auto i = 0; i < Yesan.size(); i++)
		{
			if (mid >= Yesan[i])
				CNT += Yesan[i];
			else
				CNT += mid;
		}

		if (CNT <= C)
			lo = mid;
		else
			hi = mid;
	}

	cout << lo << '\n';
}