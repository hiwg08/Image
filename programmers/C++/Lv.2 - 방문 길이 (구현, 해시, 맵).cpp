#include <bits/stdc++.h>

using namespace std;

int dir_x = 5, dir_y = 5;

int dx[]{ 0, 1, 0, -1 };
int dy[]{ -1, 0, 1, 0 };

map<char, int> DIR;

map<pair<pair<int, int>, pair<int, int>>, bool> Route_Visit;

int solution(string dirs) { // 좌표에 벗어나지 않는 방향을 제외하고는 방문했던 곳도 다시 방문해야 한다는 사실을 깜빡해서 시간을 많이 잡아먹었다. 앞으로는 주의하자.
    int answer = 0;

    DIR['D'] = 0; DIR['R'] = 1; DIR['U'] = 2; DIR['L'] = 3;

    for (int i = 0; i < dirs.size(); i++)
    {
        int nx = dir_x + dx[DIR[dirs[i]]];
        int ny = dir_y + dy[DIR[dirs[i]]];
        if (nx < 0 || ny < 0 || nx >= 11 || ny >= 11)
            continue;
        if (Route_Visit[{ {nx, ny}, { dir_x, dir_y }}] || Route_Visit[{ {dir_x, dir_y}, { nx, ny }}])
        {
            dir_x = nx;
            dir_y = ny;
            continue;
        }

        Route_Visit[{ {nx, ny}, { dir_x, dir_y }}] = true;
        Route_Visit[{ {dir_x, dir_y}, { nx, ny }}] = true;
        dir_x = nx;
        dir_y = ny;
        answer++;
    }

    return answer;
}