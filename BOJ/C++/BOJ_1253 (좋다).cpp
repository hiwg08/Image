#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int N, Arr[2001]{ 0 }, Ans;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> Arr[i];

	sort(Arr, Arr + N);

	for (int i = 0; i < N; i++)
	{
		int Start = 0, End = N - 1;

		while (Start < End)
		{
			if (Start == i)
			{
				Start++;
				continue;
			}
			if (End == i)
			{
				End--;
				continue;
			}

			if (Arr[Start] + Arr[End] < Arr[i])
				Start++;
			else if (Arr[Start] + Arr[End] > Arr[i])
				End--;
			else
			{
				Ans++;
				break;
			}
		}
	}

	cout << Ans << '\n';
}