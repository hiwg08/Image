#include <bits/stdc++.h>

using namespace std;

int dx[2]{ -1, 1 };

int Result;

class BFS_Info
{
public:
    int x, Index;
    BFS_Info(int _x, int _Index)
        :x(_x), Index(_Index)
    {}
};

void BFS(vector<int> numbers, int target)
{
    int CHK_Index = 1;

    queue<BFS_Info> Q;

    Q.push(BFS_Info(numbers[0], CHK_Index));
    Q.push(BFS_Info(-numbers[0], CHK_Index));

    while (!Q.empty())
    {
        BFS_Info st1 = Q.front();
        Q.pop();
        if (st1.Index >= numbers.size())
        {
            if (target == st1.x)
                Result++;
            continue;
        }
        for (int dir = 0; dir < 2; dir++)
        {
            int nx = st1.x + numbers[st1.Index] * dx[dir];
            Q.push(BFS_Info(nx, st1.Index + 1));
        }
    }
}

// 주어진 숫자의 개수가 20개 이하이기 때문에 BFS로 풀이가 가능하다.
// 말이 BFS지, 완전 탐색으로 풀어도 효율성 측면에서는 똑같다.

int solution(vector<int> numbers, int target) {

    BFS(numbers, target);

    return Result;
}