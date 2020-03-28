#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

vector<int> pi;
vector<int> ans;

void getpi(const string &p)
{
	int m = p.size();
	pi.assign(m, 0);
	int j = 0;

	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];

		if (p[i] == p[j])
			pi[i] = ++j;
	}
}

void smp(const string &s, const string &p)
{
	int n = s.size();
	int m = p.size();
	int j = 0;

	for (int i = 0; i < n; i++)
	{
		while ( j > 0 && s[i] != p[j])
			j = pi[j - 1];

		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 2);
				j = pi[j];
			}
			else
				++j;
		}


	}
}

int main()
{
	string s, p;

	getline(cin, s);
	getline(cin, p);
	

	getpi(p);
	smp(s, p);


	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;

}