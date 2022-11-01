#include <bits/stdc++.h>

using namespace std;

int N;

vector<pair<int, int>> Lecture;

priority_queue<int, vector<int>, greater<int>> Q;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		Lecture.push_back({ a, b });
	}

	sort(Lecture.begin(), Lecture.end());

	for (auto e : Lecture)
	{
		if (!Q.empty() && Q.top() <= e.first)
			Q.pop();
		Q.push(e.second);
	}

	cout << Q.size() << '\n';
}