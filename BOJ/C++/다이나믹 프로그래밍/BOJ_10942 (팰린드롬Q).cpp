#include <bits/stdc++.h>

using namespace std;

int N, M, I1, I2;

int Board[2001]{ 0 };

int DP[2001][2001]{ 0 };

// ****���̳��� ���α׷����� ���� �ƴ�, Ž���� �κа� �� �� �κ��� ������ ������ �Ѵ�.

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Board[i];

	memset(DP, -1, sizeof(DP));

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; j++)
		{
			DP[i][j] = Solution(i, j);
		}
	} // ���Ʈ ���� ��� (2000 * 2000 = 400�����̾ 0.5�ʸ� �ʰ��� �� ������, DP Ư¡ ������ ���� �� �ص� �ȴ�.)

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> I1 >> I2;
		cout << DP[I1][I2] << '\n';
	}
}