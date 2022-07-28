#include <iostream>

using namespace std;

// 초기 N도 2의 배수이고 부전승이 없기 때문에 쉬움 
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

// 0 1 2 3 4 5 6 7

// 0 1

int A, B, Ans;

int solution(int n, int a, int b)
{
    Ans = 1;

    A = a - 1;
    B = b - 1;

    while (n >= 2)
    {
        if (A / 2 == B / 2)
            break;
        A /= 2;
        B /= 2;
        n /= 2;
        Ans++;
    }

    return Ans;
}