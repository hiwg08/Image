#include <bits/stdc++.h>

using namespace std;

long long DP[2001]{ 0 };

void Solve()
{
    DP[1] = 1;
    DP[2] = 2;

    for (int i = 3; i <= 2000; i++)
        DP[i] = (DP[i - 2] + DP[i - 1]) % 1234567;
}

long long solution(int n) { // �ſ� ���� DP ���� (�Ǻ���ġ)

    Solve();

    return DP[n];
}