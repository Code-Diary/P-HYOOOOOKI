#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int n, w, h;
int arr[16][13];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void restruct() //재구조화
{
	int a = 0;
	int val = 0;
	for (int i = 0; i < w; i++)
	{
		a = 0;
		for (int j = h - 1; 0 <= j; j--)
		{
			val = arr[j][i];
			arr[j][i] = 0;
			if (val != 0)
			{
				a++;
				arr[h - a][i] = val;
			}
		}
	}
}

void dfs(int x,int y) //제거
{
	int temp = arr[x][y];
	arr[x][y] = 0;

	for (int i = 1; i < temp; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int temp_x = x + (dx[j] * i);
			int temp_y = y + (dy[j] * i);
			if (temp_x < h && 0 <= temp_x && temp_y < w && 0 <= temp_y && arr[temp_x][temp_y] != 0)
			{
				dfs(temp_x, temp_y);
			}
		}
	}
}

void init()
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			arr[i][j] = 0;
		}
	}
}

int count()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (arr[i][j] != 0)
				cnt++;
		}
	}
	return cnt;
}

void print_arr()
{
	printf("\n");
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int solve(int n)
{
	if (n == 0)
	{
		return count();
	}
		
	int value = 0;
	int min_v = 1000;
	int o_arr[16][13] = { 0, };

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			o_arr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (arr[j][i] != 0)
			{
				dfs(j, i);
				restruct();
				//print_arr();
				if (count() == 0)
					return 0;
				value = solve(n - 1);

				for (int a = 0; a < h; a++)
				{
					for (int b = 0; b < w; b++)
					{
						arr[a][b] = o_arr[a][b];
					}
				}
				if (value < min_v)
					min_v = value;
					
				break;
			}
		}
	}
	return min_v;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d %d %d", &n, &w, &h);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf(" %d", &arr[i][j]);
			}
		}
		printf("#%d %d\n", t + 1, solve(n));
	}
	return 0;
}