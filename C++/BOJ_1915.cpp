#include <bits/stdc++.h>

using namespace std;

int N, M;

int Map[1001][1001]{ 0 };

int DP[1001][1001]{ 0 };

string s;

int Ans = -9999999;

void Solve() // �ݺ����� ����� DP. ���簢�� �迭(n * m)�� �Ųٷ� Ž���ؼ� ���簢���� �ִ� ���̸� ���Ѵ�.
			 // �������� �䱸�ϴ°� ������ �ִ������� ����, ����, �缱 ���⿡ ��ġ�� 1�� ������ ���� ���簢���� ���� �� �ִ� ������ �ֱ� ������ max�� �ƴԿ� �����ؾ��Ѵ�. 
{
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = M - 1; j >= 0; j--)
		{
			if (Map[i][j] != 1)
				continue;

			if (i == N - 1)
				DP[i][j] = 1;
			else
				DP[i][j] = min(DP[i + 1][j + 1], min(DP[i + 1][j], DP[i][j + 1])) + 1; // ���̸� ���ϴ� ��ȭ��

			Ans = max(Ans, DP[i][j]); // ���� ��ü�� �ִ��̹Ƿ� ��� �迭���� �ִ� ����
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < M; j++)
			Map[i][j] = static_cast<int>(s[j] - 48);
	}

	Solve();
	if (Ans == -9999999)
		cout << 0 << '\n';
	else
		cout << Ans * Ans << '\n';
}