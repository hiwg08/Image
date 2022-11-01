#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[100001]{ 0 }, Cnt = 1;

stack<int> S;

vector<char> Ans;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	for (int i = 0; i < N; i++)
	{
		if (S.empty())
		{
			S.push(Cnt++);
			Ans.push_back('+');
		}

		if (S.top() > Arr[i])
		{
			cout << "NO" << '\n';
			exit(0);
		}

		while (Arr[i] != S.top())
		{
			S.push(Cnt++);
			Ans.push_back('+');
		}
		S.pop();
		Ans.push_back('-');
	}

	for (auto e : Ans)
		cout << e << '\n';
}