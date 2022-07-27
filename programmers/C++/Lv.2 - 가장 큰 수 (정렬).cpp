#include <bits/stdc++.h>

using namespace std;

// 3, 32, 319 --> 332319   
// 3, 34, 319 --> 343319  
// 3, 32, 369 --> 369332
// 343 3432 --> 3433432
// 343 3439 --> 3439343

// 3 30 --> 3이 먼저다.

bool cmp(int a, int b)
{
    string a_s = to_string(a);
    string b_s = to_string(b);

    return stoi(a_s + b_s) > stoi(b_s + a_s);
}

string solution(vector<int> numbers) { // 그리디 알고리즘 + 정렬
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0 && numbers[i] == 0)
        {
            answer = "0";
            break;
        }
        else
            answer += to_string(numbers[i]);
    }

    return answer;
}