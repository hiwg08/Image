#include <bits/stdc++.h>

using namespace std;

// 현재로서는 루트 노드를 찾을 방법이 없다.

bool Vis[101]{ 0 };

int Child_Num[101]{ 0 };

int Root;

int CNT;

int MIN = 987654321;

vector<vector<int>> Trees;

int DFS(int Idx) // 트리를 순회하면서 현재 노드(Idx)의 자식 개수 + 1을 구해주자.  
{
    Vis[Idx] = true;
    int SUM = 1;
    for (int i = 0; i < Trees[Idx].size(); i++)
    {
        if (!Vis[Trees[Idx][i]])
            SUM += DFS(Trees[Idx][i]);
    }
    return Child_Num[Idx] = SUM;
}


int solution(int n, vector<vector<int>> wires) { // 브루트포스 안 씀

    CNT = n;

    Trees.resize(n + 1);

    for (int i = 0; i < wires.size(); i++)
    {
        Trees[wires[i][0]].push_back(wires[i][1]);
        Trees[wires[i][1]].push_back(wires[i][0]);
    } // 본래 트리는 단방향이어서 이렇게 하면 안되지만, 문제의 입력이 
      // 양방향 간선이어서 트리의 부모 노드를 알 방법이 없어 그래프로 접근한다.

    for (int i = 1; i <= n; i++)
    {
        if (Trees[i].size() == 1)
        {
            Root = i;
            break;
        } // 트리의 부모 노드(Root) 구하기.
    }

    Child_Num[Root] = DFS(Root);

    for (int i = 2; i <= n; i++)
        MIN = min(MIN, abs(n - 2 * Child_Num[i]));

    return MIN;
}