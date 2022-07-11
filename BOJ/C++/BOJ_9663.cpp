#include <bits/stdc++.h>

using namespace std;

int N;

int CNT = 0;

bool COL[15]{ 0 };

vector<pair<int, int>> Queen_Pos;

bool Solution(int x, int y) // ���� �� �˰��򺸴� ���� Ǯ�̹��� ���� �� ������, ���������� �� �𸣰ڴ�.
							// BOJ 2173���� ������ ���� �޾Ҵ�
{
	for (auto& e : Queen_Pos)
	{
		if (e.first == x || e.second == y || (abs(e.first - x) == abs(e.second - y)))
			return false;
	}
	return true;
}

void Recursive(int Index)
{
	if (Index >= N)
	{
		CNT++;
		return;
	}

	for (int j = 0; j < N; j++) // ****** ��� �� �� �ϳ��� ��, ��� �� �� �ϳ��� ���� �� �� �ִ°� �˾ƾ� ������ Ǯ �� �ִ�.
								// �Լ��� �Ű������� Index�� �� ��ȣ, �ش� �ݺ����� j�� �� ��ȣ��.
								// �װ� �˸� �������� ������ �Ա� 
	{
		if (COL[j]) // ���� �̹� Index�� 1 ���߱� ������ �Ű� �� �ᵵ �ǰ�, ���� �Ű澲�� �ȴ�.
			continue;

		if (!Solution(Index, j)) // �밢���� ��ġ�� �� ã�� (���� �� ���� �˰����� ���� �� ������ ����� ���� ���ϰڴ�)
			continue;

		COL[j] = true;
		Queen_Pos.push_back({ Index, j });

		Recursive(Index + 1);

		COL[j] = false;
		Queen_Pos.pop_back(); // �������� �������� ��Ʈ��ŷ ���
	}
}

int main()
{
	cin >> N;

	Recursive(0);

	cout << CNT << '\n';
}