#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

long long T, N, M, Ans;

long long A[1001]{ 0 }, B[1001]{ 0 };

vector<long long> A_SUM, B_SUM;

void Input()
{
	fastio;

	cin >> T;

	cin >> N;
	for (long long i = 0; i < N; i++)
		cin >> A[i];

	cin >> M;
	for (long long i = 0; i < M; i++)
		cin >> B[i];
}

void Prefix_Sum()
{
	for (long long i = 0; i < N; i++)
	{
		long long SUM = 0;
		for (long long j = i; j < N; j++)
		{
			SUM += A[j];
			A_SUM.push_back(SUM);
		}
	} // 최대 1,000,000번

	for (long long i = 0; i < M; i++)
	{
		long long SUM = 0;
		for (long long j = i; j < M; j++)
		{
			SUM += B[j];
			B_SUM.push_back(SUM);
		}
	}  // 최대 1,000,000번
}

int main() // 누적합 + 이분탐색
{
	Input();

	Prefix_Sum();

	sort(A_SUM.begin(), A_SUM.end());
	sort(B_SUM.begin(), B_SUM.end());
	// 최대 2,000,000 * log(1,000,000)번

	long long A_Idx = 0;

	while (A_Idx < (long long)A_SUM.size())
	{
		long long A_Num = (long long)(upper_bound(A_SUM.begin(), A_SUM.end(), A_SUM[A_Idx]) - A_SUM.begin()) - (long long)(lower_bound(A_SUM.begin(), A_SUM.end(), A_SUM[A_Idx]) - A_SUM.begin());

		long long B_Num = (long long)(upper_bound(B_SUM.begin(), B_SUM.end(), T - A_SUM[A_Idx]) - B_SUM.begin()) - (long long)(lower_bound(B_SUM.begin(), B_SUM.end(), T - A_SUM[A_Idx]) - B_SUM.begin());

		// 최대 log(1,000,000)번

		Ans += A_Num * B_Num;

		A_Idx += A_Num;
	}
	// 최대 1,000,000번 --->  1,000,000 * log(1,000,000)

	// --> 무사히 시간 초과 통과.

	cout << Ans << '\n';
}

// 1 1 2 3 3 4 4 5 6 7 (A_SUM)

// 5

// 1 2 3 4 5 6 (B_SUM)

// 1. A_SUM을 0번부터 순차적으로 탐색한다.
// 2. A_SUM 원소의 개수를 이분 탐색으로 구하고 T - (A_SUM의 원소)의 개수를 B_SUM에서 이분 탐색으로 구한 후, 둘을 곱하자.