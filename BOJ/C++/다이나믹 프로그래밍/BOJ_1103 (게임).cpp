#include <bits/stdc++.h>

using namespace std;

int N, M;

int Map[51][51]{ 0 }, DP[51][51]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool Vis[51][51]{ 0 };

int DFS(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
		return 0;

	if (Map[x][y] == -1)
		return 0;

	int& ret = DP[x][y];

	if (ret != -1)
		return ret;

	Vis[x][y] = true;

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + (dx[dir] * Map[x][y]);
		int ny = y + (dy[dir] * Map[x][y]);

		if ((nx >= 0 && ny >= 0 && nx < N && ny < M) && Vis[nx][ny])
		{
			cout << -1 << '\n';
			exit(0);
		}

		ret = max(ret, DFS(nx, ny) + 1);
	}

	Vis[x][y] = false;

	return ret;
}

void Input()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; j++)
		{
			if (s[j] == 'H')
				Map[i][j] = -1;
			else
				Map[i][j] = (int)(s[j] - '0');
		}
	}
}

int main()
{
	Input();

	memset(DP, -1, sizeof(DP));

	cout << DFS(0, 0) << '\n';
}