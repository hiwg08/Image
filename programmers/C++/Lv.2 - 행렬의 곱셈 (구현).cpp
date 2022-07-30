#include <string>
#include <vector>

using namespace std;

// ��Ȯ�ϰ� �ż��� �ε��� �Ǵ��� �ʿ��ϴ�.

// �Ѵ� O(N^2)�̰�, arr1�� ���� ������ ������ Ž��. arr2�� ���� ������ �Ʒ� Ž������ ����

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