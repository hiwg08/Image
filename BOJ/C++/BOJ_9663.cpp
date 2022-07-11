#include <bits/stdc++.h>

using namespace std;

int N;

int CNT = 0;

bool COL[15]{ 0 };

vector<pair<int, int>> Queen_Pos;

bool Solution(int x, int y) // 뭔가 이 알고리즘보다 좋은 풀이법이 있을 것 같지만, 아직까지는 잘 모르겠다.
							// BOJ 2173번의 도움을 많이 받았다
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

	for (int j = 0; j < N; j++) // ****** 모든 행 당 하나의 퀸, 모든 열 당 하나의 퀸이 올 수 있는걸 알아야 문제를 풀 수 있다.
								// 함수의 매개변수인 Index는 행 번호, 해당 반복문의 j는 열 번호다.
								// 그걸 알면 나머지는 식은죽 먹기 
	{
		if (COL[j]) // 행은 이미 Index를 1 더했기 때문에 신경 안 써도 되고, 열만 신경쓰면 된다.
			continue;

		if (!Solution(Index, j)) // 대각선에 위치한 퀸 찾기 (뭔가 더 좋은 알고리즘이 있을 것 같은데 현재는 생각 못하겠다)
			continue;

		COL[j] = true;
		Queen_Pos.push_back({ Index, j });

		Recursive(Index + 1);

		COL[j] = false;
		Queen_Pos.pop_back(); // 나머지는 전형적인 백트래킹 방식
	}
}

int main()
{
	cin >> N;

	Recursive(0);

	cout << CNT << '\n';
}