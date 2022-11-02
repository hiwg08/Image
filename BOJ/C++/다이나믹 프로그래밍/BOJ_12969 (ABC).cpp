#include <bits/stdc++.h>

using namespace std;

int N, K;

int DP[31][31][31][436]{ 0 };

string Ans[31];

int solve(int a, int b, int c, int Remain) // DP[a][b][c][Remain] : 현재까지 a, b, c를 각각의 개수만큼 사용했을 때 나오는 문자열의 가짓수(remain) (true / false)
{
	if (a + b + c == N)
	{
		if ((a > 0 && b > 0 && c > 0) && Remain == K) return 1;
		return 0;
	} // 시간 초과가 안 나오는게 신기하네

	int& ret = DP[a][b][c][Remain];

	if (ret != -1)
		return ret;

	if (solve(a + 1, b, c, Remain))
	{
		Ans[a + b + c] = "A";
		return ret = 1;
	}
	if (solve(a, b + 1, c, Remain + a))
	{
		Ans[a + b + c] = "B";
		return ret = 1;
	}
	if (solve(a, b, c + 1, Remain + a + b))
	{
		Ans[a + b + c] = "C";
		return ret = 1;
	}

	return ret = 0;
}

int main()
{
	cin >> N >> K;

	memset(DP, -1, sizeof(DP));

	if (solve(0, 0, 0, 0))
	{
		for (int i = 0; i < N; i++)
			cout << Ans[i];
		cout << '\n';
	}
	else
		cout << -1 << '\n';
}