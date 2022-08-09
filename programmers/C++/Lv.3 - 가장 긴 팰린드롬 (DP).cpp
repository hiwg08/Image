#include <bits/stdc++.h>

using namespace std;

int DP[2501][2501]{ 0 };

int MAX = 1;  // �ּ� �Ӹ���� ���̴� 1�̴�. (���ĺ� �ϳ�)

string S;

int Solve(int s, int e)
{
    if (s >= e)
        return 1;

    int& ret = DP[s][e];

    if (ret != -1)
        return ret;

    if (S[s] == S[e])
        return ret = Solve(s + 1, e - 1);

    return ret = 0;
}

int solution(string s) // ��մ� DP ����
{
    S = s;

    memset(DP, -1, sizeof(DP));

    for (int i = 0; i < S.size(); i++)
    {
        for (int j = i + 1; j < S.size(); j++)
        {
            DP[i][j] = Solve(i, j);

            if (DP[i][j] == 1)
                MAX = max(MAX, j - i + 1);
        }
    }

    return MAX;
}