#include <bits/stdc++.h>

using namespace std;

long long N, I1, I2;

char C1;

class Island_Info
{
public:
	char kind;
	long long cnt;

	Island_Info(char a = 0, long long b = 0)
		:kind(a), cnt(b)
	{}
};

vector<vector<long long>> Graphs;

map<long long, Island_Info> Island;

long long DFS(long long Index) // �ܹ��� �׷����̱� ������ �湮 ���� �迭�� �ʿ����.
{
	long long SUM = 0;

	if (Island[Index].kind == 'S') // ���� ��尡 ���� �� ���� ���ϱ�
		SUM += Island[Index].cnt;

	for (int i = 0; i < Graphs[Index].size(); i++)
		SUM += DFS(Graphs[Index][i]); // �ڽ� ���鿡 ���� ���� ������ ���ϱ�

	if (Island[Index].kind == 'W') // ���� ��尡 ����� ������ �� ��ŭ �� ����
	{
		SUM -= Island[Index].cnt;
		if (SUM < 0)
			SUM = 0;
	}

	return SUM;
}

void Input()
{
	cin >> N;

	Graphs.resize(N + 2);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> C1;
		cin >> I1 >> I2;

		Graphs[I2].push_back(i + 2);
		Island[i + 2] = Island_Info(C1, I1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Input();

	cout << DFS(1) << '\n';
}