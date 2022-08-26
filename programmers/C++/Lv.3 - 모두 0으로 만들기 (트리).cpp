#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> Graphs;

long long CHK_T[300001]{ 0 };

bool Vis[300001]{ 0 };

long long Root, Zero_Cnt, Ans;

long long DFS(long long Idx, vector<int>& a)
{
    Vis[Idx] = true;
    long long temp = a[Idx];

    for (int i = 0; i < Graphs[Idx].size(); i++)
    {
        if (!Vis[Graphs[Idx][i]])
            temp += DFS(Graphs[Idx][i], a);

    }
    Ans += abs(temp);
    return temp;
}

long long solution(vector<int> a, vector<vector<int>> edges) {

    Graphs.resize(a.size() + 1);

    for (int i = 0; i < edges.size(); i++)
    {
        Graphs[edges[i][0]].push_back(edges[i][1]);
        Graphs[edges[i][1]].push_back(edges[i][0]);
        CHK_T[edges[i][0]]++;
        CHK_T[edges[i][1]]++;
    }

    for (int i = 0; i < a.size(); i++)
    {
        if (CHK_T[i] == 1)
        {
            Root = i;
            break;
        }
    }

    if (DFS(Root, a) != 0)
        return -1;
    return Ans;
}