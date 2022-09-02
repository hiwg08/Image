#include <bits/stdc++.h>

using namespace std;

long long N, M;

long long Map[1001][1001]{ 0 }, DP[1001][1001][3]{ 0 };

bool Vis[1001][1001]{ 0 };

int dx[]{ 1, 0, 0 };
int dy[]{ 0, 1, -1 };

long long Solve(long long x, long long y, long long dir)
{
	if (x == N - 1 && y == M - 1)
		return Map[x][y];

	long long& ret = DP[x][y][dir];

	if (ret != -1)
		return ret;

	ret = INT_MIN;

	for (int k = 0; k < 3; k++)
	{
		long long nx = x + dx[k];
		long long ny = y + dy[k];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (Vis[nx][ny])
			continue;

		Vis[nx][ny] = true;
		ret = max(ret, Map[x][y] + Solve(nx, ny, k));
		Vis[nx][ny] = false;
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

	Vis[0][0] = true;

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0, 0) << '\n';
}