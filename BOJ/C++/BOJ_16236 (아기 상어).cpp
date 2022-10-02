#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Map[21][21]{ 0 }, B_X, B_Y, B_Huge, Eat_Cnt, Ans;

bool Vis[21][21]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if (a.second == b.second)
	{
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first.first < b.first.first;
	}
	return a.second < b.second;
}

void BFS()
// ���κ��� ũ�Ⱑ ū ����� ĭ�� ������ �� ����
// �����̶� ũ�Ⱑ ������ ������ ���� �ִµ�, ���� ���� ����
{
	while (true)
	{
		queue<pair<pair<int, int>, int>> Q; // �� ������ �μ��� �Ÿ�

		vector<pair<pair<int, int>, int>> V;

		Q.push({ {B_X, B_Y}, 0 });

		memset(Vis, false, sizeof(Vis));

		Vis[B_X][B_Y] = true;

		while (!Q.empty())
		{
			pair<pair<int, int>, int> st1 = Q.front();
			Q.pop();

			if (Map[st1.first.first][st1.first.second] != 0 && Map[st1.first.first][st1.first.second] < B_Huge) 
				// ********************************
				// �� �κ��� �����߾�� �ߴ�.... IDE ���� Ǯ�� �;��µ�, ������ �� ������ �Ƿ��� �ƴѰ� ����.
			{
				V.push_back({ {st1.first.first, st1.first.second}, st1.second });
				continue;
			}

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = st1.first.first + dx[dir];
				int ny = st1.first.second + dy[dir];

				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					continue;
				if (Vis[nx][ny])
					continue;
				if (Map[nx][ny] > B_Huge)
					continue;
				if (Map[nx][ny] == 0 || Map[nx][ny] <= B_Huge)
				{
					Vis[nx][ny] = true;
					Q.push({ {nx, ny}, st1.second + 1 });
				}
			}
		}

		if (V.size() == 0)
			break;

		sort(V.begin(), V.end(), cmp);

		Ans += V[0].second;

		Map[V[0].first.first][V[0].first.second] = 0;

		B_X = V[0].first.first, B_Y = V[0].first.second;

		Eat_Cnt++;

		if (B_Huge == Eat_Cnt)
		{
			Eat_Cnt = 0;
			B_Huge++;
		}
	}
}

void Input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 9)
			{
				Map[i][j] = 0;
				B_X = i;
				B_Y = j;
			}
		}
	}

	B_Huge = 2;
}

int main() // ��� 3�� �ʹ� ����, ��� 4~5�� ������
		   // �������� �ܼ� ����. ���� ���ƴ� �κ� (��ǥ �� ģ �κ� ������;;)�� �ƴϸ�, �Ĳ��ϰ� ���� �����ϰ� Ǯ �� �־���. ���ǵ� �ʹ� �ܼ��ؼ� �ݷʸ� �������� �ʾƵ� �ƾ���
{
	fastio;

	Input();

	BFS();

	cout << Ans << '\n';
}