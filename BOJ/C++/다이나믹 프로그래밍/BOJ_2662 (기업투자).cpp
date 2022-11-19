#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, Base[301]{ 0 }, Arr[301][21]{ 0 }, DP[301][301]{ 0 }, Ans[21][301]{ 0 };

// Ans 배열의 의미 : 해당 위치(첫 번째 배열)에서 돈이 M만큼 남았을 때(두 번째 배열) 값어치가 최대가 될 수 있도록 투자할 수 있는 돈의 비용 (Ans의 값)
// 이렇게 하면 역추적이 가능하다.

int solve(int Money, int Idx)
{
	if (Idx == M)
		return 0;

	int& ret = DP[Money][Idx];

	if (ret != -1)
		return ret;

	ret = solve(Money, Idx + 1);

	for (int i = 0; i < N; i++)
	{
		if (Money - Base[i] >= 0)
		{
			int T1 = solve(Money - Base[i], Idx + 1) + Arr[i][Idx];
			if (ret < T1)
			{
				ret = T1;
				Ans[Idx][Money] = Base[i];
			}
		}
	}

	return ret;
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> Base[i];
		for (int j = 0; j < M; j++)
			cin >> Arr[i][j];
	}

	memset(DP, -1, sizeof(DP));

	int Price = solve(N, 0);

	cout << Price << '\n';

	int total = N;

	for (int i = 0; i < M; i++)
	{
		cout << Ans[i][total] << " ";
		total -= Ans[i][total];
	}
}