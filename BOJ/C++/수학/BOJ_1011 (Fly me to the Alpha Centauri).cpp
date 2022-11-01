#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

map<long long, long long> Centauri;

long long CNT = 2, CHK = 2, Idx = 2, Distance, T;

void Init()
{
	Centauri[1] = 1;
	Centauri[2] = 2;

	while (CHK <= INT_MAX)
	{
		for (int i = 0; i < 2; i++)
		{
			CHK += CNT;
			Idx++;
			Centauri[CHK] = Idx;
		}
		CNT++;
	}
}

int main()
{
	fastio;

	Init();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		long long a, b; cin >> a >> b;

		Distance = b - a;

		for (auto it = Centauri.begin(); it != Centauri.end(); it++)
		{
			if (it->first >= Distance)
			{
				cout << it->second << '\n';
				break;
			}
		}
	}
}