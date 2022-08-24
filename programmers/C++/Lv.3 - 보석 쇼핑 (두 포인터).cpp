#include <bits/stdc++.h>

using namespace std;

map<string, int> GEM;

pair<int, int> Ans;

int CNT = 0, CHK = 0, Idx_1 = 0, Idx_2 = -1, MIN = INT_MAX;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    for (int i = 0; i < gems.size(); i++)
    {
        if (GEM[gems[i]] == 0)
        {
            GEM[gems[i]]++;
            CNT++;
        }
    }

    GEM.erase(GEM.begin(), GEM.end());

    while (true)
    {
        if (Idx_2 == gems.size() - 1 && CHK < CNT)
            break;
        if (Idx_2 != -1 && Idx_1 > Idx_2)
            break;
        if (CHK == CNT)
        {
            if (MIN > Idx_2 - Idx_1)
            {
                MIN = Idx_2 - Idx_1;
                Ans = { Idx_1, Idx_2 };
            }
            GEM[gems[Idx_1]]--;
            if (GEM[gems[Idx_1]] == 0)
                CHK--;
            Idx_1++;
        }
        else
        {
            Idx_2++;
            if (GEM[gems[Idx_2]] == 0)
                CHK++;
            GEM[gems[Idx_2]]++;

        }
    }

    answer.push_back(Ans.first + 1);
    answer.push_back(Ans.second + 1);

    return answer;
}