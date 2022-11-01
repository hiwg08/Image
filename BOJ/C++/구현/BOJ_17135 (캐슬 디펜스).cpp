#include <bits/stdc++.h>

using namespace std;

int N, M, D, Board[16][16]{ 0 }, Board_Copy[16][16]{ 0 }, Arr[16]{ 0 }, Ans = INT_MIN;

bool Vis[16]{ 0 }, Board_Vis[16][16]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

void Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			Board_Copy[i][j] = Board[i][j];
	}
}

void Enemy_Conquer(int Standard)
{
	for (int j = 0; j < M; j++)
	{
		for (int i = N - 1; i >= Standard + 1; i--)
			Board_Copy[i][j] = Board_Copy[i - 1][j];
	}

	for (int j = 0; j < M; j++)
		Board_Copy[Standard][j] = 0;
}

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.second == b.second)
		return a.first.second < b.first.second; // 거리가 같으면 가장 왼쪽(y -> 0에 가까운)에 있는 적 타겟팅
	return a.second < b.second; // 맨해탄 거리 순으로 내림차순 정렬
}

int BFS(vector<pair<int, int>>& V)
{
	Init();

	int Cnt = 0;

	for (int j = 0; j < N; j++)
	{
		vector<pair<pair<int, int>, int>> Enemy[3];

		for (int i = 0; i < V.size(); i++)
		{
			memset(Board_Vis, false, sizeof(Board_Vis));

			queue<pair<pair<int, int>, int>> Q;

			Q.push({ {V[i].first, V[i].second}, 0 });

			while (!Q.empty())
			{
				pair<pair<int, int>, int> st1 = Q.front();
				Q.pop();

				if (st1.first.first >= 0 && st1.first.second >= 0 && st1.first.first < N && st1.first.second < M)
				{
					if (Board_Copy[st1.first.first][st1.first.second] == 1)
					{
						Enemy[i].push_back({ {st1.first.first, st1.first.second}, st1.second });
						continue;
					}
				}

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = st1.first.first + dx[dir];
					int ny = st1.first.second + dy[dir];

					if (nx < 0 || ny < 0 || nx >= N || ny >= M)
						continue;
					if (Board_Vis[nx][ny])
						continue;
					if (st1.second + 1 > D)
						continue;

					Board_Vis[nx][ny] = true;

					Q.push({ {nx, ny}, st1.second + 1 });
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (!Enemy[i].empty())
				sort(Enemy[i].begin(), Enemy[i].end(), cmp);
		}

		for (int i = 0; i < 3; i++)
		{
			if (!Enemy[i].empty())
			{
				if (Board_Copy[Enemy[i][0].first.first][Enemy[i][0].first.second] != 0)
				{
					Board_Copy[Enemy[i][0].first.first][Enemy[i][0].first.second] = 0;
					Cnt++;
				}
			}
		}

		Enemy_Conquer(j);
	}

	return Cnt;
}

void Recurse(int U, int Idx)
{
	if (Idx == 3)
	{
		vector<pair<int, int>> V;
		for (int i = 0; i < Idx; i++)
			V.push_back({ N, Arr[i] });
		Ans = max(Ans, BFS(V));
		return;
	}

	for (int i = U; i < M; i++)
	{
		if (!Vis[i])
		{
			Vis[i] = true;
			Arr[Idx] = i;
			Recurse(i + 1, Idx + 1);
			Vis[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M >> D;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Board[i][j];
	}

	Recurse(0, 0);

	cout << Ans << '\n';
}