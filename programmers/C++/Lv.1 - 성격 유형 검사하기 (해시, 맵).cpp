#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<char, int> MBTI;

char KIND[]{ 'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N' };

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    for (int i = 0; i < choices.size(); i++)
    {
        if (choices[i] - 4 < 0)
            MBTI[survey[i][0]] += (4 - choices[i]);

        else if (choices[i] - 4 > 0)
            MBTI[survey[i][1]] += (choices[i] - 4);
    }

    for (int i = 0; i < 8; i += 2)
        MBTI[KIND[i]] >= MBTI[KIND[i + 1]] ? answer += KIND[i] : answer += KIND[i + 1];


    return answer;
}