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


vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) { // �׳� �ؽ�, ���� ������ ������ ���Ʈ���� ����... Ʈ���� ����� ����� �������ϰ� Ǯ��ôµ�
                                                                                                                  // �׽�Ʈ���̽��� �� �¾����� �׽�Ʈ���� ��©���� ���̾���.
    vector<int> answer;

    for (int i = 0; i < enroll.size(); i++)
        RELATION[enroll[i]] = referral[i];

    for (int i = 0; i < seller.size(); i++)
        DFS(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(MONEY[enroll[i]]);

    return answer;
}