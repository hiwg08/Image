#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int DP[501][501]{ 0 };

int solution(vector<vector<int>> triangle) { // 매우 쉬운 DP 문제
    int answer = -987654321;

    DP[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
            DP[i][j] = triangle[i][j] + max(DP[i - 1][j], DP[i - 1][j - 1]);
    }

    for (int i = 0; i < triangle.size(); i++)
        answer = max(answer, DP[triangle.size() - 1][i]);

    return answer;
}