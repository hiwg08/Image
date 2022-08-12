#include <bits/stdc++.h>

using namespace std;

stack<int> S;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!S.empty() && S.top() == arr[i])
            S.pop();

        S.push(arr[i]);
    }

    while (!S.empty())
    {
        answer.push_back(S.top());
        S.pop();
    }

    reverse(answer.begin(), answer.end());

    return answer;
}