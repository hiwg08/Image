#include <bits/stdc++.h>

using namespace std;

map<int, bool> CHK;

int solution(vector<int> nums)
{
    int CNT = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!CHK[nums[i]])
        {
            CHK[nums[i]] = true;
            CNT++;
        }
    }

    return CNT > (nums.size() / 2) ? (nums.size() / 2) : CNT;

}