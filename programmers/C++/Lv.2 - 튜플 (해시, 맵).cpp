#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> Collect;

unordered_map<int, int> Tuple_Opinion;

vector<pair<int, int>> Ans;

int Arr[100001]{ 0 };

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;

    string temp = "";

    bool CHK = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' || s[i] == '}')
        {
            if (temp != "")
                Collect.push_back(temp);
            CHK = false;
            temp = "";
        }
        else if (s[i] >= '0' && s[i] <= '9')
            CHK = true;

        if (CHK)
            temp += s[i];
    }

    for (auto e : Collect)
    {
        stringstream ss(e);
        string word;
        while (getline(ss, word, ','))
            Tuple_Opinion[stoi(word)]++;
    }

    for (auto it = Tuple_Opinion.begin(); it != Tuple_Opinion.end(); it++)
        Ans.push_back({ it->first, it->second });

    sort(Ans.begin(), Ans.end(), cmp);

    for (auto e : Ans)
        answer.push_back(e.first);

    return answer;
}