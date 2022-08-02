#include <bits/stdc++.h>

using namespace std;

int SUM;

vector<int> Yaksu_Collect;

int B, Y;

void Get_Yaksu()
{
    int temp = 2;
    Yaksu_Collect.push_back(1);
    Yaksu_Collect.push_back(SUM);

    while (sqrt(SUM) >= temp)
    {
        if (SUM % temp == 0)
        {
            Yaksu_Collect.push_back(temp);
            Yaksu_Collect.push_back(SUM / temp);
        }
        temp++;
    }
}

bool CHK_Brown(int n, int m)
{
    return (2 * (n + m - 2)) == B;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    B = brown;
    Y = yellow;

    SUM = B + Y;

    Get_Yaksu();

    sort(Yaksu_Collect.begin(), Yaksu_Collect.end());

    for (int i = 0; i < Yaksu_Collect.size() / 2; i++)
    {
        if (CHK_Brown(Yaksu_Collect[Yaksu_Collect.size() - 1 - i], Yaksu_Collect[i]))
        {
            answer.push_back(Yaksu_Collect[Yaksu_Collect.size() - 1 - i]);
            answer.push_back(Yaksu_Collect[i]);
            break;
        }
    }

    return answer;
}