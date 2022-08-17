#include <bits/stdc++.h>

using namespace std;

// 문자열 하나로 자르는 건 크게 어려울 건 없는 듯..?

int Return_Ans(string s)
{
    int MIN = s.size();

    for (int i = 1; i <= s.size() / 2; i++)
    {
        int CNT = 1;
        string temp = s.substr(0, i);
        string Present = "";

        for (int j = i; j < s.size(); j += i)
        {
            string a = s.substr(j, i);
            if (temp == a)
                CNT++;

            else
            {
                if (CNT > 1)
                    Present += to_string(CNT);
                CNT = 1;
                Present += temp;
                temp = a;
            }

        }
        if (CNT > 1)
            Present += to_string(CNT);
        Present += temp;

        MIN = min(MIN, (int)Present.size());
    }

    return MIN;
}

int solution(string s) {

    return Return_Ans(s);
}