#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator () (int a, int b)
    {
        return a > b;
    }
};

priority_queue<int, vector<int>, cmp> PQ;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (auto e : scoville)
        PQ.push(e);

    while (PQ.size() > 1 && PQ.top() < K)
    {
        int temp1 = PQ.top();
        PQ.pop();
        int temp2 = PQ.top();
        PQ.pop();
        PQ.push(temp1 + 2 * temp2);
        answer++;
    }

    if (PQ.top() >= K)
        return answer;
    else
        return -1;
}