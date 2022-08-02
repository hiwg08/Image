#include <bits/stdc++.h>

using namespace std;

int Ans = 0;

void Solve(int n, int r)
{
    if (n == r)
    {
        Ans++;
        return;
    }
    else if (n < r || r <= 0)
        return;

    Solve(n - r, r - 1);
}

int solution(int n) {

    for (int i = n; i >= 1; i--) // 자연수라 했기 때문에 0은 제외다.
        Solve(n, i);

    return Ans;
}