#include <string>
#include <vector>

using namespace std;

// 정확하고 신속한 인덱스 판단이 필요하다.

// 둘다 O(N^2)이고, arr1은 안쪽 루프를 오른쪽 탐색. arr2는 안쪽 루프를 아래 탐색으로 설정

int return_SUM(vector<int> a, vector<int> b)
{
    int SUM = 0;
    for (int i = 0; i < a.size(); i++)
        SUM += (a[i] * b[i]);
    return SUM;
}

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    answer.resize(arr1.size());

    for (int i = 0; i < arr1.size(); i++)
    {
        for (int j = 0; j < arr2[0].size(); j++)
        {
            vector<int> temp;
            for (int k = 0; k < arr2.size(); k++)
                temp.push_back(arr2[k][j]);
            answer[i].push_back(return_SUM(arr1[i], temp));
        }
    }

    return answer;
}