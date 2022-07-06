#include <bits/stdc++.h>

using namespace std;

int N, M, True_N, I1, S1;

bool Arr_True[51]{ 0 };

vector<vector<int>> Party;

vector<vector<int>> Graph;

int Result = 0;

void DFS(int S) // ���ǵ��� ����(?)��Ű�� ����. DFS�� �̿��ߴ�.
				// ���� �з��� �и� �����̾�����, �и� ���ձ��� ���� �ʰ� DFS�� ���� Ǯ�̰� �����ϴ�.
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
	cin >> N >> M; // ���� ����� ��, ��Ƽ�� ����
	cin >> True_N; // ������ �˰��ִ� ����� ��

	for (int i = 0; i < True_N; i++)
	{
		cin >> I1;
		Arr_True[I1] = true;
	} // ������ �˰��ִ� ������� �迭�� ����

	// ������ �˰��ִ� ��� �� ��� �Ѹ��� ������ ��Ƽ�� �����ߴٸ�,
	// �� ��Ƽ�� �ִ� ��� ����� ������ �˰� �ȴ�. 

	Graph.resize(N + 1);
	Party.resize(M + 1); // ���� �׷����� ��Ÿ���� ������ �迭, ��Ƽ�� �����ϴ� �ο��� ���� ������ �迭 �ʱ�ȭ (�Ѵ� vector<vector<int>>)

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
				Graph[first].push_back(S1); // �� ����� ���� ��Ƽ�� ������ �� �ֱ� ������ �����̰� ������ �ϰ��ִٴ� ���� ����(?)��ų �� �ִ�.
				// ���� ��Ƽ�� ������ �ִ��� �ᱹ�� ������̴�. ����������
			}
			first = S1;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (Graph[i].size() == 0)
			continue;
		sort(Graph[i].begin(), Graph[i].end());
		Graph[i].erase(unique(Graph[i].begin(), Graph[i].end()), Graph[i].end()); // �ߺ��� ���Ҹ� ����
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
	} // ������ �˰��ִ� ��Ƽ�� ī��Ʈ���� ���ܽ�Ű��.

	cout << Result << '\n';
}