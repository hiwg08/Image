#include <bits/stdc++.h>

using namespace std;

int Q, E, W, S, N;

bool Vis[51][51]{ 0 }; // 로봇은 최대 14번 이동 가능. (4^14). 그러나 본래 위치로 되돌아오는 행위를 "백트래킹"으로 막아주면 시간 복잡도가 확 줄어든다.
				       // 처음에는 어느 위치에서 탐색하는 지 문제에 주어져있지 않았으므로 걍 20, 20 넣은 거다.

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

double P[4];

double Solve(int x, int y, double Prob, int Cnt)
{
	if (Cnt >= Q)
		return Prob; // 로봇이 이미 탐색했던 자리로 오지 않고 온전히 Q번까지 왔으면 누적했던 확률 값을 반환.

	double ret = 0; // 동, 서, 남, 북 다 돌았는데도 확률이 없을 수 있으므로 초기값은 당연히 0이다.

	Vis[x][y] = true; // 해당 자리를 탐색했다가

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir], ny = y + dy[dir];

		if (Vis[nx][ny])
			continue;
		ret += Solve(nx, ny, Prob * P[dir], Cnt + 1); // 동, 서, 남, 북 탐색 결과 확률을 누적.
	}

	Vis[x][y] = false; // 다 돌고나서 풀어주자. (다른 노드도 탐색할 수 있도록)

	return ret;
}

int main()
{
	cin >> Q >> E >> W >> S >> N;

	P[0] = (double)S / (double)100;
	P[1] = (double)E / (double)100;
	P[2] = (double)N / (double)100;
	P[3] = (double)W / (double)100;

	double Ans = Solve(20, 20, 1, 0);

	cout.precision(10); // 상대 오차가 10^-9였기에 10자리로 자르자.

	cout << fixed << Ans << '\n';
}