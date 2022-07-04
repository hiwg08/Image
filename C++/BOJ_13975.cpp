#include <bits/stdc++.h>

using namespace std;

int T, N;

long long I1, Result, S1, S2;


int main() // 그리디 + 우선순위 큐 (문제 설명에 나온 최적 풀이 방법(70 + 80 + 150 = 300)에 낚이지 말자)
{		   // 허프만 인코딩 기법이라고도 한다.
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		Result = 0;
		priority_queue<long long, vector<long long>, greater<long long>> seq;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> I1;
			seq.push(I1);
		}

		while (!seq.empty())
		{
			S1 = seq.top();
			seq.pop();

			if (seq.empty())
				break;

			S2 = seq.top();
			seq.pop();

			seq.push(S1 + S2);
			Result += (S1 + S2);
		}
		cout << Result << '\n';
	}
}