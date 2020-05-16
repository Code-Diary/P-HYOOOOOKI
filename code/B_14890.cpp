#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int n, l;
int o_arr[100][100];
int t_arr[100][100];

void rotate()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			t_arr[n-j-1][i] = o_arr[i][j];
		}
	}
}

int solution(int arr[][100])
{
	int cnt = 0;
	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = arr[i][0];
		int same = 1;
		for (int j = 1; j < n; j++)
		{
			if (temp != arr[i][j])
			{
				if (1 < abs(temp - arr[i][j]))
					break;
				else if (1 == abs(temp - arr[i][j]))
				{
					if (temp < arr[i][j])
					{
						if (l <= same)
						{
							temp = arr[i][j];
							same = 1;
						}
						else
						{
							break;
						}
					}
					else
					{
						int temp_val = arr[i][j];
						bool chk = false;
						for (int k = 0; k < l; k++)
						{
							if (j + k < n && temp_val == arr[i][j+k])
							{
								chk = true;
								continue;
							}
							else
							{
								chk = false;
								break;
							}
						}
						if (chk == false)
							break;
						j = j + l-1;
						temp = arr[i][j];
						same = 0;
					}
				}
			}
			else
			{
				temp = arr[i][j];
				same++;
			}
			if (j == n - 1)
			{
				//cout << "ori" << i << endl;
				cnt++;
			}
				
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> o_arr[i][j];
		}
	}

	int rst1 = solution(o_arr);
	rotate();
	int rst2 = solution(t_arr);

	cout << rst1+rst2 << endl;
	return 0;
}