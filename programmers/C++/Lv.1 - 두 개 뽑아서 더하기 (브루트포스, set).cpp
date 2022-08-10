#include <bits/stdc++.h>

using namespace std;


vector<int> solution(vector<int> numbers) { // set을 이용하는 방법도 있다. (set은 중복 허용 x)
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
            answer.push_back(numbers[i] + numbers[j]);
    }

    sort(answer.begin(), answer.end());

    answer.erase(unique(answer.begin(), answer.end()), answer.end());

    return answer;
}