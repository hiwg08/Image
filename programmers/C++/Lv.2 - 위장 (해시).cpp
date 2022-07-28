#include <bits/stdc++.h>

using namespace std;

map<string, int> CHK;

vector<string> Kind_Of_Clothes;

int Ans = 1;

int solution(vector<vector<string>> clothes) {

    for (int i = 0; i < clothes.size(); i++)
    {
        CHK[clothes[i][1]]++;
        Kind_Of_Clothes.push_back(clothes[i][1]);
    }

    sort(Kind_Of_Clothes.begin(), Kind_Of_Clothes.end());
    Kind_Of_Clothes.erase(unique(Kind_Of_Clothes.begin(), Kind_Of_Clothes.end()), Kind_Of_Clothes.end());

    for (auto e : Kind_Of_Clothes)
        Ans *= (CHK[e] + 1);

    return Ans - 1;
}