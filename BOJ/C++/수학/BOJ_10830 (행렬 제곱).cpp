#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MOD 1000

using namespace std;

long long N, B;

vector<vector<long long>> Matrix;

vector<vector<long long>> MUL(vector<vector<long long>> Params1, vector<vector<long long>> Params2)
{
	vector<vector<long long>> temp;
	temp.resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long SUM = 0;
			for (int k = 0; k < N; k++)
				SUM += (Params1[i][k] * Params2[k][j]) % MOD;
			temp[i].push_back(SUM % MOD);
		}
	}
	return temp;
}

vector<vector<long long>> Solve(vector<vector<long long>> Matrix, long long B)
{
	if (B == 1)
		return Matrix;

	vector<vector<long long>> temp = Solve(Matrix, B / 2);

	vector<vector<long long>> Ans = MUL(temp, temp);

	if (B % 2 != 0)
		Ans = MUL(Ans, Matrix);

	return Ans;
}

int main()
{
	fastio;

	cin >> N >> B;

	Matrix.resize(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			long long a; cin >> a;
			Matrix[i].push_back(a % MOD);
		}
	}

	vector<vector<long long>> Ans = Solve(Matrix, B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Ans[i][j] << " ";
		cout << '\n';
	}
}