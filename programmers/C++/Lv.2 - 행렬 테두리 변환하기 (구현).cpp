#include <bits/stdc++.h>

using namespace std;


// 1. 회전하는 로직 구현
// 2. 작은 숫자 찾기 (1번과 같은 반복문 상에서 구현)
// 3. 배열에 넣기

// 1, 1, 4, 3
// 2, 2, 5, 5
// 4, 0, 5, 2

int Map[101][101]{0};

int Map_Copy[101][101]{0};

int R, C;

void Init()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            Map[i][j] = Map_Copy[i][j];
    }
}

int Rotate(vector<int> phase)
{
    int sx = phase[0] - 1;
    int sy = phase[1] - 1;
    int ex = phase[2] - 1;
    int ey = phase[3] - 1;

    // 좌측 상단 (1, 1) -> 우측 상단 (1, 3) -> 우측 하단 (4, 3) -> 좌측 하단 (4, 1) 
    // --> 좌측 상단 (1, 1)
    
    // 앞으로 나오는 for문은 항상 오리지널 map을 기준으로
    for (int i = sy; i < ey; i++) // #1
        Map_Copy[sx][i + 1] = Map[sx][i];
        
    
    for (int i = sx; i < ex; i++) // #2
        Map_Copy[i + 1][ey] = Map[i][ey];
        
    
    for (int i = ey; i > sy; i--) // #3
        Map_Copy[ex][i - 1] = Map[ex][i];
        
    
     for (int i = ex; i > sx; i--) // #4
          Map_Copy[i - 1][sy] = Map[i][sy];
    
    int MIN = 999999;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (Map_Copy[i][j] != Map[i][j])
                MIN = min(MIN, Map_Copy[i][j]);
        }
    }
    
    Init();
    
    return MIN;
    
     // 예는 나중에 Init();
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    R = rows;
    C = columns;
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            Map[i][j] = (i * C + j) + 1;
    }
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            Map_Copy[i][j] = Map[i][j];
    }
    
    for (auto e : queries)
        answer.push_back(Rotate(e));
    
    return answer;
}
