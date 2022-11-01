#include <bits/stdc++.h>

using namespace std;

string S, P;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	cin >> P;

	string temp = "";

	for (int i = 0; i < S.size(); i++)
	{
		if (temp.size() >= P.size())
		{
			if (temp.substr(temp.size() - P.size()) == P)
			{
				int P_S = P.size();
				while (P_S > 0)
				{
					P_S--;
					temp.pop_back();
				}
			}
		}
		temp += S[i];
	}

	if (temp.find(P) != string::npos)
		temp = temp.substr(0, temp.find(P));

	if (temp.size() == 0)
		cout << "FRULA" << '\n';
	else
		cout << temp << '\n';
}