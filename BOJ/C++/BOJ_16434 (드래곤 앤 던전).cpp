#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 999999000001 * 123456
#define ll long long

using namespace std;

ll N, Attack, a, b, c;

vector<pair<ll, pair<ll, ll>>> Dungeon;

bool Explore_Dungeon(ll MAX_HP)
{
	ll R_Attack = Attack;
	ll Current_HP = MAX_HP;

	for (int i = 0; i < N; i++)
	{
		if (Dungeon[i].first == 2)
		{
			R_Attack += Dungeon[i].second.first;
			Current_HP + Dungeon[i].second.second > MAX_HP ? Current_HP = MAX_HP : Current_HP += Dungeon[i].second.second;
		}
		else
			Dungeon[i].second.second% R_Attack == 0 ? Current_HP -= Dungeon[i].second.first * (Dungeon[i].second.second / R_Attack - 1) : Current_HP -= Dungeon[i].second.first * (Dungeon[i].second.second / R_Attack);

		if (Current_HP <= 0)
			return false;
	}
	return true;
}

ll Binary_Search()
{
	ll lo = 0, hi = MAX + 1;

	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) / 2;

		if (Explore_Dungeon(mid))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main()
{
	fastio;

	cin >> N >> Attack;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		Dungeon.push_back({ a, {b, c} });
	}

	cout << Binary_Search() << '\n';
}