#include <bits/stdc++.h>

using namespace std;

// �� ���� 1���� ������ ��� �ɱ�? --> �� ���� 31���� ������ ��� �ɱ�?

int MONTH[13]{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

// 0 1 2 3 4 5 6

// 1 --> 4, 8 --> 11, 15 --> 18, 22 --> 26, 29 --> 34

string DAY[7]{ "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

string GET_F(int M, int D)
{
    int REMAIN = 4;
    for (int i = 1; i < M; i++)
        REMAIN = ((REMAIN + MONTH[i]) % 7);

    return DAY[(REMAIN + D) % 7];
}

string solution(int a, int b) {

    return GET_F(a, b);

}