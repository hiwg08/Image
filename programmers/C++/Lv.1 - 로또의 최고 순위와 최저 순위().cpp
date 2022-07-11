#include <bits/stdc++.h>

using namespace std;

bool a[46]{ 0 };
bool b[46]{ 0 };

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    int zero_cnt = 0;

    int correct_cnt = 0;

    for (int i = 0; i < lottos.size(); i++)
    {
        a[win_nums[i]] = true;
        b[lottos[i]] = true;
    }

    for (int i = lottos.size() - 1; i >= 0; i--)
    {
        if (a[lottos[i]] && b[lottos[i]])
        {
            correct_cnt++;
            continue;
        }
        if (lottos[i] == 0)
            zero_cnt++;
    }

    int Max = 0, Min = 0;
    if (correct_cnt <= 1) Max = 6;
    else Max = 7 - correct_cnt;
    if (correct_cnt + zero_cnt <= 1) Min = 6;
    else Min = 7 - correct_cnt - zero_cnt;

    answer.push_back(Min);
    answer.push_back(Max);

    return answer;
}