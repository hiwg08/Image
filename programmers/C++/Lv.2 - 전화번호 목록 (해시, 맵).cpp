#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> HASH;

// n�� �鸸�̾ �ð��ʰ� ����

// 1. ũ�Ⱑ ���� ������� ����
// 2. unordered_map�� �ð� ���⵵�� O(1)��, ������ ������ �ڷᱸ����. ���� �� ������� ���� �ð� ���⵵�� ���� ������ ����.
// 3. ��, 2õ�� ������ ������ �Ѵ�.

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

bool CHK(vector<string>& phone_book)
{
    int ANT = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < phone_book[i].size(); j++)
        {
            temp += phone_book[i][j];
            if (HASH[temp] >= 1)
                return false;
        }
        HASH[temp] = ANT;
        ANT++;
    }
    return true;
}

bool solution(vector<string> phone_book) { // ���� 5052�� �Ȱ��� ����

    sort(phone_book.begin(), phone_book.end(), cmp);

    return CHK(phone_book);
}