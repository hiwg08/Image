#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long Total_Pizza, N, M, Ans;

vector<long long> P_A, P_B, SUM_A, SUM_B;

void Prefix_Sum()
{
	for (long long i = 1; i <= M; i++)
		P_A.push_back(P_A[i]);

	for (long long i = 1; i <= N; i++)
		P_B.push_back(P_B[i]);

	long long SUM = 0;

	for (long long i = 1; i < P_A.size(); i++)
	{
		SUM += P_A[i];
		P_A[i] = SUM;
	}

	SUM = 0;

	for (long long i = 1; i < P_B.size(); i++)
	{
		SUM += P_B[i];
		P_B[i] = SUM;
	}
}

void Make_Pizza()
{
	for (long long i = 1; i <= M; i++)
	{
		if (i == M)
		{
			SUM_A.push_back(P_A[M]);
			continue;
		}
		for (int j = 0; j < M; j++)
			SUM_A.push_back(P_A[i + j] - P_A[j]);
	}

	for (long long i = 1; i <= N; i++)
	{
		if (i == N)
		{
			SUM_B.push_back(P_B[N]);
			continue;
		}
		for (int j = 0; j < N; j++)
			SUM_B.push_back(P_B[i + j] - P_B[j]);
	}

	SUM_A.push_back(0);
	SUM_B.push_back(0);
}

void Input()
{
	fastio;

	cin >> Total_Pizza;

	cin >> M >> N;

	P_A.push_back(0);
	P_B.push_back(0);

	for (long long i = 1; i <= M; i++)
	{
		long long a; cin >> a;
		P_A.push_back(a);
	}

	for (long long i = 1; i <= N; i++)
	{
		long long a; cin >> a;
		P_B.push_back(a);
	}
}

int main()
{
	Input();

	Prefix_Sum();

	Make_Pizza();

	sort(SUM_A.begin(), SUM_A.end());
	sort(SUM_B.begin(), SUM_B.end());

	long long A_Idx = 0;

	while (A_Idx < SUM_A.size())
	{
		long long A_Cnt = (long long)(upper_bound(SUM_A.begin(), SUM_A.end(), SUM_A[A_Idx]) - SUM_A.begin())
			- (long long)(lower_bound(SUM_A.begin(), SUM_A.end(), SUM_A[A_Idx]) - SUM_A.begin());
		long long B_Cnt = (long long)(upper_bound(SUM_B.begin(), SUM_B.end(), Total_Pizza - SUM_A[A_Idx])
			- SUM_B.begin()) - (long long)(lower_bound(SUM_B.begin(), SUM_B.end(), Total_Pizza - SUM_A[A_Idx]) - SUM_B.begin());

		Ans += (A_Cnt * B_Cnt);
		A_Idx += A_Cnt;
	}

	cout << Ans << '\n';
}