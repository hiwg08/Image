#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, R, Ans = INT_MAX;

bool Vis[10]{ 0 };

int Arr[10]{ 0 };

int CHK = 0;

vector<char> Select_Button;

void Recurse(int Idx) // 중복순열 백트래킹
{
	if (Idx == R)
	{
		string S = "";

		for (int i = 0; i < Idx; i++)
			S += Select_Button[Arr[i]];

		if (S.size() >= 2 && S[0] == '0')
			return;

		Ans = min(Ans, abs(stoi(S) - N) + Idx);

		return;
	}
	for (int i = 0; i < (int)Select_Button.size(); i++)
	{
		Arr[Idx] = i;
		Recurse(Idx + 1);
		Arr[Idx] = 0;
	}
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a; cin >> a;
		Vis[a] = true;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!Vis[i])
			Select_Button.push_back(i + '0');
	}

	for (int i = 1; i <= 6; i++)
	{
		memset(Arr, 0, sizeof(Arr));
		R = i;
		Recurse(0);
	}

	cout << min(Ans, abs(100 - N)) << '\n'; // 멍청하게 모든 숫자버튼이 싹 다 고장 났을 때를 생각 못 했다...ㅎㅎ
}