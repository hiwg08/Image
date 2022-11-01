#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll N, M, Arr[100001]{ 0 };

vector<pll> Tree;

// 난이도에 비해 정말 쉬웠던 문제

pll Init(ll Node_Num, ll Start, ll End)
{
	if (Start == End)
		return Tree[Node_Num] = { Arr[Start], Start };

	ll L = Node_Num * 2, R = L + 1, Mid = (Start + End) / 2;

	pll A = Init(L, Start, Mid);
	pll B = Init(R, Mid + 1, End);

	if (A.first < B.first)
		Tree[Node_Num] = B;
	else
		Tree[Node_Num] = A;

	return Tree[Node_Num];
}

pll Modify(ll Node_Num, ll Start, ll End, ll Idx, ll Chg)
{
	if (Start > Idx || End < Idx)
		return Tree[Node_Num];

	if (Idx == Start && Idx == End)
		return Tree[Node_Num] = { Chg, Idx };

	ll L = Node_Num * 2, R = L + 1, Mid = (Start + End) / 2;

	pll A = Modify(L, Start, Mid, Idx, Chg);
	pll B = Modify(R, Mid + 1, End, Idx, Chg);

	if (A.first < B.first)
		Tree[Node_Num] = B;
	else
		Tree[Node_Num] = A;

	return Tree[Node_Num];
}

pll Find_Maximum(ll Node_Num, ll Start, ll End, ll Cmd_A, ll Cmd_B)
{
	if (Cmd_A > End || Cmd_B < Start)
		return { -1, -1 };

	if (Cmd_A <= Start && End <= Cmd_B)
		return Tree[Node_Num];

	ll L = Node_Num * 2, R = L + 1, Mid = (Start + End) / 2;

	pll A = Find_Maximum(L, Start, Mid, Cmd_A, Cmd_B);
	pll B = Find_Maximum(R, Mid + 1, End, Cmd_A, Cmd_B);

	if (A.first < B.first)
		return B;
	else
		return A;
}

int main()
{
	fastio;

	cin >> N;

	for (ll i = 0; i < N; i++)
		cin >> Arr[i];

	ll Tree_height = ceil(log2(N));
	Tree.resize(1 << (Tree_height + 1));

	Init(1, 0, N - 1);

	cin >> M;

	for (ll i = 0; i < M; i++)
	{
		ll a, b, c; cin >> a >> b >> c;

		if (a == 2)
		{
			pll Max_Info = Find_Maximum(1, 0, N - 1, b - 1, c - 1);
			pll A = Find_Maximum(1, 0, N - 1, b - 1, Max_Info.second - 1);
			pll B = Find_Maximum(1, 0, N - 1, Max_Info.second + 1, c - 1);
			cout << Max_Info.first + max(A.first, B.first) << '\n';
		}
		else
			Modify(1, 0, N - 1, b - 1, c);
	}
}