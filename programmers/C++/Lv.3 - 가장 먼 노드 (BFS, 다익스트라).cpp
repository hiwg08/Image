#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graphs;

queue<pair<int, int>> Q;

int MAX = -987654321;

vector<int> Ans;

bool Vis[20001]{ 0 };

void BFS(int start)
{
    Q.push({ start, 0 });
    Vis[start] = true;
    while (!Q.empty())
    {
        pair<int, int> st1 = Q.front();
        Q.pop();

        if (MAX < st1.second)
        {
            MAX = st1.second;
            Ans.clear();
            vector<int>().swap(Ans);
            Ans.push_back(st1.first);
        }
        else if (MAX == st1.second)
            Ans.push_back(st1.first);

        for (int i = 0; i < graphs[st1.first].size(); i++)
        {
            if (Vis[graphs[st1.first][i]])
                continue;
            Vis[graphs[st1.first][i]] = true;
            Q.push({ graphs[st1.first][i], st1.second + 1 });
        }
    }
}
int solution(int n, vector<vector<int>> edge) { // ��� ������ ���̰� 1�̱� ������ ���ͽ�Ʈ�� �� �ʿ䰡 ����. �ִ� �Ÿ� == BFS ���� �˸� BFS�� ����� Ǯ �� �ִ� ����

    graphs.resize(edge.size() + 1);

    for (int i = 0; i < edge.size(); i++)
    {
        graphs[edge[i][0]].push_back(edge[i][1]);
        graphs[edge[i][1]].push_back(edge[i][0]);
    }

    BFS(1);

    return Ans.size();
}