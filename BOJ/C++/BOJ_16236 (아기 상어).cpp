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
// 본인보다 크기가 큰 물고기 칸은 지나갈 수 없음
// 본인이랑 크기가 같으면 지나갈 수는 있는데, 먹을 수는 없음
{
	while (true)
	{
		queue<pair<pair<int, int>, int>> Q; // 맨 마지막 인수는 거리

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
				// 이 부분을 조심했어야 했다.... IDE 없이 풀고 싶었는데, 아직은 그 정도의 실력은 아닌것 같다.
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

int main() // 골드 3은 너무 높고, 골드 4~5가 적절함
		   // 나머지는 단순 구현. 내가 놓쳤던 부분 (별표 막 친 부분 ㅋㅋㅋ;;)만 아니면, 꼼꼼하게 보고 무난하게 풀 수 있었음. 조건도 너무 단순해서 반례를 생각하지 않아도 됐었음
{
	fastio;

	Input();

	BFS();

	cout << Ans << '\n';
}