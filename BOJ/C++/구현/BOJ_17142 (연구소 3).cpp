#include <bits/stdc++.h>

using namespace std;

class Virus_Info
{
public:
	int x, y, dis;
	Virus_Info(int _x, int _y, int _dis)
		:x(_x), y(_y), dis(_dis)
	{}
};

int N, M, Ans = INT_MAX, Origin_Map[51][51]{ 0 }, Copy_Map[51][51]{ 0 }, Arr[11]{ 0 }, Vis_Combi[11]{ 0 }, Vis_Search[51][51]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int CHK_E = 0;

vector<Virus_Info> Virus;

void BFS(vector<Virus_Info> Active_Virus)
{
	queue<Virus_Info> Q;

	for (int i = 0; i < Active_Virus.size(); i++)
	{
		Q.push(Active_Virus[i]);
		Vis_Search[Active_Virus[i].x][Active_Virus[i].y] = true;
	}

	while (!Q.empty())
	{
		Virus_Info st1 = Q.front();
		Q.pop();

		Copy_Map[st1.x][st1.y] = st1.dis;

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = st1.x + dx[dir];
			int ny = st1.y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (Vis_Search[nx][ny])
				continue;
			if (Copy_Map[nx][ny] == -1)
				continue;
			Vis_Search[nx][ny] = true;
			Q.push(Virus_Info(nx, ny, st1.dis + 1));
		}
	}
}

void Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (Origin_Map[i][j] == 1)
				Copy_Map[i][j] = -1;
			else
				Copy_Map[i][j] = Origin_Map[i][j];
		}
	}
}

void Combination(int Idx, int U)
{
	if (Idx == M)
	{
		Init();
		memset(Vis_Search, false, sizeof(Vis_Search));

		vector<Virus_Info> Active_Virus, InActive_Virus;

		for (int i = 0; i < Idx; i++)
			Active_Virus.push_back(Virus_Info(Virus[Arr[i]].x, Virus[Arr[i]].y, 0));

		for (int i = 0; i < Virus.size(); i++)
		{
			bool CHK = false;
			for (int j = 0; j < Idx; j++)
			{
				if (Arr[j] == i)
				{
					CHK = true;
					break;
				}
			}
			if (!CHK)
				InActive_Virus.push_back(Virus_Info(Virus[i].x, Virus[i].y, 0));
		}

		BFS(Active_Virus);

		int Max_CNT = INT_MIN;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (Copy_Map[i][j] != -1)
				{
					if (!Vis_Search[i][j])
					{
						Max_CNT = -1;
						break;
					}
					bool CHK = false;
					for (int k = 0; k < InActive_Virus.size(); k++)
					{
						if (i == InActive_Virus[k].x && j == InActive_Virus[k].y)
						{
							CHK = true;
							break;
						}
					}
					if (CHK)
						Max_CNT = max(Max_CNT, 0);
					else
						Max_CNT = max(Max_CNT, Copy_Map[i][j]);
				}
			}
			if (Max_CNT == -1)
				break;
		}

		if (Max_CNT == -1)
		{
			if (CHK_E == 0)
				Ans = -1;
		}
		else
		{
			if (CHK_E == 0)
			{
				CHK_E++;
				Ans = Max_CNT;
			}
			else
				Ans = min(Ans, Max_CNT);
		}

		return;
	}

	for (int i = U; i < Virus.size(); i++)
	{
		if (!Vis_Combi[i])
		{
			Vis_Combi[i] = true;
			Arr[Idx] = i;
			Combination(Idx + 1, i + 1);
			Vis_Combi[i] = false;
		}
	}
}

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> Origin_Map[i][j];
			if (Origin_Map[i][j] == 2)
				Virus.push_back(Virus_Info(i, j, 0));
		}
	}
}

int main()
{
	Input();

	Combination(0, 0);

	cout << Ans << '\n';
}