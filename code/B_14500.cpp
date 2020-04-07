#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int n, m;

int arr[500][500] = { 0, };
int fig_x[7][4] = {
	{ 0,0,0,0 },
	{ 0,0,1,1 },
	{ 0,1,2,2 },
	{ 0,1,1,2 },
	{ 0,0,0,1 },
	{0,1,2,2 },
	{0,1,1,2}
};
int fig_y[7][4] = {
	{ 0,1,2,3 },
	{ 0,1,0,1 },
	{ 0,0,0,1 },
	{ 0,0,1,1 },
	{ 0,1,2,1 },
{0,0,0,-1},
{0,0,-1,-1}
};

int max_v = 0;

bool check(int x, int y)
{
	if (n <= x || x < 0 || m <= y || y < 0)
		return false;
	return true;
}

void rotate()
{
	int t_n = n;
	int t_m = m;
	n = m;
	m = t_n;

	vector<vector<int>> t_arr(t_m, vector<int>(t_n, 0));

	for (int i = 0; i < t_n; i++)
	{
		for (int j = 0; j < t_m; j++)
		{
			t_arr[j][t_n-i-1] = arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = t_arr[i][j];
		}
	}
}

void search(int arr[][500])
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				temp = 0;
				for (int f = 0; f < 4; f++)
				{
					if (check(i + fig_x[k][f], j + fig_y[k][f]))
					{
						temp += arr[i + fig_x[k][f]][j + fig_y[k][f]];
					}
					else
					{
						break;
					}
					
					if (f == 3)
					{
						max_v = max(max_v, temp);
					}
				}
			}
		}
	}
}

void print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		search(arr);
		if (i == 3)
			break;
		rotate();
		//print();

	}

	cout << max_v << "\n";
	return 0;
	
}