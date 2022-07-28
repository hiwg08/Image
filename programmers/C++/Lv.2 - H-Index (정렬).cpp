#include <bits/stdc++.h>

using namespace std;

// 0 1 (2) 3 6 5

// h, n - h(나머지)

// 2 4 6 8 10

// 3

int H;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end());

    // vector<int> temp{0, 0, 0, 0, 0};
    // citations = temp; // 디버깅

    H = 0;

    for (int i = 0; i < citations.size(); i++)
    {
        while (true)
        {
            // 1. 현재 논문에서 오른쪽으로 볼 때 카운트되는 논문의 수 구하기 
            if (citations.size() - i < H || i > H) // 말이 안 되는 경우
                break;
            if (H > citations[i])
                break;
            H++;
        }
    }

    return H - 1;
}