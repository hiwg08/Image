#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> Route;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int solution(vector<vector<int>> routes) {
    int answer = 1;

    for (int i = 0; i < routes.size(); i++)
        Route.push_back({ routes[i][0], routes[i][1] });

    sort(Route.begin(), Route.end(), cmp);

    int a_second = Route[0].second;

    for (int i = 1; i < Route.size(); i++)
    {
        if (Route[i].first > a_second)
        {
            answer++;
            a_second = Route[i].second;
        }
        else if (Route[i].second < a_second)
            a_second = Route[i].second;
    }

    return answer;
}