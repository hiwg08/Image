#include <bits/stdc++.h>

using namespace std;

char Map[5][5]{ 0 };

bool Vis[5][5]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

class BFS_Info
{
public:
    int x, y, distance;
    BFS_Info(int _x, int _y, int _distance)
        :x(_x), y(_y), distance(_distance)
    {}
};

bool Solution(int x, int y)
{
    queue<BFS_Info> Q;
    Q.push(BFS_Info(x, y, 0));
    Vis[x][y] = true;

    while (!Q.empty())
    {
        BFS_Info st1 = Q.front();
        Q.pop();

        if (Map[st1.x][st1.y] == 'P' && st1.distance >= 1)
            return false;
        if (st1.distance >= 2)
            continue;

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = st1.x + dx[dir];
            int ny = st1.y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
                continue;
            if (Vis[nx][ny])
                continue;
            if (Map[nx][ny] == 'X')
                continue;

            Vis[nx][ny] = true;
            Q.push(BFS_Info(nx, ny, st1.distance + 1));
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) { // 매우 전형적인 BFS 문제다
    vector<int> answer;

    for (int i = 0; i < places.size(); i++)
    {
        bool CHK = true;
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                Map[j][k] = places[i][j][k];
            }
        }
        for (int j = 0; j < places[i].size(); j++)
        {
            for (int k = 0; k < places[i][j].size(); k++)
            {
                if (Map[j][k] == 'P')
                {
                    memset(Vis, false, sizeof(Vis));
                    if (!Solution(j, k))
                    {
                        CHK = false;
                        break;
                    }
                }
            }
            if (!CHK)
                break;
        }
        if (CHK)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    return answer;
}