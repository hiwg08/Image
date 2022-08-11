#include <bits/stdc++.h>

using namespace std;

map<string, int> CHK_MARATHON;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    for (auto e : completion)
        CHK_MARATHON[e]++;

    for (auto e : participant)
    {
        if (CHK_MARATHON[e])
            CHK_MARATHON[e]--;
        else
        {
            answer = e;
            break;
        }
    }
    return answer;
}