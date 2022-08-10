#include <bits/stdc++.h>

using namespace std;

// lost + reserve에 없는 학생들은 무조건 수업을 들을 수 있음

// (1) (2) 3 4 (5) 6

int Sport_Bind[31]{ 0 };

int solution(int n, vector<int> lost, vector<int> reserve) { // 재밌는 그리디 문제.
    int answer = 0;

    for (int i = 0; i < lost.size(); i++)
        Sport_Bind[lost[i]] = -1;

    for (int i = 0; i < reserve.size(); i++)
    {
        if (Sport_Bind[reserve[i]] == -1)
            Sport_Bind[reserve[i]] = 0;
        else
            Sport_Bind[reserve[i]] = 1;
    } // 체육복 여벌을 가진 학생도 도난당할 수 있다는 사실을 놓쳐서 헤맸다;; 문제를 잘 보자.


    for (int i = 1; i <= n; i++)
    {
        if (Sport_Bind[i] == 0)
            continue;
        if (Sport_Bind[i] == 1)
        {
            if (i - 1 >= 1 && Sport_Bind[i - 1] == -1)
            {
                Sport_Bind[i - 1] = 0;
                Sport_Bind[i] = 0;
                continue;
            }
            if (i + 1 <= n && Sport_Bind[i + 1] == -1)
            {
                Sport_Bind[i + 1] = 0;
                Sport_Bind[i] = 0;
                continue;
            }
        }
    }

    // (1) 2 (3) 4 5 (6) (7) 8 9 (10)

    for (int i = 1; i <= n; i++)
    {
        if (Sport_Bind[i] == 0 || Sport_Bind[i] == 1)
            answer++;
    }

    return answer;
}