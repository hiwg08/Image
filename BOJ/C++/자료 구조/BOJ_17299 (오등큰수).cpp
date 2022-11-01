#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[1000001]{ 0 }, Vis[1000001]{ 0 }, Ans[1000001]{ 0 };

stack<pair<int, int>> S;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Arr[i];
		Vis[Arr[i]]++;
	}

	for (int i = 0; i < N; i++)
	{
		while (!S.empty() && S.top().first < Vis[Arr[i]])
		{
			Ans[S.top().second] = Arr[i];
			S.pop();
		}
		S.push({ Vis[Arr[i]], i });
		Ans[i] = -1;
	}

	for (int i = 0; i < N; i++)
		cout << Ans[i] << " ";
	cout << '\n';
}

// 오큰수 문제랑 동일. 여기는 숫자의 빈도 수에만 차이가 있다.