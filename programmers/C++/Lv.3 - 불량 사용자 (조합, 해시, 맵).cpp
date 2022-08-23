#include <bits/stdc++.h>

using namespace std;

int N, R;

int Arr[9]{ 0 };
bool Vis[9]{ 0 };

vector<string> USER, BAN;

map<vector<string>, bool> MAP;

int Result = 0;

void DFS(int Idx)
{
    if (Idx == R)
    {
        int CNT = 0;
        vector<string> CHK_ID;

        for (int i = 0; i < Idx; i++)
        {
            if (USER[Arr[i]].size() != BAN[i].size())
                break;

            CHK_ID.push_back(USER[Arr[i]]);

            int j = 0;
            for (j = 0; j < USER[Arr[i]].size(); j++)
            {
                if (USER[Arr[i]][j] == BAN[i][j])
                    continue;
                if (BAN[i][j] == '*')
                    continue;
                break;
            }

            if (j == USER[Arr[i]].size())
                CNT++;
        }

        sort(CHK_ID.begin(), CHK_ID.end());

        if (CNT == BAN.size() && !MAP[CHK_ID])
        {
            MAP[CHK_ID] = true;
            Result++;
        }

        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!Vis[i])
        {
            Vis[i] = true;
            Arr[Idx] = i;
            DFS(Idx + 1);
            Vis[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {

    N = user_id.size();
    R = banned_id.size();

    USER = user_id;
    BAN = banned_id;

    DFS(0);

    return Result;
}