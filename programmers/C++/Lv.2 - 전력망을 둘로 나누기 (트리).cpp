#include <bits/stdc++.h>

using namespace std;

// ����μ��� ��Ʈ ��带 ã�� ����� ����.

bool Vis[101]{ 0 };

int Child_Num[101]{ 0 };

int Root;

int CNT;

int MIN = 987654321;

vector<vector<int>> Trees;

int DFS(int Idx) // Ʈ���� ��ȸ�ϸ鼭 ���� ���(Idx)�� �ڽ� ���� + 1�� ��������.  
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


int solution(int n, vector<vector<int>> wires) { // ���Ʈ���� �� ��

    CNT = n;

    Trees.resize(n + 1);

    for (int i = 0; i < wires.size(); i++)
    {
        Trees[wires[i][0]].push_back(wires[i][1]);
        Trees[wires[i][1]].push_back(wires[i][0]);
    } // ���� Ʈ���� �ܹ����̾ �̷��� �ϸ� �ȵ�����, ������ �Է��� 
      // ����� �����̾ Ʈ���� �θ� ��带 �� ����� ���� �׷����� �����Ѵ�.

    for (int i = 1; i <= n; i++)
    {
        if (Trees[i].size() == 1)
        {
            Root = i;
            break;
        } // Ʈ���� �θ� ���(Root) ���ϱ�.
    }

    Child_Num[Root] = DFS(Root);

    for (int i = 2; i <= n; i++)
        MIN = min(MIN, abs(n - 2 * Child_Num[i]));

    return MIN;
}