#include <bits/stdc++.h>

using namespace std;

// 24 , 42

// 소인수분해

bool Sosu[101]{ 0 };

vector<int> S_Collect;

int Arr[101]{ 0 };

int Arr_Copy[101]{ 0 };

void Eratos()
{
    Sosu[1] = true;
    int start = 3;
    while (start <= 100)
    {
        if (Sosu[start])
        {
            start += 2;
            continue;
        }
        for (int i = start; i <= 100; i += start)
        {
            if (i == start)
                continue;
            Sosu[i] = true;
        }
        start += 2;
    }
}

void Get_F(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> temp;
        int Idx = 0;
        int SUM = arr[i];
        memset(Arr_Copy, 0, sizeof(Arr_Copy));

        while (Idx >= S_Collect.size() || SUM != 1)
        {
            if (SUM % S_Collect[Idx] == 0)
            {
                temp.push_back(S_Collect[Idx]);
                SUM /= S_Collect[Idx];
                Arr_Copy[S_Collect[Idx]]++;
            }
            else
                Idx++;
        }

        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        for (auto e : temp)
            Arr[e] = max(Arr[e], Arr_Copy[e]);
    }
}

int solution(vector<int> arr) { // 소인수분해를 이용한 풀이
                                // 에라토스테네스의 체를 이용하여 소수 구하기 + 각 원소별로 소인수 분해값 구하기 + 이들을 모두 만족하도록 소수들의 개수를 구한 후, 일괄 곱셈
                                // 근데 이건 너무 비효율적이다
    int answer = 1;

    Eratos();

    S_Collect.push_back(2);

    for (int i = 1; i <= 100; i++)
    {
        if (i % 2 != 0 && !Sosu[i])
            S_Collect.push_back(i);
    }

    Get_F(arr);

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < Arr[i]; j++)
            answer *= i;
    }

    return answer;
}


// 이쪽은 쉬운 방법
// ex) 배열이 {2, 6, 8, 14}로 주어졌을 때, 2, 6의 최소 공배수 구하기, 여기서 나온 최소 공배수 6과 8 간의 최소 공배수 구하기, 여기서 나온 최소 공배수 24와 14 간의 최소 공배수를 구하면 된다. (168)

//#include <string>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
//int lcm(int x, int y) { return x * y / gcd(x, y); }
//int solution(vector<int> arr) {
//    int answer = arr[0];
//    for (int i = 1; i < arr.size(); i++)
//        answer = lcm(answer, arr[i]);
//    return answer;
//}