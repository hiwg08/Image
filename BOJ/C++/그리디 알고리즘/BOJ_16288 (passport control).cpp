#include <bits/stdc++.h>

using namespace std;

int N, K, Arr[101]{ 0 };

bool Vis[101]{ 0 };

// 가장 긴 증가하는 부분 수열(LIS)를 구하는 문제.
// 아이디어 싸움이다.
// 모든 경우의 수를 구하는 대신, 해당 예시가 되는가? 로 생각을 전환해야했던 문제.

int main()
{
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int Cnt = 0, Idx = 0;

	Vis[0] = true;

	while (true)
	{
		int Pre = Arr[Idx], temp_Idx = INT_MAX;

		for (int i = Idx + 1; i < N; i++)
		{
			if (Vis[i])
				continue;
			if (Pre > Arr[i])
				temp_Idx = min(temp_Idx, i);
			else
			{
				Pre = Arr[i];
				Vis[i] = true;
			}
		}

		Cnt++;
		if (temp_Idx == INT_MAX) break;
		Idx = temp_Idx;
	}

	Cnt <= K ? cout << "YES" << '\n' : cout << "NO" << '\n';
}