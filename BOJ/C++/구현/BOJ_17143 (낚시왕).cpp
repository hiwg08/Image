#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int R, C, M, Ans;

class Shark_Info
{
public:
	int Speed, Dir, Huge;
	Shark_Info(int _Speed, int _Dir, int _Huge)
		:Speed(_Speed), Dir(_Dir), Huge(_Huge)
	{}
};

map<pair<int, int>, vector<Shark_Info>> Info;

map<int, int> Change_Dir;

int dx[]{ -1, 1, 0, 0 };
int dy[]{ 0, 0, 1, -1 };

bool cmp(Shark_Info a, Shark_Info b)
{
	return a.Huge > b.Huge;
}

int main()
{
	fastio;

	cin >> R >> C >> M;

	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;

		Info[{r - 1, c - 1}].push_back(Shark_Info(s, d - 1, z));
	}

	Change_Dir[0] = 1;
	Change_Dir[1] = 0;
	Change_Dir[2] = 3;
	Change_Dir[3] = 2;

	for (int i = 0; i < C; i++)
	{
		map<pair<int, int>, vector<Shark_Info>> Info_Copy, Info_Second;

		for (int j = 0; j < R; j++)
		{
			if (Info[{j, i}].size() != 0)
			{
				Ans += Info[{j, i}][0].Huge;
				Info[{j, i}].pop_back();
				break;
			}
		}

		for (auto it = Info.begin(); it != Info.end(); it++)
		{
			if (it->second.size() == 0)
				continue;

			int P_R = it->first.first;
			int P_C = it->first.second;
			int P_Dir = it->second[0].Dir;
			int P_Speed = it->second[0].Speed;
			int P_Huge = it->second[0].Huge;

			int CHK = 0;

			if (P_Dir == 0) // 위
			{
				CHK = P_R + 1;

				if (R == 1)
				{
					if (P_Speed % 2 != 0)
						P_Dir = Change_Dir[P_Dir];
					continue;
				}

				if (P_Speed < CHK)
					P_R += dx[P_Dir] * P_Speed;

				else
				{
					if (((P_Speed - CHK) / (R - 1)) % 2 == 0) // 역순
					{
						P_R = ((P_Speed - CHK) % (R - 1)) + 1;
						P_Dir = Change_Dir[P_Dir];
					}

					else // 본래 순서
						P_R = R - 2 - ((P_Speed - CHK) % (R - 1));
				}
			}

			else if (P_Dir == 1) // 아래
			{
				CHK = R - P_R;

				if (R == 1)
				{
					if (P_Speed % 2 != 0)
						P_Dir = Change_Dir[P_Dir];
					continue;
				}

				if (P_Speed < CHK)
					P_R += dx[P_Dir] * P_Speed;

				else
				{
					if (((P_Speed - CHK) / (R - 1)) % 2 == 0) // 역순
					{
						P_R = R - 2 - ((P_Speed - CHK) % (R - 1));
						P_Dir = Change_Dir[P_Dir];
					}

					else // 본래 순서
						P_R = ((P_Speed - CHK) % (R - 1)) + 1;

				}
			}

			else if (P_Dir == 2) // 오른
			{
				CHK = C - P_C;

				if (C == 1) // 얘는 방향만 변환
				{
					if (P_Speed % 2 != 0)
						P_Dir = Change_Dir[P_Dir];
					continue;
				}

				if (P_Speed < CHK)
					P_C += dy[P_Dir] * P_Speed;

				else
				{
					if (((P_Speed - CHK) / (C - 1)) % 2 == 0) // 역순
					{
						P_C = C - 2 - ((P_Speed - CHK) % (C - 1));
						P_Dir = Change_Dir[P_Dir];
					}

					else // 본래 순서
						P_C = ((P_Speed - CHK) % (C - 1)) + 1;
				}
			}

			else if (P_Dir == 3) // 왼
			{
				CHK = P_C + 1;

				if (C == 1)
				{
					if (P_Speed % 2 != 0)
						P_Dir = Change_Dir[P_Dir];
					continue;
				}

				if (P_Speed < CHK)
					P_C += dy[P_Dir] * P_Speed;

				else
				{
					if (((P_Speed - CHK) / (C - 1)) % 2 == 0) // 역순
					{
						P_C = ((P_Speed - CHK) % (C - 1)) + 1;
						P_Dir = Change_Dir[P_Dir];
					}

					else // 본래 순서
						P_C = C - 2 - ((P_Speed - CHK) % (C - 1));
				}
			}
			Info_Copy[{P_R, P_C}].push_back(Shark_Info(P_Speed, P_Dir, P_Huge));
		}

		for (auto it = Info_Copy.begin(); it != Info_Copy.end(); it++)
		{
			sort(it->second.begin(), it->second.end(), cmp);
			Info_Second[{it->first.first, it->first.second}].push_back(it->second[0]);
		}

		Info = Info_Second;
	}

	cout << Ans << '\n';
}

// 구현이 너무 더럽다....