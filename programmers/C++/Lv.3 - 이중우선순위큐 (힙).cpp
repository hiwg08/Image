#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator () (int a, int b)
    {
        return a > b;
    }
};

priority_queue<int> Max_Q;

priority_queue<int, vector<int>, cmp> Min_Q;


vector<int> solution(vector<string> operations) {
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        if (operations[i][0] == 'I')
        {
            Min_Q.push(stoi(operations[i].substr(2)));
            Max_Q.push(stoi(operations[i].substr(2)));
        }
        else if (operations[i][0] == 'D' && !Min_Q.empty() && !Max_Q.empty())
        {
            if (operations[i][2] == '-') // ÃÖ¼Ú°ª
            {
                Min_Q.pop();

                priority_queue<int> Max_Q_Copy;
                stack<int> Min_S;
                while (!Min_Q.empty())
                {
                    Min_S.push(Min_Q.top());
                    Max_Q_Copy.push(Min_Q.top());
                    Min_Q.pop();
                }
                Max_Q = Max_Q_Copy;
                while (!Min_S.empty())
                {
                    Min_Q.push(Min_S.top());
                    Min_S.pop();
                }
            }
            else // ÃÖ´ñ°ª
            {
                Max_Q.pop();

                priority_queue<int, vector<int>, cmp> Min_Q_Copy;
                stack<int> Max_S;
                while (!Max_Q.empty())
                {
                    Max_S.push(Max_Q.top());
                    Min_Q_Copy.push(Max_Q.top());
                    Max_Q.pop();
                }
                Min_Q = Min_Q_Copy;
                while (!Max_S.empty())
                {
                    Max_Q.push(Max_S.top());
                    Max_S.pop();
                }
            }
        }
    }

    if (Max_Q.empty())
        return { 0, 0 };
    return { Max_Q.top(), Min_Q.top() };
}