#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int N;
vector<vector<int>> arr;
int max_v = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void solve(int cnt,int d, vector < vector <int> > &v)
{
	
	vector<vector<int>> t_arr(N,vector<int>(N,0));
	t_arr = v;


	if (5 < cnt)
		return;

	if (d == 5)
	{
		solve(1, 0,t_arr);
		solve(1, 1, t_arr);
		solve(1, 2, t_arr);
		solve(1, 3, t_arr);
		return;
	}

	if(d==0 || d==3)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (t_arr[i][j] == 0)
					continue;

				int n_x = i + dx[d];
				int n_y = j + dy[d];
				int temp = t_arr[i][j];

				while (0 <= n_x && n_x < N && 0 <= n_y && n_y < N && t_arr[n_x][n_y] == 0)
				{
					t_arr[n_x][n_y] = temp;
					t_arr[n_x-dx[d]][n_y-dy[d]] = 0;
					n_x = n_x + dx[d];
					n_y = n_y + dy[d];
				}
			}
		}
	else
		for (int i = N-1; 0<=i; i--)
		{
			for (int j = N-1; 0<=j ; j--)
			{
				if (t_arr[i][j] == 0)
					continue;
				int n_x = i + dx[d];
				int n_y = j + dy[d];
				int temp = t_arr[i][j];

				while (0 <= n_x && n_x < N && 0<=n_y && n_y <N && t_arr[n_x][n_y] == 0)
				{
					t_arr[n_x][n_y] = temp;
					t_arr[n_x - dx[d]][n_y - dy[d]] = 0;
					n_x = n_x + dx[d];
					n_y = n_y + dy[d];
				}
			}
		}
	
	if(d==0)
		for (int i = 0; i < N-1; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (t_arr[i][j] == t_arr[i + 1][j])
				{
					t_arr[i][j] = t_arr[i][j] * 2;
					t_arr[i + 1][j] = 0;
				}	
			}
		}
	else if(d==3)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N-1; j++)
			{
				if (t_arr[i][j] == t_arr[i][j+1])
				{
					t_arr[i][j] = t_arr[i][j] * 2;
					t_arr[i][j+1] = 0;
				}
			}
		}
	else if (d == 1)
		for (int i = N - 1; 0 <= i; i--)
		{
			for (int j = N - 1; 1 <= j; j--)
			{
				if (t_arr[i][j] == t_arr[i][j-1])
				{
					t_arr[i][j] = t_arr[i][j] * 2;
					t_arr[i][j-1] = 0;
				}
			}
		}
	else if(d==2)
		for (int i = N - 1; 1 <= i; i--)
		{
			for (int j = N - 1; 0 <= j; j--)
			{
				if (t_arr[i][j] == t_arr[i - 1][j])
				{
					t_arr[i][j] = t_arr[i][j] * 2;
					t_arr[i - 1][j] = 0;
				}
			}
		}

	if (d == 0 || d == 3)
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (t_arr[i][j] == 0)
					continue;

				int n_x = i + dx[d];
				int n_y = j + dy[d];
				int temp = t_arr[i][j];

				while (0 <= n_x && n_x < N && 0 <= n_y && n_y < N && t_arr[n_x][n_y] == 0)
				{
					t_arr[n_x][n_y] = temp;
					t_arr[n_x - dx[d]][n_y - dy[d]] = 0;
					n_x = n_x + dx[d];
					n_y = n_y + dy[d];
				}
			}
		}
	else
		for (int i = N - 1; 0 <= i; i--)
		{
			for (int j = N - 1; 0 <= j; j--)
			{
				if (t_arr[i][j] == 0)
					continue;
				int n_x = i + dx[d];
				int n_y = j + dy[d];
				int temp = t_arr[i][j];

				while (0 <= n_x && n_x < N && 0 <= n_y && n_y < N && t_arr[n_x][n_y] == 0)
				{
					t_arr[n_x][n_y] = temp;
					t_arr[n_x - dx[d]][n_y - dy[d]] = 0;
					n_x = n_x + dx[d];
					n_y = n_y + dy[d];
				}
			}
		}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			max_v = max(max_v, t_arr[i][j]);
		}
	}

	solve(cnt + 1, 0, t_arr);
	solve(cnt + 1, 1, t_arr);
	solve(cnt + 1, 2, t_arr);
	solve(cnt + 1, 3, t_arr);

	return;
}

int main()
{
	scanf("%d", &N);

	arr.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf(" %d", &arr[i][j]);
		}
	}
	solve(0, 5, arr);

	printf("%d\n", max_v);
}