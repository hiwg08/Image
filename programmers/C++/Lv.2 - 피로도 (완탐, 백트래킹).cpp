#include <bits/stdc++.h>

using namespace std;

int N, K, MAX = -987654321;

bool Vis[10]{ 0 };
int Arr[10]{ 0 };

vector<vector<int>> D;

void Recursion(int Idx)
{
    if (Idx == N)
    {
        int K_temp = K;
        int SUM = 0;
        for (int i = 0; i < Idx; i++)
        {
            if (K_temp >= D[Arr[i]][0])
            {
                K_temp -= D[Arr[i]][1];
                SUM++;
            }
        }
        MAX = max(MAX, SUM);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!Vis[i])
        {
            Vis[i] = true;
            Arr[Idx] = i;
            Recursion(Idx + 1);
            Vis[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {

    D = dungeons;

    K = k;

    N = dungeons.size();

    Recursion(0);

    return MAX;
}