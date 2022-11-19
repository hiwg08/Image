#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N;

string S;

vector<int> V;

// kmp의 실패 테이블을 묻는 문제.

void make_table()
{
	for (int i = 0, j = -1; i <= N; i++, j++)
	{
		V[i] = j;

		while ((j >= 0) && (S[i] != S[j]))
			j = V[j];
	}
}

int main()
{
	fastio;

	cin >> N >> S;

	V.resize(N + 1);

	make_table();

	cout << N - V[N] << '\n';
}