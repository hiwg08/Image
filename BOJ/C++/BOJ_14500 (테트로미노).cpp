#include <bits/stdc++.h>

using namespace std;

int N, M, Map[501][501]{ 0 }, MAX = INT_MIN;

vector<pair<int, int>> Tetromino[19];

void Tetromino_Init()
{
	Tetromino[0] = { {0, 1}, {0, 2}, {0, 3} };
	Tetromino[1] = { {1, 0}, {2, 0}, {3, 0} }; // 짝대기

	Tetromino[2] = { {0, 1}, {1, 1}, {1, 0} }; // 정사각형

	Tetromino[3] = { {0, 1}, {0, 2}, {1, 1} };
	Tetromino[4] = { {0, 1}, {-1, 1}, {1, 1} };
	Tetromino[5] = { {0, 1}, {0, 2}, {-1, 1} };
	Tetromino[6] = { {-1, 0}, {1, 0}, {0, 1} }; // 중지

	Tetromino[7] = { {1, 0}, {1, 1}, {2, 1} };
	Tetromino[8] = { {0, 1}, {-1, 1}, {-1, 2} };
	Tetromino[9] = { {-1, 0}, {-1, 1}, {-2, 1} };
	Tetromino[10] = { {0, 1}, {1, 1}, {1, 2} }; // 지그재그

	Tetromino[11] = { {1, 0}, {2, 0}, {2, 1} };
	Tetromino[12] = { {-1, 0}, {-1, 1}, {-1, 2} };
	Tetromino[13] = { {0, 1}, {1, 1}, {2, 1} };
	Tetromino[14] = { {0, 1}, {0, 2}, {-1, 2} };
	Tetromino[15] = { {0, 1}, {-1, 1}, {-2, 1} };
	Tetromino[16] = { {1, 0}, {1, 1}, {1, 2} };
	Tetromino[17] = { {0, -1}, {1, -1}, {2, -1} };
	Tetromino[18] = { {0, 1}, {0, 2}, {1, 2} }; // 지팡이
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
	}

	Tetromino_Init();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 19; k++)
			{
				bool CHK = true;
				int Ans = Map[i][j];

				for (int u = 0; u < 3; u++)
				{
					if (i + Tetromino[k][u].first < 0 || i + Tetromino[k][u].first >= N || j + Tetromino[k][u].second < 0 || j + Tetromino[k][u].second >= M)
					{
						CHK = false;
						break;
					}
					Ans += Map[i + Tetromino[k][u].first][j + Tetromino[k][u].second];
				}

				if (CHK)
					MAX = max(MAX, Ans);
			}
		}
	}

	cout << MAX << '\n';
}