#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

long N, B, C;
vector<long> arr;

long cnt = 0;
long temp;
long tmp;
long rst;

void solve()
{
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;
		
		if (arr[i] <= 0)
		{
			continue;
		}

		tmp = arr[i] % C;
		rst = arr[i] / C;
		if (tmp == 0)
			cnt = cnt + rst;
		else
			cnt = cnt + rst + 1;
	}
}

int main()
{
	cin >> N;
	cnt = N;
	for (int i=0; i < N; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	cin >> B >> C;

	solve();

	cout << cnt << endl;
}