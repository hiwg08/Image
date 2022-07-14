#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> temp_answer;
    
    for (int i = 0; i < progresses.size(); i++)
    {
        int SUM = progresses[i];
        int CNT = 0;
        while(SUM < 100)
        {
            SUM += speeds[i];
            CNT++;
        }
        temp_answer.push_back(CNT);
    }
    
    int MAX = -999999;
    
    int INDEX = -1;
    
    for (auto e : temp_answer)
    {
        if (e > MAX)
        {
            answer.push_back(1);
            INDEX++;
            MAX = e;
        }
        else
            answer[INDEX]++;
    }
    
    return answer;
}
