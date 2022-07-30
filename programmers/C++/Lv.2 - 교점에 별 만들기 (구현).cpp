#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, bool> counting_star;

long long MAX_x = LLONG_MIN, MAX_y = LLONG_MIN, MIN_x = LLONG_MAX, MIN_y = LLONG_MAX;

void return_collision(vector<int> a, vector<int> b)
{
    long long common = (long long)((long long)a[0] * (long long)b[1]) - (long long)((long long)a[1] * (long long)b[0]);
    if (common == 0)
        return;

    long long x = (long long)((long long)a[1] * (long long)b[2]) - (long long)((long long)a[2] * (long long)b[1]);
    long long y = (long long)((long long)a[2] * (long long)b[0]) - (long long)((long long)a[0] * (long long)b[2]);

    if (x % common != 0 || y % common != 0)
        return;

    long long convert_x = x / common;
    long long convert_y = y / common;

    MAX_x = max(MAX_x, convert_x);
    MAX_y = max(MAX_y, convert_y);
    MIN_x = min(MIN_x, convert_x);
    MIN_y = min(MIN_y, convert_y);

    counting_star[{convert_x, convert_y}] = true;
}

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;

    for (int i = 0; i < line.size(); i++)
    {
        for (int j = i + 1; j < line.size(); j++)
            return_collision(line[i], line[j]);
    } // O(N^2)

    for (long long i = MAX_y; i >= MIN_y; i--)
    {
        string temp = "";
        for (long long j = MIN_x; j <= MAX_x; j++)
        {
            if (counting_star[{j, i}])
                temp += '*';
            else
                temp += '.';
        }
        answer.push_back(temp);
    }

    return answer;
}