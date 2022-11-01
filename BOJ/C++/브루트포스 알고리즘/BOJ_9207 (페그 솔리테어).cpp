#include <bits/stdc++.h>

using namespace std;

int T, MIN = INT_MAX, Ans = 0;

char Block[9][9]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

void Peg_Solitear(int Cnt)
{
	int Hole_Cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (Block[i][j] != 'o')
				continue;

			Hole_Cnt++;

			for (int dir = 0; dir < 4; dir++)
			{
				int nx = i + dx[dir], ny = j + dy[dir];
				if (nx < 0 || ny < 0 || nx >= 5 || ny >= 9 ||
					nx + dx[dir] < 0 || ny + dy[dir] < 0 || nx + dx[dir] >= 5 || ny + dy[dir] >= 9)
					continue;
				if (Block[nx][ny] == 'o' && Block[nx + dx[dir]][ny + dy[dir]] == '.')
				{
					Block[nx][ny] = '.';
					Block[nx + dx[dir]][ny + dy[dir]] = 'o';
					Block[i][j] = '.';
					Peg_Solitear(Cnt + 1);
					Block[nx][ny] = 'o';
					Block[nx + dx[dir]][ny + dy[dir]] = '.';
					Block[i][j] = 'o';
				}
			}
		}
	}

	if (MIN > Hole_Cnt)
	{
		MIN = Hole_Cnt;
		Ans = Cnt;
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		MIN = INT_MAX, Ans = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 9; j++)
				cin >> Block[i][j];
		}

		Peg_Solitear(0);

		cout << MIN << " " << Ans << '\n';
	}
}