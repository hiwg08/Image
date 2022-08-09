#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, vector<pair<int, int>>> ALL_PLAY;
unordered_map<string, int> TOTAL_PLAY;
vector<pair<string, int>> TEMP;

bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

bool cmp2(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) { // 레벨 3 난이도는 절----대 아니다. 암튼 그렇다.
    vector<int> answer;

    for (int i = 0; i < genres.size(); i++)
    {
        ALL_PLAY[genres[i]].push_back({ i, plays[i] });
        TOTAL_PLAY[genres[i]] += plays[i];
    }

    for (auto it = ALL_PLAY.begin(); it != ALL_PLAY.end(); it++)
        sort(it->second.begin(), it->second.end(), cmp1);

    for (auto it = TOTAL_PLAY.begin(); it != TOTAL_PLAY.end(); it++)
        TEMP.push_back({ it->first, it->second });

    sort(TEMP.begin(), TEMP.end(), cmp2);

    for (int i = 0; i < TEMP.size(); i++)
    {
        int CNT = 0;
        for (int j = 0; j < ALL_PLAY[TEMP[i].first].size(); j++)
        {
            answer.push_back(ALL_PLAY[TEMP[i].first][j].first);
            CNT++;
            if (CNT >= 2)
                break;
        }
    }

    return answer;
}