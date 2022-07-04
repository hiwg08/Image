#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<pair<int, int>, pair<int, int>>> BFS_queue;

int N, I1;

int Map[16][16]{ 0 };

int DP[16][16]{ 0 };

int result = 0;

void BFS()
{
	while (!BFS_queue.empty()) // BFS 시작
	{
		pair<pair<int, int>, pair<int, int>> st1 = BFS_queue.front();
		BFS_queue.pop();
		if (st1.second.first == N - 1 && st1.second.second == N - 1)
		{
			result++;
			continue;
		}
		if (st1.first.first == st1.second.first && st1.second.second - st1.first.second == 1) // 가로일 때
		{
			if (st1.second.second + 1 < N && Map[st1.second.first][st1.second.second + 1] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first, st1.second.second + 1} });
			if (st1.second.first + 1 < N && st1.second.second + 1 < N && Map[st1.second.first + 1][st1.second.second + 1] != 1 && Map[st1.second.first][st1.second.second + 1] != 1 && Map[st1.second.first + 1][st1.second.second] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first + 1, st1.second.second + 1} });
		}
		else if (st1.first.second == st1.second.second && st1.second.first - st1.first.first == 1) // 세로일 때
		{
			if (st1.second.first + 1 < N && Map[st1.second.first + 1][st1.second.second] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first + 1, st1.second.second} });
			if (st1.second.first + 1 < N && st1.second.second + 1 < N && Map[st1.second.first + 1][st1.second.second + 1] != 1 && Map[st1.second.first][st1.second.second + 1] != 1 && Map[st1.second.first + 1][st1.second.second] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first + 1, st1.second.second + 1} });
		}
		else if (st1.second.first - st1.first.first == 1 && st1.second.second - st1.first.second == 1)
		{
			if (st1.second.second + 1 < N && Map[st1.second.first][st1.second.second + 1] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first, st1.second.second + 1} });
			if (st1.second.first + 1 < N && Map[st1.second.first + 1][st1.second.second] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first + 1, st1.second.second} });
			if (st1.second.first + 1 < N && st1.second.second + 1 < N && Map[st1.second.first + 1][st1.second.second + 1] != 1 && Map[st1.second.first][st1.second.second + 1] != 1 && Map[st1.second.first + 1][st1.second.second] != 1)
				BFS_queue.push({ {st1.second.first, st1.second.second}, {st1.second.first + 1, st1.second.second + 1} });
		}
	}
}

int main()
{
	BFS_queue.push({ {0,0}, {0,1} });
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> I1;
			Map[i][j] = I1;
		}
	}

	BFS();

	cout << result << '\n';
}

//#include <iostream> // 단언컨데, BFS보다 DP가 훨씬 좋은 풀이법인 것 같다.
//
//using namespace std;
//
//int m[18][18], d[18][18][3];
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//			cin >> m[i][j];
//	}
//	d[1][2][0] = 1;
//	d[1][2][1] = 0;
//	d[1][2][2] = 0;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (i == 1 && j <= 2)
//				continue;
//			if (m[i][j] == 1)
//				continue;
//
//			if (m[i][j - 1] == 1)
//				d[i][j][0] = 0;
//			else
//				d[i][j][0] = d[i][j - 1][0] + d[i][j - 1][2];
//
//			if (m[i - 1][j] == 1)
//				d[i][j][1] = 0;
//			else
//				d[i][j][1] = d[i - 1][j][1] + d[i - 1][j][2];
//
//			if (m[i - 1][j] == 1 || m[i][j - 1] == 1)
//				d[i][j][2] = 0;
//			else
//				d[i][j][2] = d[i - 1][j - 1][0] + d[i - 1][j - 1][1] + d[i - 1][j - 1][2];
//		}
//	}
//	cout << d[n][n][0] + d[n][n][1] + d[n][n][2] << '\n';
//} 