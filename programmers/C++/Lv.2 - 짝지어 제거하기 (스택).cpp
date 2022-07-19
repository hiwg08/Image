#include <bits/stdc++.h>

using namespace std;

stack<char> Q;

int Ans = 0;

void CHK_Remove(string s) // 너무 간단한 스택 문제
{
    for (int i = 0; i < s.length(); i++)
    {
        if (Q.empty())
            Q.push(s[i]);
        else
        {
            if (Q.top() != s[i])
                Q.push(s[i]);
            else
                Q.pop();
        }
    }
}

int solution(string s)
{
    CHK_Remove(s);

    if (Q.empty())
        Ans = 1;

    return Ans;
}