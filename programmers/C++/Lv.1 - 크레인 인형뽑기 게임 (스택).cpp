#include <bits/stdc++.h>

using namespace std;

int Map[31][31]{ 0 };

int N, Result;

stack<int> Ans;

int solution(vector<vector<int>> board, vector<int> moves) { // 전형적인 스택 문제

    Ans.push(-1);

    N = board.size();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            Map[i][j] = board[i][j];
    }

    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Map[j][moves[i] - 1] != 0)
            {
                if (Ans.top() == Map[j][moves[i] - 1])
                {
                    Ans.pop();
                    Result += 2;
                }
                else
                    Ans.push(Map[j][moves[i] - 1]);

                Map[j][moves[i] - 1] = 0;
                break;
            }
        }
    }

    return Result;
}