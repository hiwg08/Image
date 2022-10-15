#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll K, N, Arr[10001]{ 0 };

bool CHK(ll mid)
{
	ll SUM = 0;

	for (int i = 0; i < K; i++)
		SUM += Arr[i] / mid;

	return SUM >= N; // 부등호를 붙여야 최댓값을 구할 수 있기 때문에...
}

ll Binary_Search()
{
	ll lo = 1, hi = (ll)((ll)1 << 31); // lo를 출력하는 과정이기 때문에 hi의 값을 애당초 값이 될 수 없는 (ll)((ll)1 << 31)을 써준 거다.
									   // WHY? 그래야 lo와 hi의 간격이 정확하게 1 만큼 차이가 나니까....
									   // lo는 1이 될 수도 있기 때문에 1을 선언해준 것
									   // 만약에 hi를 출력하는 거였으면 lo = 0, hi = (ll)(1 << 31) - 1이 됐겠지.

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) / 2; // 이 과정에서 오버플로우가 일어나기 때문에 반드시 long long 형으로 선언.

		if (CHK(mid))
			lo = mid;
		else
			hi = mid;
	}

	return lo; // 구간의 범위가 T T T T..... F F F F 이기 때문에 lo를 출력하는 거다. 
}

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
		cin >> Arr[i];

	cout << Binary_Search() << '\n';
}