#include <bits/stdc++.h>

using namespace std;

// 24 , 42

// ���μ�����

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

int solution(vector<int> arr) { // ���μ����ظ� �̿��� Ǯ��
                                // �����佺�׳׽��� ü�� �̿��Ͽ� �Ҽ� ���ϱ� + �� ���Һ��� ���μ� ���ذ� ���ϱ� + �̵��� ��� �����ϵ��� �Ҽ����� ������ ���� ��, �ϰ� ����
                                // �ٵ� �̰� �ʹ� ��ȿ�����̴�
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


// ������ ���� ���
// ex) �迭�� {2, 6, 8, 14}�� �־����� ��, 2, 6�� �ּ� ����� ���ϱ�, ���⼭ ���� �ּ� ����� 6�� 8 ���� �ּ� ����� ���ϱ�, ���⼭ ���� �ּ� ����� 24�� 14 ���� �ּ� ������� ���ϸ� �ȴ�. (168)

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