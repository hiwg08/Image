#include <bits/stdc++.h>

using namespace std;

int N, MIN, MAX, Map[51][51]{ 0 }, Result;

bool Vis[51][51]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool BFS(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x, y });
	Vis[x][y] = true;

	vector<pair<int, int>> Person_Move;

	while (!Q.empty())
	{
		pair<int, int> st1 = Q.front();
		Q.pop();
		Person_Move.push_back({ st1.first, st1.second });

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = st1.first + dx[dir];
			int ny = st1.second + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (Vis[nx][ny])
				continue;
			if (abs(Map[st1.first][st1.second] - Map[nx][ny]) < MIN || abs(Map[st1.first][st1.second] - Map[nx][ny]) > MAX)
				continue;

			Vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}
	if (Person_Move.size() == 1)
		return false;

	int Move_After = 0;

	for (int i = 0; i < Person_Move.size(); i++)
		Move_After += Map[Person_Move[i].first][Person_Move[i].second];

	for (int i = 0; i < Person_Move.size(); i++)
		Map[Person_Move[i].first][Person_Move[i].second] = Move_After / (int)Person_Move.size();

	return true;
}

int main()
{
	cin >> N >> MIN >> MAX;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> Map[i][j];
	}

	while (true)
	{
		memset(Vis, false, sizeof(Vis));
		bool CHK = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (!Vis[i][j] && BFS(i, j))
					CHK = true;
			}
		}
		if (!CHK)
			break;
		Result++;
	}

	cout << Result << '\n';
}