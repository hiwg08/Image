#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

string I;

bool Vis[5][5]{ 0 }; // 이 배열을 학생 결합 + 백트래킹 같이 쓰고 있었다.... 왜이렇게 실수가 많지 나는

int Board[5][5]{ 0 };

char Student[5][5]{ 0 };

int Ans;

vector<pii> V;

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int BFS(int x, int y)
{
	memset(Vis, false, sizeof(Vis));

	int Som = 0, Yeon = 0;

	queue<pii> Q;

	Vis[x][y] = true;

	Q.push({ x, y });

	while (!Q.empty())
	{
		pii P = Q.front();
		Q.pop();
		if (Student[P.f][P.s] == 'Y') Yeon++;
		else Som++;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = P.f + dx[dir];
			int ny = P.s + dy[dir];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
				continue;
			if (Vis[nx][ny])
				continue;
			if (Board[nx][ny] == 0)
				continue;

			Vis[nx][ny] = true;
			Q.push({ nx, ny });

		}
	}

	if (Som + Yeon == 7 && Som > Yeon)
		return 1;
	return 0;
}

void Rec(int x, int y, int Cnt)
{
	if (Cnt == 7)
	{
		Ans += BFS(V[0].f, V[0].s);
		return;
	}

	while (x < 5)
	{
		while (y < 5)
		{
			if (Board[x][y] == 1)
				continue;

			Board[x][y] = 1;
			V.push_back({ x, y });
			Rec(x, y + 1, Cnt + 1);
			Board[x][y] = 0;
			V.pop_back();
			y++;
		}
		y = 0;
		x++;
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		cin >> I;
		for (int j = 0; j < 5; j++)
			Student[i][j] = I[j];
	}

	Rec(0, 0, 0);

	cout << Ans << '\n';
}