#include <bits/stdc++.h>

using namespace std;

long long DP[101][101]{ 0 };

int N, M;

int MAP[101][101]{ 0 };

long long Solve(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return 0;
    if (MAP[x][y] == -1)
        return 0;
    if (x == N - 1 && y == M - 1)
        return 1;

    long long& ret = DP[x][y];

    if (ret != -1)
        return ret;

    return ret = (Solve(x + 1, y) + Solve(x, y + 1)) % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) { // 백준 1520 (내리막길) 문제의 하위호환

    N = n;
    M = m;

    memset(DP, -1, sizeof(DP));

    for (int i = 0; i < puddles.size(); i++)
        MAP[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

    return Solve(0, 0);
}