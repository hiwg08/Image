#include <bits/stdc++.h>

using namespace std;

int Q, E, W, S, N;

bool Vis[51][51]{ 0 }; // �κ��� �ִ� 14�� �̵� ����. (4^14). �׷��� ���� ��ġ�� �ǵ��ƿ��� ������ "��Ʈ��ŷ"���� �����ָ� �ð� ���⵵�� Ȯ �پ���.
				       // ó������ ��� ��ġ���� Ž���ϴ� �� ������ �־������� �ʾ����Ƿ� �� 20, 20 ���� �Ŵ�.

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

double P[4];

double Solve(int x, int y, double Prob, int Cnt)
{
	if (Cnt >= Q)
		return Prob; // �κ��� �̹� Ž���ߴ� �ڸ��� ���� �ʰ� ������ Q������ ������ �����ߴ� Ȯ�� ���� ��ȯ.

	double ret = 0; // ��, ��, ��, �� �� ���Ҵµ��� Ȯ���� ���� �� �����Ƿ� �ʱⰪ�� �翬�� 0�̴�.

	Vis[x][y] = true; // �ش� �ڸ��� Ž���ߴٰ�

	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir], ny = y + dy[dir];

		if (Vis[nx][ny])
			continue;
		ret += Solve(nx, ny, Prob * P[dir], Cnt + 1); // ��, ��, ��, �� Ž�� ��� Ȯ���� ����.
	}

	Vis[x][y] = false; // �� ������ Ǯ������. (�ٸ� ��嵵 Ž���� �� �ֵ���)

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

	cout.precision(10); // ��� ������ 10^-9���⿡ 10�ڸ��� �ڸ���.

	cout << fixed << Ans << '\n';
}