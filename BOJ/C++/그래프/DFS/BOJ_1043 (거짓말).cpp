#include <bits/stdc++.h>

using namespace std;

int N, M, True_N, I1, S1;

bool Arr_True[51]{ 0 };

vector<vector<int>> Party;

vector<vector<int>> Graph;

int Result = 0;

void DFS(int S) // 진실됨을 전염(?)시키는 과정. DFS를 이용했다.
				// 문제 분류가 분리 집합이었으나, 분리 집합까지 가지 않고도 DFS로 쉽게 풀이가 가능하다.
{
	for (int i = 0; i < Graph[S].size(); i++)
	{
		if (Arr_True[S] && !Arr_True[Graph[S][i]])
		{
			Arr_True[Graph[S][i]] = true;
			DFS(Graph[S][i]);
		}
	}
}

int main()
{
	cin >> N >> M; // 각각 사람의 수, 파티의 개수
	cin >> True_N; // 진실을 알고있는 사람의 수

	for (int i = 0; i < True_N; i++)
	{
		cin >> I1;
		Arr_True[I1] = true;
	} // 진실을 알고있는 사람들을 배열에 담자

	// 진실을 알고있는 사람 중 적어도 한명이 임의의 파티에 참여했다면,
	// 그 파티에 있는 모든 사람이 진실을 알게 된다. 

	Graph.resize(N + 1);
	Party.resize(M + 1); // 인접 그래프를 나타내는 이차원 배열, 파티에 참석하는 인원을 담을 이차원 배열 초기화 (둘다 vector<vector<int>>)

	for (int i = 1; i <= M; i++)
	{
		cin >> I1;
		int first = 0;

		for (int j = 0; j < I1; j++)
		{
			cin >> S1;
			Party[i].push_back(S1);
			if (j != 0)
			{
				Graph[S1].push_back(first);
				Graph[first].push_back(S1); // 한 사람이 여러 파티에 참여할 수 있기 때문에 지민이가 거짓말 하고있다는 점을 전염(?)시킬 수 있다.
				// 따라서 파티가 떼어져 있더라도 결국은 한통속이다. ㅋㅋㅋㅋㅋ
			}
			first = S1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (Graph[i].size() == 0)
			continue;
		sort(Graph[i].begin(), Graph[i].end());
		Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end()); // 중복된 원소를 제거
	}

	for (int i = 1; i <= N; i++)
		DFS(i);

	for (int i = 1; i <= M; i++)
	{
		bool CHK = false;
		for (auto e : Party[i])
		{
			if (Arr_True[e])
				CHK = true;
		}
		if (!CHK)
			Result++;
	} // 진실을 알고있는 파티는 카운트에서 제외시키자.

	cout << Result << '\n';
}