#include <bits/stdc++.h>

using namespace std;

// 본질은 브루트포스다. 이걸 DFS/BFS로 돌린 것일 뿐.
// 모든 경우 탐색이기 때문에, Vis 배열을 쓰면 안되는 것에 주의하자.

queue<pair<string, int>> Q;

vector<string> WORD;

string TARGET;

int BFS(string begin)
{
    Q.push({ begin, 0 });
    while (!Q.empty())
    {
        pair<string, int> st1 = Q.front();
        Q.pop();

        if (st1.first == TARGET)
            return st1.second;
        if (st1.second >= WORD.size())
            continue;

        for (int i = 0; i < WORD.size(); i++)
        {
            int CNT = 0;
            for (int j = 0; j < WORD[i].size(); j++)
            {
                if (st1.first[j] == WORD[i][j])
                    CNT++;
            }
            if (CNT == st1.first.size() - 1)
                Q.push({ WORD[i], st1.second + 1 });
        }
    }
    return 0;
}

int solution(string begin, string target, vector<string> words) {

    WORD = words;

    TARGET = target;

    return BFS(begin);
}