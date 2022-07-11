#include <bits/stdc++.h>
// ��·�� �� ���� �����ؼ� �Ű��ϴ°� ������ �ϳ�����. ó���� �� ������

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> declare;
    map<string, int> declare_cnt;
    map<string, int> Ans;
    answer.resize(id_list.size());

    for (auto& e : report)
    {
        bool CHK = false;
        string temp1 = "";
        string temp2 = "";
        for (auto& q : e) // q : char
        {
            if (q == ' ')
            {
                CHK = true;
                continue;
            }
            if (!CHK)
            {
                temp1 += q;
                continue;
            }
            temp2 += q;
        }
        declare[temp1].push_back(temp2);
    }

    for (auto& e : id_list)
    {
        sort(declare[e].begin(), declare[e].end());
        declare[e].erase(unique(declare[e].begin(), declare[e].end()), declare[e].end());
    }
    for (int i = 0; i < id_list.size(); i++)
    {
        for (auto& q : declare[id_list[i]])
            declare_cnt[q]++;
    }

    for (int i = 0; i < id_list.size(); i++)
    {
        for (auto& q : declare[id_list[i]])
        {
            if (declare_cnt[q] >= k)
                answer[i]++;
        }
    }

    return answer;
}