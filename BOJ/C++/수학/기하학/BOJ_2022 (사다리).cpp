#include <bits/stdc++.h>

using namespace std;

double x, y, c;

double calc(double mid)
{
	return ((sqrt(x * x - mid * mid) * sqrt(y * y - mid * mid)) / (sqrt(x * x - mid * mid) + sqrt(y * y - mid * mid)));
}

// 피타고라스 정리를 이용한 기하학 문제이지만, 이 문제에서 핵심은 사실 이분 탐색에 있다.
// 우선 뼈대는 기하학이므로 기하학 폴더에 넣었다.
// 어차피 문제에 상대 오차를 허용하기 때문에 상대 오차 수 만큼 이분 탐색을 돌려도 된다. (깨달은 사실) 

int main()
{
	cin >> x >> y >> c;

	double lo = -0.001, hi = x > y ? x + 0.001 : y + 0.001;

	while (lo + 0.001 < hi)
	{
		double mid = (lo + hi) / (double)2;

		calc(mid) >= c ? lo = mid : hi = mid;
	}

	cout.precision(3);

	cout << fixed << lo << '\n';
}