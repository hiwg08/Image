#include <bits/stdc++.h>

using namespace std;

int DP_1[100001][2]{ 0 };

int DP_2[100001][2]{ 0 };

int solution(vector<int> sticker)
{
    int N = sticker.size();

    DP_1[0][0] = 0;
    DP_1[0][1] = sticker[0];

    DP_2[1][0] = 0;
    DP_2[1][1] = sticker[1];

    for (int i = 1; i < N; i++)
    {
        DP_1[i][1] = sticker[i] + DP_1[i - 1][0];
        DP_1[i][0] = max(DP_1[i - 1][0], DP_1[i - 1][1]);
        if (i == 1)
            continue;
        DP_2[i][1] = sticker[i] + DP_2[i - 1][0];
        DP_2[i][0] = max(DP_2[i - 1][0], DP_2[i - 1][1]);
    }

    if (N == 1)
        return sticker[0];
    return max(DP_2[N - 1][1], DP_1[N - 1][0]);
}