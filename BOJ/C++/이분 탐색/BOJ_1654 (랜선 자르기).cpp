#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll K, N, Arr[10001]{ 0 };

bool CHK(ll mid)
{
	ll SUM = 0;

	for (int i = 0; i < K; i++)
		SUM += Arr[i] / mid;

	return SUM >= N; // �ε�ȣ�� �ٿ��� �ִ��� ���� �� �ֱ� ������...
}

ll Binary_Search()
{
	ll lo = 1, hi = (ll)((ll)1 << 31); // lo�� ����ϴ� �����̱� ������ hi�� ���� �ִ��� ���� �� �� ���� (ll)((ll)1 << 31)�� ���� �Ŵ�.
									   // WHY? �׷��� lo�� hi�� ������ ��Ȯ�ϰ� 1 ��ŭ ���̰� ���ϱ�....
									   // lo�� 1�� �� ���� �ֱ� ������ 1�� �������� ��
									   // ���࿡ hi�� ����ϴ� �ſ����� lo = 0, hi = (ll)(1 << 31) - 1�� �ư���.

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) / 2; // �� �������� �����÷ο찡 �Ͼ�� ������ �ݵ�� long long ������ ����.

		if (CHK(mid))
			lo = mid;
		else
			hi = mid;
	}

	return lo; // ������ ������ T T T T..... F F F F �̱� ������ lo�� ����ϴ� �Ŵ�. 
}

int main()
{
	cin >> K >> N;

	for (int i = 0; i < K; i++)
		cin >> Arr[i];

	cout << Binary_Search() << '\n';
}