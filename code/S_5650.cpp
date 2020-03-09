#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int arr[100][100];
int N;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int i_x;
int i_y;
int cnt=0;
int c_x;
int c_y;
int c_d;
int t_cnt;

vector<pair<int, int>> hall6;
vector<pair<int, int>> hall7;
vector<pair<int, int>> hall8;
vector<pair<int, int>> hall9;
vector<pair<int, int>> hall10;

void init()
{
	hall6.clear();
	hall7.clear();
	hall8.clear();
	hall9.clear();
	hall10.clear();
	i_x = 0;
	i_y = 0;
	cnt = 0;
	c_x = 0;
	c_y = 0;
	c_d = 0;
	t_cnt = 0;
}

bool check(int x,int y)
{
	if (0 <= x && x < N && 0 <= y && y < N)
		return true;
	return false;
}

int touching(int num, int d)
{
	if (num == 1)
	{
		if (d == 0)
			return 2;
		else if (d == 1)
			return 3;
		else if (d == 2)
			return 1;
		else if (d == 3)
			return 0;
	}
	else if (num == 2)
	{
		if (d == 0)
			return 1;
		else if (d == 1)
			return 3;
		else if (d == 2)
			return 0;
		else if (d == 3)
			return 2;
	}
	else if (num == 3)
	{
		if (d == 0)
			return 3;
		else if (d == 1)
			return 2;
		else if (d == 2)
			return 0;
		else if (d == 3)
			return 1;
	}
	else if (num == 4)
	{
		if (d == 0)
			return 2;
		else if (d == 1)
			return 0;
		else if (d == 2)
			return 3;
		else if (d == 3)
			return 1;
	}
	else if (num == 5)
	{
		if (d == 0)
			return 2;
		else if (d == 1)
			return 3;
		else if (d == 2)
			return 0;
		else if (d == 3)
			return 1;
	}
}

int warmhall(int n,int x,int y)
{
	if (n == 6)
	{
		for (int i = 0; i < hall6.size(); i++)
		{
			if (hall6[i].first != x || hall6[i].second != y)
				return i;
		}
	}
	else if (n == 7)
	{
		for (int i = 0; i < hall7.size(); i++)
		{
			if (hall7[i].first != x || hall7[i].second != y)
				return i;
		}
	}
	else if (n == 8)
	{
		for (int i = 0; i < hall8.size(); i++)
		{
			if (hall8[i].first != x || hall8[i].second != y)
				return i;
		}
	}
	else if (n == 9)
	{
		for (int i = 0; i < hall9.size(); i++)
		{
			if (hall9[i].first != x || hall9[i].second != y)
				return i;
		}
	}
	else if (n == 10)
	{
		for (int i = 0; i < hall10.size(); i++)
		{
			if (hall10[i].first != x || hall10[i].second != y)
				return i;
		}
	}
}


int tracking(int x, int y,int d)
{
	c_x = x;
	c_y = y;
	c_d = d;
	t_cnt = 0;
	
	while (1)
	{
		if (c_x == i_x && c_y == i_y)
			return t_cnt;
		
		if (check(c_x, c_y))
		{
			if (arr[c_x][c_y] == 0)
			{
				c_x = c_x + dx[c_d];
				c_y = c_y + dy[c_d];
				continue;
			}
			else if (arr[c_x][c_y] <= 5 && 1 <= arr[c_x][c_y])
			{
				c_d = touching(arr[c_x][c_y], c_d);
				c_x = c_x + dx[c_d];
				c_y = c_y + dy[c_d];
				t_cnt++;
				continue;
			}
			else if (6 <= arr[c_x][c_y])
			{
				int num = arr[c_x][c_y];
				int k;
				if (num == 6)
				{
					k = warmhall(num, c_x, c_y);
					c_x = hall6[k].first + dx[c_d];
					c_y = hall6[k].second + dy[c_d];
				}
				else if (num == 7)
				{
					k = warmhall(num, c_x, c_y);
					c_x = hall7[k].first + dx[c_d];
					c_y = hall7[k].second + dy[c_d];
				}
				else if (num == 8)
				{
					k = warmhall(num, c_x, c_y);
					c_x = hall8[k].first + dx[c_d];
					c_y = hall8[k].second + dy[c_d];
				}
				else if (num == 9)
				{
					k = warmhall(num, c_x, c_y);
					c_x = hall9[k].first + dx[c_d];
					c_y = hall9[k].second + dy[c_d];
				}
				else if (num == 10)
				{
					k = warmhall(num, c_x, c_y);
					c_x = hall10[k].first + dx[c_d];
					c_y = hall10[k].second + dy[c_d];
				}
				continue;
			}
			else if (arr[c_x][c_y] == -1)
				return t_cnt;
		}
		else if (check(c_x, c_y) == false)
		{
			c_d = touching(5, c_d);
			c_x = c_x + dx[c_d];
			c_y = c_y + dy[c_d];
			t_cnt++;
			continue;
		}
	}
}

void solve()
{
	int t_x;
	int t_y;

	for (int d = 0; d < 4; d++)
	{
		t_x = i_x + dx[d];
		t_y = i_y + dy[d];
		
		cnt = max(cnt,tracking(t_x,t_y,d));
			
		

	}
}


int main()
{
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d",&N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %d", &arr[i][j]);
				if (arr[i][j] == 6)
					hall6.push_back(make_pair(i, j));
				else if (arr[i][j] == 7)
					hall7.push_back(make_pair(i, j));
				else if (arr[i][j] == 8)
					hall8.push_back(make_pair(i, j));
				else if (arr[i][j] == 9)
					hall9.push_back(make_pair(i, j));
				else if (arr[i][j] == 10)
					hall10.push_back(make_pair(i, j));

			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != 0)
					continue;
				i_x = i;
				i_y = j;
				solve();
			}
		}

		printf("#%d %d\n", t + 1, cnt);

	}
}