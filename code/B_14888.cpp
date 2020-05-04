#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> num;
vector<char> oper;
vector<int> oper_n;
int min_v=1000000000;
int max_v=-1000000000;


int main() {
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;;
		for (int j = 0; j < temp; j++)
		{
			if (i == 0)
				oper.push_back('+');
			else if(i==1)
				oper.push_back('-');
			else if (i == 2)
				oper.push_back('*');
			else if (i == 3)
				oper.push_back('/');
			oper_n.push_back(cnt++);
		}
	}

	int t1 = num[0];
	int t2;
	for (int i = 0; i < oper.size(); i++)
	{
		t2 = num[i + 1];
		if (oper[i] == '+')
			t1 = t1 + t2;
		else if (oper[i] == '-')
			t1 = t1 - t2;
		else if (oper[i] == '*')
			t1 = t1 * t2;
		else if (oper[i] == '/')
			t1 = t1 / t2;
	}

	max_v = max(max_v, t1);
	min_v = min(min_v, t1);


	
	while (next_permutation(oper_n.begin(), oper_n.end()))
	{
		t1 = num[0];
		for (int i = 0; i < oper.size(); i++)
		{
			t2 = num[i + 1];
			if (oper[oper_n[i]] == '+')
				t1 = t1 + t2;
			else if (oper[oper_n[i]] == '-')
				t1 = t1 - t2;
			else if (oper[oper_n[i]] == '*')
				t1 = t1 * t2;
			else if (oper[oper_n[i]] == '/')
				t1 = t1 / t2;
		}
		max_v = max(max_v,t1);
		min_v = min(min_v,t1);
	}

	cout << max_v << "\n" << min_v << "\n";

	return 0;
}