#include <bits/stdc++.h>

using namespace std;

int N, M, Board[9][9]{ 0 }, CCTV_Cnt, Ans = INT_MAX;

vector<pair<int, int>> CCTV;

map<int, vector<vector<int>>> CCTV_Dir;

int dx[]{ 1, 0,-1, 0 };
int dy[]{ 0, 1, 0, -1 };

void Init()
{
	CCTV_Dir[1] = { {0}, {1}, {2}, {3} };
	CCTV_Dir[2] = { {0, 2}, {1, 3} };
	CCTV_Dir[3] = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };
	CCTV_Dir[4] = { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} };
	CCTV_Dir[5] = { {0, 1, 2, 3} };
}

void Make_Board(int x, int y, int Dir, int Params)
{
	int nx = x, ny = y;

	while (true)
	{
		nx += dx[Dir];
		ny += dy[Dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			break;
		if (Board[nx][ny] == 6)
			break;
		if (Board[nx][ny] < 1 || Board[nx][ny] > 5)
			Board[nx][ny] += Params;
	}
}

int Bottom_Num()
{
	int Cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			Board[i][j] == 0 ? Cnt++ : Cnt += 0;
	}

	return Cnt;
}

void Recurse(int Idx)
{
	if (Idx == CCTV_Cnt)
	{
		Ans = min(Ans, Bottom_Num());
		return;
	}

	for (auto q : CCTV_Dir[Board[CCTV[Idx].first][CCTV[Idx].second]])
	{
		for (auto e : q)
			Make_Board(CCTV[Idx].first, CCTV[Idx].second, e, -1);

		Recurse(Idx + 1);

		for (auto e : q)
			Make_Board(CCTV[Idx].first, CCTV[Idx].second, e, 1);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Board[i][j];

			if (Board[i][j] >= 1 && Board[i][j] <= 5)
				CCTV.push_back({ i, j });
		}
	}

	Init();

	CCTV_Cnt = (int)CCTV.size();

	Recurse(0);

	cout << Ans << '\n';
}