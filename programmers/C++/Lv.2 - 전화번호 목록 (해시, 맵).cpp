#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<string, int> HASH;

// n이 백만이어서 시간초과 주의

// 1. 크기가 작은 순서대로 정렬
// 2. unordered_map은 시간 복잡도가 O(1)로, 굉장히 고성능의 자료구조다. 따라서 맵 사용으로 인한 시간 복잡도를 거의 없도록 하자.
// 3. 즉, 2천번 안으로 끝내야 한다.

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

bool solution(vector<string> phone_book) { // 백준 5052와 똑같은 문제

    sort(phone_book.begin(), phone_book.end(), cmp);

    return CHK(phone_book);
}