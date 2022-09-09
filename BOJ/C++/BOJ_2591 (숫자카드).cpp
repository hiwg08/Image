#include <bits/stdc++.h>

using namespace std;

string S;

long long N, DP[41]{ 0 };

long long Solve(long long Idx)
{
	if ((int)(S[Idx] - '0') == 0)
		return 0;

	if (Idx == N)
		return 1;

	long long& ret = DP[Idx];

	if (ret != -1)
		return ret;

	ret = Solve(Idx + 1);

	if (Idx <= N - 2 && stoi(S.substr(Idx, 2)) <= 34)
		ret += Solve(Idx + 2);

	return ret;
}

int main() // 0�� ���� ���� ����. (1���� 34������ ī�常 �����߱� ����)
		   // + �Ǽ��ϱ� ����....
{
	cin >> S;

	N = (long long)S.size();

	memset(DP, -1, sizeof(DP));

	cout << Solve(0) << '\n';
}