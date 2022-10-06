#include <bits/stdc++.h>

using namespace std;

int N, Cnt = 0;

vector<int> V;

void Recurse(int Idx, int U)
{
	if (Idx == 1)
	{
		Cnt++;
		V.push_back(U);

		if (Cnt == N + 1)
		{
			for (auto e : V)
				cout << e;
			cout << '\n';
			exit(0);
		}

		V.pop_back();
		return;
	}

	if (U == 0)
		return;

	for (int i = 0; i < U; i++)
	{
		V.push_back(U);
		Recurse(Idx - 1, i);
		V.pop_back();
	}
}

int main()
{
	cin >> N;

	for (int k = 1; k <= 10; k++)
	{
		for (int i = k - 1; i <= 9; i++)
			Recurse(k, i);
	}

	cout << -1 << '\n';

}