#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) { // 내적의 특성 상 a와 b의 길이는 같다.
    int answer = 0;

    for (int i = 0; i < a.size(); i++)
        answer += (a[i] * b[i]);

    return answer;
}