#include <bits/stdc++.h>

using namespace std;

int N, M;

char Map[31][31]{ 0 };

bool Vis[31][31]{ 0 };

// 블록이 반드시 2 x 2 형태여만 부서지기 때문에 DFS 및 BFS를 사용할 필요가 없어서 쉽다.
// 따라서 단순 구현문제

int solution(int m, int n, vector<string> board) {
    int Result = 0;

    N = m;
    M = n;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].length(); j++)
            Map[i][j] = board[i][j];
    }

    while (1)
    {
        bool CHK = false;
        memset(Vis, false, sizeof(Vis));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if ((Map[i][j] == Map[i + 1][j]) && (Map[i][j + 1] == Map[i + 1][j + 1]) && (Map[i][j] == Map[i][j + 1]) && Map[i][j] != ' ')
                {
                    CHK = true;
                    Vis[i][j] = true;
                    Vis[i + 1][j] = true;
                    Vis[i][j + 1] = true;
                    Vis[i + 1][j + 1] = true;
                }
            }
        }
        if (!CHK)
            break;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (Vis[i][j])
                {
                    Result++;
                    Map[i][j] = ' ';
                }
            }
        }

        for (int i = 0; i < M; i++)
        {
            int CNT = 0;
            for (int j = N - 1; j >= 0; j--)
            {
                if (Map[j][i] == ' ')
                    CNT++;
                else
                {
                    while (CNT != 0)
                    {
                        Map[j + 1][i] = Map[j][i];
                        Map[j][i] = ' ';
                        j++;
                        CNT--;
                    }
                }
            }
        }
    }

    return Result;
}