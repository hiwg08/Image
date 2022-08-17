#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;

    sort(d.begin(), d.end());

    for (auto e : d)
    {
        budget -= e;
        if (budget <= -1)
            break;
        answer++;
    }

    return answer;
}