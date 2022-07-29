#include <bits/stdc++.h>

using namespace std;

stack<int> Q, Q_Index;

int Ans[100001]{ 0 };

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!Q.empty() && Q.top() > prices[i])
        {
            Ans[Q_Index.top()] = i - Q_Index.top();
            Q_Index.pop();
            Q.pop();
        }
        Q_Index.push(i);
        Q.push(prices[i]);
        Ans[i] = prices.size() - i - 1;
    }

    for (int i = 0; i < prices.size(); i++)
        answer.push_back(Ans[i]);

    return answer;
}