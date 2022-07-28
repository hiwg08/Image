#include <bits/stdc++.h>

using namespace std;

int Map[101][101]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool Vis[101][101]{ 0 };

queue<pair<pair<int, int>, int>> Q;

int N, M, Ans = -1;

void BFS(int x, int y, int Time) // 최단거리 문제는 무조건 BFS라고 생각하면 된다. 헷갈리는 개념이므로 잘 알아두자.
{
    Vis[x][y] = true;
    Q.push({ {x, y}, 0 });

    while (!Q.empty())
    {
        pair<pair<int, int>, int> st1 = Q.front();
        Q.pop();
        if (st1.first.first == N - 1 && st1.first.second == M - 1)
        {
            Ans = st1.second + 1;
            return;
        }
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = st1.first.first + dx[dir];
            int ny = st1.first.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (Vis[nx][ny])
                continue;
            if (Map[nx][ny] != 1)
                continue;
            Vis[nx][ny] = true;
            Q.push({ {nx, ny}, st1.second + 1 });
        }
    }
}

int solution(vector<vector<int>> maps)
{
    N = maps.size();
    M = maps[0].size();

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
            Map[i][j] = maps[i][j];
    }

    BFS(0, 0, 0);

    return Ans;
}