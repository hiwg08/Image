#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, string> RELATION;

unordered_map<string, int> MONEY;

void DFS(string a, int b)
{
    if (a == "-" || b == 0)
        return;
    MONEY[a] += b - (b / 10);
    DFS(RELATION[a], b / 10);
}


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) { // 그냥 해시, 맵을 가장한 무지성 브루트포스 문제... 트리를 사용한 방법이 없을까하고 풀어봤는데
                                                                                                                  // 테스트케이스는 다 맞았으나 테스트에서 얄짤없이 밴이었다.
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)
        RELATION[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); i++)
        DFS(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(MONEY[enroll[i]]);

    return answer;
}