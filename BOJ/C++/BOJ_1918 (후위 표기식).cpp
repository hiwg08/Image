#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

class Moss_Info
{
public:
	char c;
	int First, Origin;
	Moss_Info(char _c, int _First, int _Origin)
		:c(_c), First(_First), Origin(_Origin)
	{}
};

string S;

string Ans = "";

stack<Moss_Info> Q;

map<int, pair<int, int>> CHK;

bool cmp(int a, int b, int c, int d)
{
	if (a == c)
		return b >= d;
	return a > c;
}

int main()
{
	fastio;

	cin >> S;

	int Cnt = 0;

	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(')
			Cnt++;
		else if (S[i] == ')')
			Cnt--;

		if (S[i] == '+' || S[i] == '-')
			CHK[i] = { Cnt, 1 };
		else if (S[i] == '*' || S[i] == '/')
			CHK[i] = { Cnt, 2 };
	}


	for (int i = 0; i < S.size(); i++)
	{
		if (S[i] == '(' || S[i] == ')')
			continue;

		if (S[i] >= 'A' && S[i] <= 'Z')
			Ans += S[i];

		else
		{
			while (!Q.empty() && cmp(Q.top().First, Q.top().Origin, CHK[i].first, CHK[i].second))
			{
				Moss_Info MI = Q.top();
				Q.pop();

				Ans += MI.c;
			}
			Q.push(Moss_Info(S[i], CHK[i].first, CHK[i].second));
		}
	}

	while (!Q.empty())
	{
		Moss_Info MI = Q.top();
		Q.pop();

		Ans += MI.c;
	}

	cout << Ans << '\n';
}