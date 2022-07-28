#include <bits/stdc++.h>

using namespace std;

queue<int> Q, Q_temp, Q_Index, Q_Index_temp;

int solution(vector<int> priorities, int location) {

    int Ans = 0;

    for (int i = 0; i < priorities.size(); i++)
    {
        Q.push(priorities[i]);
        Q_Index.push(i);
    }


    while (!Q.empty())
    {
        int temp_first = Q.front();
        int temp_first_index = Q_Index.front();

        Q.pop();
        Q_Index.pop();

        bool CHK = false;

        while (!Q.empty())
        {
            int temp_second = Q.front();
            int temp_second_index = Q_Index.front();

            Q_temp.push(temp_second);
            Q_Index_temp.push(temp_second_index);

            Q.pop();
            Q_Index.pop();

            if (temp_first < temp_second)
                CHK = true;
        }

        while (!Q_temp.empty())
        {
            Q.push(Q_temp.front());
            Q_Index.push(Q_Index_temp.front());

            Q_temp.pop();
            Q_Index_temp.pop();
        }

        if (CHK)
        {
            Q.push(temp_first);
            Q_Index.push(temp_first_index);
        }

        else
        {
            Ans++;
            if (temp_first_index == location)
                break;
        }
    }
    return Ans;
}