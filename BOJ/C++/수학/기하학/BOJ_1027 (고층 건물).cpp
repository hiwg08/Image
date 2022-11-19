#include <bits/stdc++.h>
#define int long long

using namespace std;

int N, Arr[51]{ 0 }, Ans, a, b, MAX = INT_MIN;

// 직선의 기울기를 이용한 문제.
// N의 작은 범위를 활용하여 완전 탐색 적용 + 간단한 기하학 개념.

int32_t main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N; i++)
	{
		Ans = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			if (j == i - 1)
			{
				a = 1, b = Arr[j] - Arr[i];
				Ans++;
			}
			else
			{
				int c = i - j, d = Arr[j] - Arr[i];
				if (c * b < a * d)
				{
					a = c, b = d;
					Ans++;
				}
			}
		}
		for (int j = i + 1; j < N; j++)
		{
			if (j == i + 1)
			{
				a = 1, b = Arr[j] - Arr[i];
				Ans++;
			}
			else
			{
				int c = j - i, d = Arr[j] - Arr[i];
				if (c * b < a * d)
				{
					a = c, b = d;
					Ans++;
				}
			}
		}

		MAX = max(MAX, Ans);
	}

	cout << MAX << '\n';
}