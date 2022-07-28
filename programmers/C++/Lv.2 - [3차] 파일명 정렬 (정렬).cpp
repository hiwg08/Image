#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b)
{
    string HEAD_a = "", NUMBER_a = "", HEAD_b = "", NUMBER_b = "";
    bool CHK = false;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] < '0' || a[i] > '9')
        {
            if (CHK)
                break;
            else
                HEAD_a += toupper(a[i]);
        }

        if (a[i] >= '0' && a[i] <= '9')
        {
            CHK = true;
            NUMBER_a += a[i];
        }
    }

    CHK = false;

    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] < '0' || b[i] > '9')
        {
            if (CHK)
                break;
            else
                HEAD_b += toupper(b[i]);
        }

        if (b[i] >= '0' && b[i] <= '9')
        {
            CHK = true;
            NUMBER_b += b[i];
        }
    }

    if (HEAD_a == HEAD_b)
        return stoi(NUMBER_a) < stoi(NUMBER_b);
    return HEAD_a < HEAD_b;
}

vector<string> solution(vector<string> files) {
    // 애초에 문제 의도 자체가 stable_sort 사용이다. (값이 동일한 원소들의 순서를 sort는 완전히 보장할 수 없다.)

    stable_sort(files.begin(), files.end(), cmp);

    return files;
}