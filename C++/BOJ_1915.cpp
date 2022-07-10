#include <bits/stdc++.h>

using namespace std;

int N, M;

int Map[1001][1001]{ 0 };

int DP[1001][1001]{ 0 };

string s;

int Ans = -9999999;

void Solve() // 반복문을 사용한 DP. 직사각형 배열(n * m)을 거꾸로 탐색해서 정사각형의 최대 넓이를 구한다.
			 // 문제에서 요구하는건 넓이의 최댓값이지만 가로, 세로, 사선 방향에 위치한 1의 개수에 따라 정사각형을 만들 수 있는 제약이 있기 때문에 max가 아님에 유의해야한다. 
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			if (Map[i][j] != 1)
				continue;

			if (i == N - 1)
				DP[i][j] = 1;
			else
				DP[i][j] = min(DP[i + 1][j + 1], min(DP[i + 1][j], DP[i][j + 1])) + 1; // 넓이를 구하는 점화식

			Ans = max(Ans, DP[i][j]); // 넓이 자체는 최댓값이므로 모든 배열에서 최댓값 선택
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
			Map[i][j] = static_cast<int>(s[j] - 48);
	}

	Solve();
	if (Ans == -9999999)
		cout << 0 << '\n';
	else
		cout << Ans * Ans << '\n';
}