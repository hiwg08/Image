#include <bits/stdc++.h>

using namespace std;

int N;

vector<int> TIME;

long long Return_Ans()
{
    long long lo = 0, hi = (long long)TIME[TIME.size() - 1] * (long long)N + 1, mid = 0;

    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;

        long long CNT = 0;

        for (int i = 0; i < TIME.size(); i++)
            CNT += (mid / TIME[i]);

        if (CNT < N) // check(lo) == check(mid)
            lo = mid;
        else
            hi = mid;
    }

    return hi;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    N = n;
    TIME = times;

    return Return_Ans();
}