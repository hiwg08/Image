#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int N, M, snake[101]{ 0 }, ladder[101]{ 0 };

bool Vis[101]{ 0 };

int BFS(int Start)
{
	queue<pii> Q;

	Q.push({ Start, 0 });

	Vis[Start] = true;

	while (!Q.empty())
	{
		pii Par = Q.front();
		Q.pop();

		if (Par.first == 100)
			return Par.second;

		for (int dir = 1; dir <= 6; dir++)
		{
			int D = Par.first + dir;

			if (D > 100)
				continue;
			if (Vis[D])
				continue;
			if (ladder[D])
			{
				Vis[ladder[D]] = true;
				Q.push({ ladder[D], Par.second + 1 });
			}
			else if (snake[D])
			{
				Vis[snake[D]] = true;
				Q.push({ snake[D], Par.second + 1 });
			}
			else
			{
				Vis[D] = true;
				Q.push({ D, Par.second + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		ladder[a] = b;
	}

	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		snake[a] = b;
	}

	cout << BFS(1) << '\n';
}