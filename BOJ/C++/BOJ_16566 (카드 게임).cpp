#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M, K, Arr[4000001]{ 0 }, P[4000001]{ 0 };

vector<int> Ans;

int GetParent(int Idx)
{
	if (P[Idx] == -1)
		return P[Idx] = Idx + 1;
	return P[Idx] = GetParent(P[Idx]);
}

int main()
{
	fastio;

	cin >> N >> M >> K;

	for (int i = 0; i < M; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	memset(P, -1, sizeof(P));

	for (int i = 0; i < K; i++)
	{
		int a; cin >> a;
		int Idx = (int)(upper_bound(Arr, Arr + N, a) - Arr);
		P[Idx] = GetParent(Idx);
		Ans.push_back(Arr[P[Idx] - 1]);
	}

	for (auto e : Ans)
		cout << e << '\n';
}