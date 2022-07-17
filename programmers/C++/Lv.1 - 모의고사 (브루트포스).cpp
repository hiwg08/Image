#include <bits/stdc++.h>

using namespace std;

int first_math_give_up[5] = { 1, 2, 3, 4, 5 };
int second_math_give_up[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int third_math_give_up[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

int Ans[4]{ 0 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == first_math_give_up[i % 5])
            Ans[1]++;
        if (answers[i] == second_math_give_up[i % 8])
            Ans[2]++;
        if (answers[i] == third_math_give_up[i % 10])
            Ans[3]++;
    }

    int MAX = max(Ans[1], max(Ans[2], Ans[3]));

    for (int i = 1; i <= 3; i++)
    {
        if (MAX == Ans[i])
            answer.push_back(i);
    }

    return answer;
}