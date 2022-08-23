#include <bits/stdc++.h>

using namespace std;

int DP[100001]{ 0 };

int solution(int n, vector<int> money) { // ���� 2293 (����) ������ ������ ���� ����
    int answer = 0;

    DP[0] = 1;

    for (int i = 0; i < money.size(); i++)
    {
        for (int j = money[i]; j <= n; j++)
            DP[j] += (DP[j - money[i]] % 1000000007);
    }

    return DP[n] % 1000000007;
}