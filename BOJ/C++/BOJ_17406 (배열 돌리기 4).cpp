#include <bits/stdc++.h>

using namespace std;

int N, M, K, R, Result = INT_MAX;

int Origin_Map[51][51]{ 0 }, Mid_Map[51][51]{ 0 }, Vis[7]{ 0 }, Arr[7]{ 0 }, Copy_Map[51][51]{ 0 };

class Rotate_Info
{
public:
	int a, b, c, d;
	Rotate_Info(int _a, int _b, int _c, int _d)
		:a(_a), b(_b), c(_c), d(_d)
	{}
};

vector<vector<Rotate_Info>> Rotate;

void Origin_Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			Mid_Map[i][j] = Origin_Map[i][j];
			Copy_Map[i][j] = Origin_Map[i][j];
		}
	}
}

void Rotate_Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			Mid_Map[i][j] = Copy_Map[i][j];
	}
}

void Solve(vector<Rotate_Info> B)
{
	for (int i = 0; i < B.size(); i++)
	{
		int start_x = B[i].a - 1, start_y = B[i].b - 1, end_x = B[i].c - 1, end_y = B[i].d - 1;

		for (int j = start_y; j < end_y; j++)
			Copy_Map[start_x][j + 1] = Mid_Map[start_x][j];
		for (int j = start_x; j < end_x; j++)
			Copy_Map[j + 1][end_y] = Mid_Map[j][end_y];
		for (int j = start_y; j < end_y; j++)
			Copy_Map[end_x][j] = Mid_Map[end_x][j + 1];
		for (int j = start_x; j < end_x; j++)
			Copy_Map[j][start_y] = Mid_Map[j + 1][start_y];

		Rotate_Init();
	}
}

void Calc_Row()
{
	for (int i = 0; i < N; i++)
	{
		int Ans = 0;
		for (int j = 0; j < M; j++)
			Ans += Mid_Map[i][j];

		Result = min(Result, Ans);
	}
}

void Permutation(int Idx)
{
	if (Idx == R)
	{
		Origin_Init();

		for (int i = 0; i < Idx; i++)
			Solve(Rotate[Arr[i]]);

		Calc_Row();

		return;
	}

	for (int i = 0; i < R; i++)
	{
		if (!Vis[i])
		{
			Vis[i] = true;
			Arr[Idx] = i;
			Permutation(Idx + 1);
			Vis[i] = false;
		}
	}
}

int main()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> Origin_Map[i][j];
	}

	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<Rotate_Info> temp;
		for (int j = 1; j <= c; j++)
			temp.push_back(Rotate_Info(a - j, b - j, a + j, b + j));
		Rotate.push_back(temp);
	}

	R = Rotate.size();

	Permutation(0);

	cout << Result << '\n';
}