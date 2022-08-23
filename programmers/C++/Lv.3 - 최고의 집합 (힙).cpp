#include <bits/stdc++.h>

using namespace std;

priority_queue<int> Q;

vector<int> solution(int n, int s) { // 동일 레벨의 "야근 지수" 문제와 완전히 동일한 문제.
    vector<int> answer;

    if (n > s)
    {
        answer.push_back(-1);
        return answer;
    }

    int SUM = 0;

    int temp = s / n;
    if (s % n != 0)
        temp++;

    for (int i = 0; i < n; i++)
    {
        Q.push(temp);
        SUM += temp;
    }

    while (SUM != s)
    {
        int temp1 = Q.top();
        Q.pop();
        temp1--;
        SUM--;
        Q.push(temp1);
    }

    while (!Q.empty())
    {
        answer.push_back(Q.top());
        Q.pop();
    }

    sort(answer.begin(), answer.end());

    return answer;
}