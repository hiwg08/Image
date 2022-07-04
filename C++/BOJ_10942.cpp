#include <bits/stdc++.h>

using namespace std;

int N, M, I1, I2;

int Board[2010]{ 0 };

int DP1[2010][2010]{ 0 };

void Solution(int first, int second) // ��� ���� (DP) (-1 : Ž���� �� �� �κ�, 0 : Ž���� ��� �Ӹ���� X, 1 : Ž���� ��� �Ӹ���� O)
{
	if (DP1[first][second] != -1)
		return;

	DP1[first][second] = 1;

	if (first - 1 > 0 && second + 1 < N + 1)
	{
		if (Board[first - 1] == Board[second])
			Solution(first - 1, second);
		else
			DP1[first - 1][second] = 0; // ���ʿ��� ��������

		if (Board[first] == Board[second + 1])
			Solution(first, second + 1);
		else
			DP1[first][second + 1] = 0; // �����ʿ��� ��������

		if (Board[first - 1] == Board[second + 1])
			Solution(first - 1, second + 1);
		else
			DP1[first - 1][second + 1] = 0; // ���� + �����ʿ��� ��������
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(DP1, -1, sizeof(DP1));

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> Board[i];

	for (int i = 1; i <= N; i++)
		Solution(i, i);

	cin >> M;
	for (int i = 1; i <= M; i++)
	{
		cin >> I1 >> I2;
		if (DP1[I1][I2] == 1)
			cout << 1 << '\n';
		else // Ž���� �� �� �κе� ���� �Ӹ������ �ƴϴ�.
			cout << 0 << '\n';
	}
}