#include <bits/stdc++.h>

using namespace std;

int N, M;

int Map[501][501]{ 0 };

int DP[501][501]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int Solve(int x, int y)
{
	if (x == N - 1 && y == M - 1)
		return 1;

	int& ret = DP[x][y];

	if (ret != -1)
		return ret;

	ret = 0;

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (Map[x][y] <= Map[nx][ny])
			continue;
		ret += Solve(nx, ny);
	}
	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
	}

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0) << '\n';
}