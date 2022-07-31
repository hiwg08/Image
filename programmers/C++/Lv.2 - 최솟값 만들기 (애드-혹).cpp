#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B) // 아이디어가 필요한 문제다. 많은 사람들이 정답을 맞춘걸 보면 굉장히 쉬운 애드-혹 문제다.
{
    int Ans = 0;

    sort(A.begin(), A.end());

    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++)
        Ans += (A[i] * B[i]);

    return Ans;
}