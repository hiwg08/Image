#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<char, string> sharp_convert;

unordered_map<string, pair<int, string>> Music_Info;
vector<string> Music_Name;
vector<pair<int, string>> Ans;

bool cmp(pair<int, string> a, pair<int, string> b)
{
    return a.first > b.first;
}

void convert_sharp_f(string& Params)
{
    vector<string> code_partition;
    for (int j = 0; j < Params.size(); j++)
    {
        string temp = "";
        temp += Params[j];
        if ((Params[j] == 'C' || Params[j] == 'D' || Params[j] == 'F' || Params[j] == 'G' || Params[j] == 'A') && j != Params.size() - 1 && Params[j + 1] == '#')
        {
            temp = sharp_convert[Params[j]];
            j++;
        }
        code_partition.push_back(temp);
    }

    Params = "";
    for (auto e : code_partition)
        Params += e;
}

string solution(string m, vector<string> musicinfos) {

    sharp_convert['C'] = "V";
    sharp_convert['D'] = "W";
    sharp_convert['F'] = "X";
    sharp_convert['G'] = "Y";
    sharp_convert['A'] = "Z";

    for (int i = 0; i < musicinfos.size(); i++)
    {
        vector<string> info_partition;
        vector<string> code_partition;
        vector<int> first_time, last_time;
        int sub_time;
        string word;

        stringstream sstream1(musicinfos[i]);
        while (getline(sstream1, word, ','))
            info_partition.push_back(word);

        stringstream sstream2(info_partition[0]);
        while (getline(sstream2, word, ':'))
            first_time.push_back(stoi(word));

        stringstream sstream3(info_partition[1]);
        while (getline(sstream3, word, ':'))
            last_time.push_back(stoi(word));

        if (first_time[1] > last_time[1])
            sub_time = ((last_time[0] - first_time[0] - 1) * 60 + (60 - first_time[1] + last_time[1]));
        else
            sub_time = ((last_time[0] - first_time[0]) * 60 + (last_time[1] - first_time[1]));

        convert_sharp_f(info_partition[3]);

        int Index = 0;
        word = "";
        for (int j = 0; j < sub_time; j++)
            word += info_partition[3][j % info_partition[3].size()];

        Music_Info[info_partition[2]] = { sub_time, word };
    }

    convert_sharp_f(m);

    for (auto it = Music_Info.begin(); it != Music_Info.end(); it++)
    {
        if (it->second.second.find(m) != string::npos)
            Ans.push_back({ it->second.first, it->first });
    }

    reverse(Ans.begin(), Ans.end());

    if (Ans.size() == 0)
        return "(None)";

    stable_sort(Ans.begin(), Ans.end(), cmp);

    return Ans[0].second;
}