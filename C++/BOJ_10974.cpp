#include <bits/stdc++.h>

using namespace std;

int N;

int Arr[10]{ 0 };

bool Vis[10]{ 0 };

int CNT;

void Solution(int Index)
{
	if (Index >= N)
	{
		CNT++;
		for (int i = 0; i < N; i++)
			cout << Arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (Arr[Index] != 0)
			continue;
		if (Vis[i])
			continue;

		Vis[i] = true;
		Arr[Index] = i;

		Solution(Index + 1);

		Vis[i] = false;
		Arr[Index] = 0;
	}
}

int main() // 혼자 해본 백트래킹 기초 문제
{
	cin >> N;

	Solution(0);
}