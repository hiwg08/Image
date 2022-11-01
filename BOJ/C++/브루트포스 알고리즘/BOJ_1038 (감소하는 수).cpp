#include <bits/stdc++.h>

using namespace std;

int N, CHK = -1;

void Recurse(int Cnt, int Pre, string S) // �ڸ����� ��Ÿ���� Cnt, ���� ������ Pre, �����ϴ� ���� ���ڿ� S
{
	if (Cnt == 0)
	{
		if (++CHK == N) // ����ڰ� �Է��� ��°�� ���� ����� �� �ٷ� ���α׷� ����.
		{
			cout << S << '\n';
			exit(0);
		}
		return;
	}

	if (Pre == -1)
		return; // ���ҽ��״� ���� ������ �������� �����Ƿ� ����

	for (int i = 0; i <= Pre; i++) // for���� 0���� �����ؾ��Ѵ�. �׷��� �����ϴ� ���� ������ ��ų �� �ִ�. ex. 10 -> "20" -> 21 -> "30" -> 31 -> 32 -> ...
		Recurse(Cnt - 1, i - 1, S + to_string(i)); // ���� �ִ� ��(i) + ������ ������ �� (i - 1)
}

int main()
{
	cin >> N;

	for (int i = 1; i <= 10; i++)
		Recurse(i, 9, ""); // 10���� �ڸ�����ŭ �ݺ�

	cout << -1 << '\n'; // 1024 �̻�(<= 1,000,000)�� ������ ��� -1 ���.
}