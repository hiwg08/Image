#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

priority_queue<int> Middle_PQ;

priority_queue<int, vector<int>, greater<int>> Another_PQ;

int N;

int main()
{
	fastio;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a; cin >> a;
		if ((Middle_PQ.size() + Another_PQ.size()) % 2 == 0)
		{
			if (Middle_PQ.size() == 0)
				Middle_PQ.push(a);
			else
			{
				if (!Another_PQ.empty() && Another_PQ.top() <= a)
				{
					Middle_PQ.push(Another_PQ.top());
					Another_PQ.pop();
					Another_PQ.push(a);
				}
				else if (!Middle_PQ.empty() && !Another_PQ.empty() && (Middle_PQ.top() <= a && Another_PQ.top() > a))
					Middle_PQ.push(a);
				else if (!Middle_PQ.empty() && Middle_PQ.top() > a)
					Middle_PQ.push(a);
			}
		}
		else
		{
			if (!Another_PQ.empty() && Another_PQ.top() <= a)
				Another_PQ.push(a);
			else if (!Middle_PQ.empty() && !Another_PQ.empty() && (Middle_PQ.top() <= a && Another_PQ.top() > a))
				Another_PQ.push(a);
			else if (!Middle_PQ.empty())
			{
				if (Middle_PQ.top() > a)
				{
					Another_PQ.push(Middle_PQ.top());
					Middle_PQ.pop();
					Middle_PQ.push(a);
				}
				else
					Another_PQ.push(a);
			}
		}
		cout << Middle_PQ.top() << '\n';
	}
}