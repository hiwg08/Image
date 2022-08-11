#include <bits/stdc++.h>

using namespace std;

// �� ó���� *, #

// 1 2 3 1�� 1��
// 4 5 6 2�� 1��
// 7 8 9 3�� 1��
// * 0 #


// 7�� 3���� ������ ������ : 1, �� : 2 (�� + 1�� ��, �������� ��)

int Left = 10;
int Right = 12;

string Ans = "";

void Get_Distance(int K, string hand)
{
    int left_hang = ((Left - 1) / 3) + 1;
    int left_yeol = ((Left - 1) % 3);
    int right_hang = ((Right - 1) / 3) + 1;
    int right_yeol = ((Right - 1) % 3);
    int K_hang = ((K - 1) / 3) + 1;
    int K_yeol = ((K - 1) % 3);

    if (abs(left_hang - K_hang) + abs(left_yeol - K_yeol) > abs(right_hang - K_hang) + abs(right_yeol - K_yeol))
    {
        Ans += 'R';
        Right = K;
    }
    else if (abs(left_hang - K_hang) + abs(left_yeol - K_yeol) < abs(right_hang - K_hang) + abs(right_yeol - K_yeol))
    {
        Ans += 'L';
        Left = K;
    }
    else
    {
        if (hand == "right")
        {
            Ans += 'R';
            Right = K;
        }
        else
        {
            Ans += 'L';
            Left = K;
        }
    }
}


string solution(vector<int> numbers, string hand) { // ���� ������ �� ����.

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 0)
            numbers[i] = 11;
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            Ans += 'L';
            Left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            Ans += 'R';
            Right = numbers[i];
        }
        else
            Get_Distance(numbers[i], hand);
    }

    return Ans;
}