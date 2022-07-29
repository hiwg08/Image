#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<char, bool> skill_chk;

int solution(string skill, vector<string> skill_trees) { // N�� ������ �۾Ƽ� ��Ž���ε� Ǯ �� �ִ�. �ణ�� ���̵� �־�� Ǯ �� �ִ� ����.
    int answer = 0;

    for (int i = 0; i < skill.size(); i++)
        skill_chk[skill[i]] = true;

    for (int i = 0; i < skill_trees.size(); i++)
    {
        bool CHK = true;
        int skill_Idx = 0;
        for (int j = 0; j < skill_trees[i].size(); j++)
        {
            if (skill_Idx >= skill.size())
                continue;
            if (skill[skill_Idx] != skill_trees[i][j])
            {
                if (skill_chk[skill_trees[i][j]])
                {
                    CHK = false;
                    break;
                }
            }
            else
                skill_Idx++;
        }
        if (CHK)
            answer++;
    }

    return answer;
}