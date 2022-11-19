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

// BFS�� �׻� ����� �Ÿ��� �켱������ ���� ������ �ּ�, �ִ밪�� �����ذ��鼭
// Ž���ϴ� �� �ƹ��� �ǹ̰� ����.
// �׷��� Ž���� �� �ִ� ����(min ~ max)�� ���� ���� ����Ѵ�.
// �� ������ ������ �ٿ��� �� �ִ� ������� �̺� Ž���� �ִٴ� ��
// �翬�ϰ�����, ������ ���� ���� Ž���� ������ �о�����, ���� ���� Ž���� ������ �ִϱ�...
// yes or no�� Ȯ���� �������� ������ �̺� Ž���� �� �� �ִ�.


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