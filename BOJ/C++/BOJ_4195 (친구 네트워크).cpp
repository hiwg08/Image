#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int T, N, CNT = 1, Arr[200001]{ 0 };

map<string, int> CHK;

map<int, int> Child_Num;

int GetParent(int Idx)
{
	if (Arr[Idx] == -1 || Arr[Idx] == Idx)
	{
		if (Arr[Idx] == -1)
			Child_Num[Idx]++;
		return Arr[Idx] = Idx;
	}

	return Arr[Idx] = GetParent(Arr[Idx]);
}

int main()
{
	fastio;

	cin >> T;

	while (T--)
	{
		cin >> N;

		memset(Arr, -1, sizeof(Arr));
		CHK.clear();
		Child_Num.clear();

		cin.ignore(32767, '\n');
		CNT = 1;

		while (N--)
		{
			string S, T1, T2;
			getline(cin, S);
			stringstream ss(S);
			ss >> T1 >> T2;

			if (CHK[T1] == 0)
				CHK[T1] = CNT++;
			if (CHK[T2] == 0)
				CHK[T2] = CNT++;

			int st1 = GetParent(CHK[T1]);
			int st2 = GetParent(CHK[T2]);

			if (st1 < st2)
			{
				Arr[st2] = st1;
				Child_Num[st1] += Child_Num[st2];
				cout << Child_Num[st1] << '\n';
			} // 부모가 서로 다르면 부모가 작은 쪽에 자식들을 합치자. (1)

			else if (st1 > st2)
			{
				Arr[st1] = st2;
				Child_Num[st2] += Child_Num[st1];
				cout << Child_Num[st2] << '\n';
			} // 부모가 서로 다르면 부모가 작은 쪽에 자식들을 합치자. (2)

			else
				cout << Child_Num[st1] << '\n'; // 부모가 같으면 더하는게 아니라, 부모가 갖고 있는 자식들의 수를 그대로 출력한다는 사실을 까마득히 잊고 있었다....
			// 분리 집합을 얼마나 잘 파악하고 이해하느냐에 따른 문제인 것 같다.
		}
	}
}