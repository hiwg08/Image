#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0, interval = w * 2 + 1, Idx = 1;

    stations.push_back(n + w + 1);

    for (int i = 0; i < stations.size(); i++)
    {
        if (stations[i] - w - Idx >= 0)
        {
            if ((stations[i] - w - Idx) % interval != 0)
                answer += (stations[i] - w - Idx) / interval + 1;
            else
                answer += (stations[i] - w - Idx) / interval;
        }
        Idx = stations[i] + w + 1;
    }

    return answer;
}