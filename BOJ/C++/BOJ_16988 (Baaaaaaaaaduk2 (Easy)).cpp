#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N, M, Board[21][21]{ 0 }, Vis_R[21][21]{ 0 }, Vis[21][21]{ 0 }, MAX = 0;

vector<pii> Zero;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int Ret(int x, int y)
{
	bool Zero_Met = false;

	queue<pii> Q;

	int Cnt = 0;

	Vis[x][y] = true;

	Q.push({ x, y });

	while (!Q.empty())
	{
		pii P = Q.front();
		Q.pop();

		Cnt++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = P.f + dx[dir];
			int ny = P.s + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;

			if (Vis[nx][ny])
				continue;

			if (Board[nx][ny] == 1)
				continue;

			if (Board[nx][ny] == 0)
			{
				Zero_Met = true;
				continue;
			}

			Vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}

	if (Zero_Met)
		return 0;
	return Cnt;
}

int BFS()
{
	memset(Vis, false, sizeof(Vis)); // 탐색하는 배열이 매번 달라지기에 초기화

	int Cnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!Vis[i][j] && Board[i][j] == 2)
				Cnt += Ret(i, j);
		}
	}

	return Cnt;
}

void Recurse(int U, int Idx)
{
	if (Idx == 2)
	{
		MAX = max(MAX, BFS());
		return;
	}
	for (int i = U; i < (int)Zero.size(); i++)
	{
		if (Vis_R[Zero[i].f][Zero[i].s])
			continue;
		Vis_R[Zero[i].f][Zero[i].s] = true;
		Board[Zero[i].f][Zero[i].s] = 1;
		Recurse(i + 1, Idx + 1);
		Vis_R[Zero[i].f][Zero[i].s] = false;
		Board[Zero[i].f][Zero[i].s] = 0;
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
			if (Board[i][j] == 0)
				Zero.push_back({ i, j });
		}
	}

	memset(Vis, false, sizeof(Vis)); // 탐색하는 배열이 매번 달라지기에 초기화

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!Vis[i][j] && Board[i][j] == 2)
				MAX = max(MAX, Ret(i, j));
		}
	}

	Recurse(0, 0);

	cout << MAX << '\n';
}

// 1. 배열 중 0인 곳에 내 돌(숫자 : 1)을 2개 넣을 수 있으므로, 0인 곳을 벡터에 넣어준다.
// 2. 나의 돌을 넣을 수 있는 "조합"을 구한 후, 그 케이스에 대해 BFS를 돌린다.
// 3. 주의할 점은 BFS 돌릴 때, 최댓값 반환이 아니라, 에워쌓여진 상대방 돌의 개수를 전부 누적한 후, 그거와의 최댓값을 갱신해야 한다.

// 3번이 부족했던 것 같다.... 익숙한 문제일 수록 설계를 확실히 해야할 것 같다.

// 400C2 = 79800, BFS 탐색 시간복잡도 O(4NM) (여기서는 4 * 20 * 20 = 1600) = 127,680,000
// ... 그래서 아마 시간이 이렇게나 오래 걸리지 않았나 싶다
// 나중에 시간 되면 시간 줄일 방법을 모색해야겠다.