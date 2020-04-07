#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n;
pair<int, int> arr[15];
int max_v = 0;

void solution(int start,int num)
{
	int next = 0;
	int money = num;
	int t_money = 0;
	int i = start;

	while(i<n)
	{
		if (arr[i].first == 1)
		{
			next = i + 1;
		}
		else
		{
			next = arr[i].first + i;
		}		
		
		if (next <= n)
		{
			money += arr[i].second;
		}
		for (int j = next + 1; j < n; j++)
			solution(j, money);

		i = next;
		
		max_v = max(max_v, money);
	}
	max_v = max(max_v, money);
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n;
	

	for (int i = 0; i < n; i++)
	{	
		int t1, t2;
		cin >> t1 >> t2;
		arr[i] = make_pair(t1, t2);
	}

	for (int i = 0; i < n; i++)
	{
		solution(i, 0);
	}

	cout << max_v << "\n";


	return 0;
}