#include <bits/stdc++.h>

using namespace std;

int N, CHK = -1;

void Recurse(int Cnt, int Pre, string S) // 자릿수를 나타내는 Cnt, 현재 숫자인 Pre, 감소하는 수인 문자열 S
{
	if (Cnt == 0)
	{
		if (++CHK == N) // 사용자가 입력한 번째의 수를 출력한 후 바로 프로그램 종료.
		{
			cout << S << '\n';
			exit(0);
		}
		return;
	}

	if (Pre == -1)
		return; // 감소시켰던 수가 음수면 성립되지 않으므로 리턴

	for (int i = 0; i <= Pre; i++) // for문은 0부터 시작해야한다. 그래야 감소하는 수의 순서를 지킬 수 있다. ex. 10 -> "20" -> 21 -> "30" -> 31 -> 32 -> ...
		Recurse(Cnt - 1, i - 1, S + to_string(i)); // 현재 있는 수(i) + 앞으로 감소할 수 (i - 1)
}

int main()
{
	cin >> N;

	for (int i = 1; i <= 10; i++)
		Recurse(i, 9, ""); // 10개의 자릿수만큼 반복

	cout << -1 << '\n'; // 1024 이상(<= 1,000,000)의 수들은 모두 -1 출력.
}