#include <string>
#include <vector>

using namespace std;

// 그래프를 이용한 분리 집합

vector<vector<int>> Graphs;

bool Vis[201]{ 0 };

int Result;

void DFS(int Idx)
{
    Vis[Idx] = true;
    for (int i = 0; i < Graphs[Idx].size(); i++)
    {
        if (!Vis[Graphs[Idx][i]])
            DFS(Graphs[Idx][i]);
    }
}

int solution(int n, vector<vector<int>> computers) { // 너무나도 쉬운 분리집합 문제 (현재는 DFS로 해결)

    Graphs.resize(n + 1);

    for (int i = 0; i < computers.size(); i++)
    {
        for (int j = 0; j < computers[i].size(); j++)
        {
            if (i != j && computers[i][j] == 1)
            {
                Graphs[i + 1].push_back(j + 1);
                Graphs[j + 1].push_back(i + 1);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (!Vis[i])
        {
            DFS(i);
            Result++;
        }
    }

    return Result;
}