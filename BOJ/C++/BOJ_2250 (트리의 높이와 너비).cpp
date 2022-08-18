#include <bits/stdc++.h>

using namespace std;

// 루트 노드가 1이라는 보장이 없다.

int N, I1, I2, I3;

bool Vis[10001]{ 0 };

int Root;

int H_MAX = INT_MIN, Result_Width = INT_MIN, Result_Num;

vector<vector<int>> Trees, Ans;

map<int, pair<int, int>> INFO;

int DFS(int Idx, int H, int W) // 자식의 개수 구하기...
{
	int Left = 0, Right = 0;

	if (Trees[Idx][0] != -1)
		Left = DFS(Trees[Idx][0], H + 1, W);

	H_MAX = max(H_MAX, H);
	INFO[Idx] = { H, W + Left + 1 };

	if (Trees[Idx][1] != -1)
		Right = DFS(Trees[Idx][1], H + 1, W + Left + 1);

	return Left + Right + 1;
}

// 중위 순회

int main()
{
	cin >> N;

	Trees.resize(N + 1);
	Ans.resize(N + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> I1 >> I2 >> I3;
		Trees[I1].push_back(I2);
		Trees[I1].push_back(I3);
		if (I2 != -1)
			Vis[I2] = true;
		if (I3 != -1)
			Vis[I3] = true;
	} // 자식으로 삼지 않는 녀석을 고르자.

	for (int i = 1; i <= N; i++)
	{
		if (!Vis[i])
		{
			Root = i;
			break;
		}
	}

	DFS(Root, 1, 0);

	for (auto it = INFO.begin(); it != INFO.end(); it++)
		Ans[it->second.first].push_back(it->second.second);

	for (int i = 1; i <= H_MAX; i++)
	{
		sort(Ans[i].begin(), Ans[i].end());
		if (Result_Width < Ans[i][Ans[i].size() - 1] - Ans[i][0] + 1)
		{
			Result_Width = Ans[i][Ans[i].size() - 1] - Ans[i][0] + 1;
			Result_Num = i;
		}
	}

	cout << Result_Num << " " << Result_Width << '\n';
}