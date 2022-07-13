#include <bits/stdc++.h>

using namespace std;

using PP = pair<int, int>;

bool Vis[101][101]{ 0 };

int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, 1, 0, -1 };

int M, N, CNT;
int MAX = -20000;

vector<vector<int>> Map;

// 전형적인 BFS 문제. 백준 2667 (단지번호붙이기, S1) 문제 복붙.
// 함수 안에 전역 변수를 초기화를 안 하면 ㄹㅇ 맞았는데 틀리는 거지같은 옛날 컴파일러 때문에 쓸데없는 시간을 잡아먹었다. 

void BFS(int x, int y)
{
    queue<PP> S;
    S.push({ x, y });
    Vis[x][y] = true;
    int WIDTH = 0;

    while (!S.empty())
    {
        PP st1 = S.front();
        S.pop();
        WIDTH++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = st1.first + dx[dir];
            int ny = st1.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;
            if (Vis[nx][ny])
                continue;
            if (Map[nx][ny] != Map[x][y])
                continue;

            Vis[nx][ny] = true;
            S.push({ nx, ny });
        }
    }
    MAX = max(MAX, WIDTH);
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    Map = picture;
    vector<int> answer;
    M = m;
    N = n;
    CNT = 0;
    MAX = -20000;

    memset(Vis, false, sizeof(Vis));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Vis[i][j] || picture[i][j] == 0)
                continue;
            CNT++;
            BFS(i, j);
        }
    }

    answer.push_back(CNT);
    answer.push_back(MAX);

    return answer;
}