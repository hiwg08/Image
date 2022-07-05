#include <bits/stdc++.h>

using namespace std;

int N, M, I1, I2;

int Board[2501]{ 0 };

int DP[2501][2501]{ 0 };

int Ans[2501]{ 0 };

string ST;

int ST_Length;

int Min = 3000;

// 백준 10942에서 사용한 팰린드롬 알고리즘 + 최소 집합 판별 (DP 2번 사용)

int Solution(int start, int end)
{
	int& ref = DP[start][end];

	if (ref != -1)
		return ref;

	if (start > end)
		return 1;

	if (start == end)
		return ref = 1;

	if (Board[start] != Board[end])
		return ref = 0;

	return ref = Solution(start + 1, end - 1);
}

int Solution2(int start)
{
	int& ref = Ans[start];

	if (ref != 2139062143)
		return ref;
	if (start == ST_Length)
		return 1;
	if (start > ST_Length)
		return 0;
	for (int i = start; i <= ST_Length; i++)
	{
		if (DP[start][i] == 1)
			ref = min(ref, Solution2(i + 1) + 1);
		else
			continue;
	}
	return ref;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> ST;
	ST_Length = static_cast<int>(ST.length());

	memset(DP, -1, sizeof(DP));
	memset(Ans, 0x7F, sizeof(Ans));

	for (int i = 0; i < ST_Length; i++)
		Board[i + 1] = static_cast<int>(ST[i]);

	for (int i = 1; i <= ST_Length; i++)
	{
		for (int j = i; j <= ST_Length; j++)
			DP[i][j] = Solution(i, j);
	} // 1. 팰린드롬 유무 확인

	cout << Solution2(1) << '\n'; // 2. 최소 집합 구하기
}