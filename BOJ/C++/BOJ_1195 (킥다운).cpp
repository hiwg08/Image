#include <bits/stdc++.h>

using namespace std;

string L, R;

int MIN;

int main()
{
	cin >> L >> R;

	if ((int)L.size() < (int)R.size())
		swap(L, R);

	MIN = (int)L.size() + (int)R.size();

	for (int i = -(int)R.size() + 1; i <= (int)L.size() - 1; i++)
	{
		bool CHK = true;
		int Interval = 0;

		for (int j = 0; j < (int)R.size(); j++)
		{
			if (i + j < 0 || i + j >= (int)L.size())
				continue;

			if ((L[i + j] == '1' && R[j] == '2') || (L[i + j] == '2' && R[j] == '1') || (L[i + j] == '1' && R[j] == '1'))
				Interval++;
			else
			{
				CHK = false;
				break;
			}
		}

		if (CHK) MIN = min(MIN, (int)L.size() + (int)R.size() - Interval);
	}

	cout << MIN << '\n';
}