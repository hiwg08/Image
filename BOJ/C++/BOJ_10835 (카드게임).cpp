#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Left[2001]{ 0 }, Right[2001]{ 0 }, DP[2001][2001]{ 0 };

int Solve(int Q, int W)
{
	if (Q >= N || W >= N)
		return 0;

	int& ret = DP[Q][W];

	if (ret != -1)
		return ret;

	ret = max({ ret, Solve(Q + 1, W), Solve(Q + 1, W + 1) });

	if (Left[Q] > Right[W])
		ret = max(ret, Solve(Q, W + 1) + Right[W]);

	return ret;
}

int main() // 무난한 DP문제. 1차원 DP로 해결할 수 없는 이유는, 왼쪽 더미와 오른쪽 더미의 카드 개수가 턴을 진행할 때마다 상이하게 바뀌기 때문이다.
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Left[i];

	for (int i = 0; i < N; i++)
		cin >> Right[i];

	memset(DP, -1, sizeof(DP));

	cout << Solve(0, 0) << '\n';
}