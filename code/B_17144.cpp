#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int r, c, t;
vector<vector<int>> arr;
vector<int> air;
vector<pair<int, int>> dust;
int dr[4] = {0,-1,0,1};
int dc[4] = { 1,0,-1,0 };

void solution()
{
	vector<vector<int>> tmep2(r, vector<int>(c, 0));
	//spread
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (4<arr[i][j])
			{
				int cnt = 0;
				int t_dust = (arr[i][j] / 5);
				for (int d = 0; d < 4; d++)
				{
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr < r && 0 <= nr && nc < c && 0 <= nc && -1 < arr[nr][nc])
					{	
						tmep2[nr][nc] += t_dust;
						cnt++;
					}
				}
				tmep2[i][j] += (-(t_dust*cnt));
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			arr[i][j] += tmep2[i][j];
		}
	}

	//0 rotate
	int a_rot = air[0];
	for (int i = a_rot-2; 0 <= i; i--)
	{
		arr[i + 1][0] = arr[i][0]; 
		arr[i][0] = 0;
	}
	for (int i = 1; i < c; i++)
	{
		arr[0][i - 1] = arr[0][i];
		arr[0][i] = 0;
	}
	for (int i = 1; i <= a_rot; i++)
	{
		arr[i - 1][c - 1] = arr[i][c - 1];
		arr[i][c - 1] = 0;
	}
	for (int i = c-1;1<i;i--)
	{
		arr[a_rot][i] = arr[a_rot][i - 1];
		arr[a_rot][i - 1] = 0;
	}

	//1 rotate
	int b_rot = air[1];
	for (int i = b_rot+1; i<=r-2; i++)
	{
		arr[i][0] = arr[i + 1][0];
		arr[i + 1][0] = 0;
	}
	for (int i = 0; i < c-1; i++)
	{
		arr[r - 1][i] = arr[r - 1][i + 1];
		arr[r - 1][i + 1] = 0;
		
	}
	for (int i = r - 1; b_rot < i; i--)
	{
		arr[i][c - 1] = arr[i - 1][c - 1];
		arr[i - 1][c - 1] = 0;
	}
	for (int i = c - 1; 1 < i; i--)
	{
		arr[b_rot][i] = arr[b_rot][i - 1];
		arr[b_rot][i - 1] = 0;
	}

	return;
}

int main()
{
	int temp;

	cin >> r >> c >> t;

	arr.assign(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			if (temp == -1)
				air.push_back(i);
			arr[i][j] = temp;
		}
	}

	for (int i = 0; i < t; i++)
	{
		solution();
	}

		

	int sum = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			sum += arr[i][j];
		}
	}

	cout << sum+2 << "\n";
	return 0;
}