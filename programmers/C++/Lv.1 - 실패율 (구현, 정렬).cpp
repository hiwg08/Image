include <bits / stdc++.h>

using namespace std;

int CHALLANGE_STAGE[501]{ 0 };

vector<pair<double, int>> PROBABILITY;

bool cmp(pair<double, int> a, pair<double, int> b)
{
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) { // 왜 나는 이 쉬운 구현 문제를 허둥지둥 됐을까....
    vector<int> answer;

    for (int i = 0; i < stages.size(); i++)
        CHALLANGE_STAGE[stages[i]]++;

    int S = stages.size();

    for (int i = 1; i <= N; i++)
    {
        cout << i << " : " << CHALLANGE_STAGE[i] << " " << S << '\n';
        PROBABILITY.push_back({ (double)CHALLANGE_STAGE[i] / S, i });
        S -= CHALLANGE_STAGE[i];
    }

    stable_sort(PROBABILITY.begin(), PROBABILITY.end(), cmp);

    for (auto e : PROBABILITY)
        answer.push_back(e.second);

    return answer;
}