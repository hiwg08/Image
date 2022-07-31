#include <bits/stdc++.h>

using namespace std;

// 전형적인 DP 문제다.

int DP[100001][4]{ 0 };

int solution(vector<vector<int>> land)
{
    int answer = -1;

    DP[0][0] = land[0][0];
    DP[0][1] = land[0][1];
    DP[0][2] = land[0][2];
    DP[0][3] = land[0][3];

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < land[i].size(); j++)
        {
            int MAX = -1;
            for (int k = 0; k < land[i].size(); k++)
            {
                if (k != j)
                    MAX = max(MAX, DP[i - 1][k]);
            }
            DP[i][j] = land[i][j] + MAX;
        }
    }

    for (int i = 0; i < land[0].size(); i++)
        answer = max(answer, DP[land.size() - 1][i]);

    return answer;
}