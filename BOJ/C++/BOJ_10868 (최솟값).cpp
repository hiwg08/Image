#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, M;

int Arr[100001]{ 0 };

vector<int> Tree;

int Tree_Init(int Tree_Node, int Start, int End)
{
	if (Start == End)
		return Tree[Tree_Node] = Arr[Start];

	int L = Tree_Node * 2, R = L + 1, Mid = (Start + End) / 2;

	return Tree[Tree_Node] = min(Tree_Init(L, Start, Mid), Tree_Init(R, Mid + 1, End));
}

int Search_Minimum(int Tree_Node, int Start, int End, int Cmd_a, int Cmd_b)
{
	if (End < Cmd_a || Start > Cmd_b)
		return INT_MAX;

	if (Cmd_a <= Start && End <= Cmd_b)
		return Tree[Tree_Node];

	int L = Tree_Node * 2, R = L + 1, Mid = (Start + End) / 2;

	return min(Search_Minimum(L, Start, Mid, Cmd_a, Cmd_b), Search_Minimum(R, Mid + 1, End, Cmd_a, Cmd_b));
}

int main()
{
	fastio;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	int height = ceil(log2(N));

	Tree.resize(1 << (height + 1));

	Tree_Init(1, 0, N - 1);

	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		cout << Search_Minimum(1, 0, N - 1, a - 1, b - 1) << '\n';
	}
}