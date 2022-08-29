#include <bits/stdc++.h>

using namespace std;

int N, M, Result = INT_MAX;

int Map[51][51]{ 0 };

int Arr[51]{ 0 };
bool Vis[51]{ 0 };

vector<pair<int, int>> House, Chicken;

int Get_Manhatan(vector<pair<int, int>>& Chicken_Copy)
{
	int Chicken_Distance = 0;
	for (int i = 0; i < House.size(); i++)
	{
		int MIN = INT_MAX;
		for (int j = 0; j < Chicken_Copy.size(); j++)
			MIN = min(MIN, abs(House[i].first - Chicken_Copy[j].first) + abs(House[i].second - Chicken_Copy[j].second));

		Chicken_Distance += MIN;
	}
	return Chicken_Distance;
}


void Combination(int Idx, int U, int Num)
{
	if (Idx == Num)
	{
		vector<pair<int, int>> Chicken_Copy;
		for (int i = 0; i < Idx; i++)
			Chicken_Copy.push_back({ Chicken[Arr[i]].first, Chicken[Arr[i]].second });

		Result = min(Result, Get_Manhatan(Chicken_Copy));

		return;
	}
	for (int i = U; i < Chicken.size(); i++)
	{
		if (!Vis[i])
		{
			Vis[i] = true;
			Arr[Idx] = i;
			Combination(Idx + 1, i + 1, Num);
			Vis[i] = false;
		}
	}
}

int main() // 멍청하게 맨해튼 거리를 BFS로 접근했다가 시간초과가 3번 떠버린 문제... 반성하자. 
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];
			if (Map[i][j] == 2)
				Chicken.push_back({ i, j });
			if (Map[i][j] == 1)
				House.push_back({ i, j });
		}
	}

	for (int i = 1; i <= M; i++)
	{
		memset(Arr, 0, sizeof(Arr));
		memset(Vis, false, sizeof(Vis));
		Combination(0, 0, i);
	}

	cout << Result << '\n';
}