#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pii pair<int, int>

using namespace std;

int N, Interval, MAX = INT_MIN;

vector<pii> V;

struct cmp
{
	bool operator() (pii a, pii b)
	{
		return a.first > b.first;
	}
};

bool cmp_f(pii a, pii b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

priority_queue<pii, vector<pii>, cmp> PQ;

// 끝 점을 기준으로 정렬
// 현재 위치를 기준으로 철로를 벗어나는 곳은 전부 제거 + 철로 포함 (스위핑)

int main()
{
	fastio;

	cin >> N;

	for (int i = 0, a, b; i < N; i++)
	{
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		V.push_back({ a, b });
	}

	cin >> Interval;

	sort(V.begin(), V.end(), cmp_f);

	for (int i = 0; i < (int)V.size(); i++)
	{
		int Start = V[i].second - Interval;

		while (!PQ.empty() && Start > PQ.top().first)
			PQ.pop();

		if (Start <= V[i].first)
			PQ.push({ V[i].first, V[i].second });

		MAX = max(MAX, (int)PQ.size());
	}

	cout << MAX << '\n';
}