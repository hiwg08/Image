#include <bits/stdc++.h>

using namespace std;

vector<int> Info, Ans;

int MAX = INT_MIN;

bool Lower_Score(vector<int> Apache)
{
    for (int i = 10; i >= 0; i--)
    {
        if (Apache[i] > Ans[i])
            return true;
        else if (Apache[i] < Ans[i])
            return false;
    }
}

void CHK(vector<int> Apache)
{
    int Ryan_Score = 0, Apache_Score = 0;

    for (int i = 0; i < 11; i++)
    {
        if (Info[i] < Apache[i])
            Apache_Score += (10 - i);
        else if (Info[i] > Apache[i])
            Ryan_Score += (10 - i);
    }

    if (Apache_Score - Ryan_Score > 0)
    {
        if (MAX < (Apache_Score - Ryan_Score))
        {
            MAX = (Apache_Score - Ryan_Score);
            Ans = Apache;
        }
        else if (MAX == (Apache_Score - Ryan_Score) && Lower_Score(Apache))
            Ans = Apache;
    }
}

void Solve(int Idx, int n, vector<int> Apache) // 전형적인 완탐 문제이다. 재귀의 탈출 조건을 최대한 깔끔하게 짜는 방법을 생각해보자... 아직 많이 부족한 것 같다...
{
    if (Idx == 11 || n == 0)
    {
        Apache[Idx - 1] += n;
        CHK(Apache);
        Apache[Idx - 1] -= n;
        return;
    }

    if (n - (Info[Idx] + 1) >= 0)
    {
        n -= (Info[Idx] + 1);
        Apache[Idx] = Info[Idx] + 1;
        Solve(Idx + 1, n, Apache);
        Apache[Idx] = 0;
        n += (Info[Idx] + 1);
    }

    Solve(Idx + 1, n, Apache);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> Apache(11, 0);

    Info = info;

    Solve(0, n, Apache);

    if (MAX == INT_MIN)
        return { -1 };
    return Ans;
}