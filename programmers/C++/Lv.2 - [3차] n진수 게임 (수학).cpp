#include <bits/stdc++.h>

using namespace std;

// 1. 숫자를 진수로 변환하는 함수를 짜자.
// 2. 쪼개면서 계속 튜브의 순서에 맞는 숫자를 덧붙여야함.

// 0 / 1 / 1 0 / 1 1 / 1 0 0 / 1 0 1 / 1 1 0 / 1 1 1

// 0 1 2 3 4 5 6 7 8 9 A B C D E F 1 0 1 1 1 2 1 3

int CNT, Person, Tube_Order;

string Jinsu_Convert(int N, int jinsu)
{
    int temp = 1;
    string Ans = "";

    while (true)
    {
        if (N < temp * jinsu)
            break;
        temp *= jinsu;
    }

    while (temp != 0)
    {
        if (N / temp >= 10 && N / temp <= 15)
            Ans += (char)((N / temp) + 55);
        else
            Ans += to_string(N / temp);

        N %= temp;
        temp /= jinsu;
    }

    return Ans;
}


string Solve(int jinsu)
{
    int N = 0;

    int Idx = 1;

    int CHK = 0;

    string Ans = "";

    while (true)
    {
        string temp = Jinsu_Convert(N, jinsu);

        for (auto e : temp)
        {
            if (Idx % Person == Tube_Order)
            {
                Ans += e;
                CHK++;
            }
            Idx++;

            if (CHK == CNT)
                break;
        }

        if (CHK == CNT)
            break;

        N++;
    }

    return Ans;
}


string solution(int n, int t, int m, int p) { // 전형적인 수학 문제

    CNT = t;
    Person = m;
    Tube_Order = p;

    if (Person == Tube_Order)
        Tube_Order = 0;

    return Solve(n);
}