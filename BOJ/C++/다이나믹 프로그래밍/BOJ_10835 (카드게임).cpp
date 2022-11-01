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

int main() // ������ DP����. 1���� DP�� �ذ��� �� ���� ������, ���� ���̿� ������ ������ ī�� ������ ���� ������ ������ �����ϰ� �ٲ�� �����̴�.
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