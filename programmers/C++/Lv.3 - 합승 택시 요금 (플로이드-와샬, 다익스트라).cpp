#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int N;

int Map[201][201]{ 0 };

int MIN = 987654321;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) { // 전형적인 플로이드-와샬 문제.
                                                                      // N이 200까지여서 바로 플로이드-와샬임을 눈치 챘었는데, 만약에 N이 많이 컸더라면
                                                                      // 난이도도 많이 올라가며, 많이 헤맸을 것 같다.
                                                                      // 이럴 때는 3번의 다익스트라를 쓰면 되는데
                                                                      // 1. 시작 지점 (int s)에서 모든 지점간의 최단 거리 구하기
                                                                      // 2. a 지점 (int a)에서 모든 지점간의 최단 거리 구하기
                                                                      // 3. b 지점 (int b)에서 모든 지점간의 최단 거리 구하기
                                                                      // 4. i로 for문을 돌면서(1~N) "s -> i" + "a -> i" + "b -> i"를 구해주면 된다.

    N = n;

    for (auto e : fares)
    {
        int I1 = 0, I2 = 0, I3 = 0;
        for (int i = 0; i < e.size(); i++)
        {
            switch (i)
            {
            case 0:
                I1 = e[i];
                break;
            case 1:
                I2 = e[i];
                break;
            case 2:
                I3 = e[i];
                break;
            }
        }
        Map[I1][I2] = I3;
        Map[I2][I1] = I3;
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                Map[i][j] = 0;
            else
            {
                if (Map[i][j] == 0)
                    Map[i][j] = INF;
            }
        }
    } // 그래프 초기화 (시작 지점과 도착 지점이 같으면 0, 아니라면 도달이 불가능하므로 INF 적용

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                if (Map[j][k] > Map[j][i] + Map[i][k])
                    Map[j][k] = Map[j][i] + Map[i][k];
            }
        }
    } // 플로이드-와샬 알고리즘 적용

    for (int i = 1; i <= N; i++)
    {
        if (Map[s][i] == INF || Map[i][a] == INF || Map[i][b] == INF)
            continue;
        MIN = min(MIN, Map[s][i] + Map[i][a] + Map[i][b]);
    } // 도달 불가능한 부분을 제외하고 모든 정점에 대한 최단거리의 합의 최솟값을 구해주면 끝

    cout << MIN << '\n';

    return MIN;
}