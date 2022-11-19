#include <bits/stdc++.h>
#define MOD 100000

using namespace std;

int W, H, DP[101][101][2][2]{ 0 };

int dx[]{ 1, 0 };
int dy[]{ 0, 1 };

// 이걸 DP로 풀 수 있는 이유는 DAG라서 그렇다.
// 사이클이 도는 거라면 DP를 적용하기 어렵다.

int solve(int x, int y, bool dir, int move)
{
	if (x >= W || y >= H)
		return 0;

	if (x == W - 1 && y == H - 1)
		return 1; // 기저 조건은 간단하다. (목적지에 도착하냐? 배열을 벗어나냐?)

	int& ret = DP[x][y][dir][move];

	if (ret != -1)
		return ret;

	ret = 0;

	if (x == 0 && y == 0)
	{
		ret += (solve(x + dx[0], y + dy[0], 0, 0) % MOD);
		ret += (solve(x + dx[1], y + dy[1], 1, 0) % MOD);
	} // 구현의 헷갈림을 막기 위해 x = 0, y = 0일 때를 추가.
	else
	{
		if (move == 0)
		{
			ret += (solve(x + dx[dir], y + dy[dir], dir, 0) % MOD);
			ret += (solve(x + dx[!dir], y + dy[!dir], !dir, 1) % MOD); // 교차로를 건너지 않았으면 두 갈래로 이동.
		}
		else
			ret += (solve(x + dx[dir], y + dy[dir], dir, 0) % MOD); // 교차로를 건넌 상태이면 무조건 같은 방향 이동 후 제한을 풀어준다.
	}

	return ret % MOD;
}

int main()
{
	cin >> W >> H;

	memset(DP, -1, sizeof(DP));

	cout << solve(0, 0, 0, 0) << '\n';
}