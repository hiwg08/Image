#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>
#define f first
#define s second

using namespace std;

int N, Board[101][101]{ 0 }, MIN = INT_MAX, MAX = INT_MIN;

bool Vis[101][101]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

// BFS는 항상 가까운 거리를 우선적으로 돌기 때문에 최소, 최대값을 저장해가면서
// 탐색하는 건 아무런 의미가 없다.
// 그래서 탐색할 수 있는 간격(min ~ max)을 내가 직접 줘야한다.
// 그 간격을 빠르게 줄여줄 수 있는 방법으로 이분 탐색이 있다는 뜻
// 당연하겠지만, 간격이 넓을 수록 탐색할 범위가 넓어지고, 좁을 수록 탐색할 범위가 주니까...
// yes or no가 확실히 정해지기 때문에 이분 탐색을 쓸 수 있다.


bool BFS(int L, int R)
{
	if (Board[0][0] < L || Board[0][0] > R)
		return false;

	queue<pii> Q;

	Q.push({ 0, 0 });

	Vis[0][0] = true;

	while (!Q.empty())
	{
		pii T1 = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = T1.f + dx[dir], ny = T1.s + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;

			if (Vis[nx][ny])
				continue;

			if (Board[nx][ny] < L || Board[nx][ny] > R)
				continue;

			Vis[nx][ny] = true;
			Q.push({ nx, ny });
		}
	}

	return Vis[N - 1][N - 1];
}

int solve()
{
	int lo = -1, hi = MAX - MIN;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) >> 1;

		bool CHK = false;

		for (int i = MIN; i <= MAX - mid; i++)
		{
			memset(Vis, false, sizeof(Vis));

			if (BFS(i, i + mid))
			{
				CHK = true;
				break;
			}
		}
		CHK ? hi = mid : lo = mid;
	}

	return hi;
}

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Board[i][j];
			MIN = min(MIN, Board[i][j]), MAX = max(MAX, Board[i][j]);
		}
	}

	cout << solve() << '\n';
}