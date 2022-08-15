#include <iostream>
#include <string>
#include <vector>

using namespace std;

int SIGN[2]{ -1, 1 };

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for (int i = 0; i < absolutes.size(); i++)
        answer += (SIGN[signs[i]] * absolutes[i]);

    return answer;
}