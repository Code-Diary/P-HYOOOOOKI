#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>

using namespace std;

int arr[20][20];

int N, M;

vector<pair<int, int>> home;

int res_home = 0;

void init()
{
	for (int i = 0; i < 20; i++)
	{
		memset(arr[i], 0, sizeof(int) * 20);
	}
	home.clear();
}

void bfs(int a, int b)
{
	int count = 0;
	int temp_a = a;
	int temp_b = b;
	int home_cnt = 0;
	int result = 0;



	for (int k = 0; k < 30; k++)
	{
		home_cnt = 0;

		int a_to = temp_a - count;
		int a_from = temp_a + count;
		int b_to = temp_b - count;
		int b_from = temp_b + count;

		for (int i = a_to; i <= a_from; i++)
		{
			for (int j = b_to; j <= b_from; j++)
			{
				if (i < 0 || N <= i || j < 0 || N <= j)
				{

				}
				else
				{
					int temp = abs(temp_a - i) + abs(temp_b - j);
					if (temp <= count)
					{
						if (arr[i][j] == 1)
							home_cnt++;
					}
				}
			}
		}
		count++;
		result = (home_cnt*M) - ((count*count) + ((count - 1) * (count - 1)));

		if (0 <= result)
			res_home = home_cnt;
	}
}


int main()
{
	int T;
	int value = 0;
	scanf(" %d", &T);
	for (int t = 0; t < T; t++)
	{
		init();
		value = 1;
		res_home = 1;
		scanf(" %d %d", &N, &M);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %d", &arr[i][j]);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				bfs(i, j);
				value = max(value, res_home);
			}
		}
		printf("#%d %d\n", t + 1, value);
	}
}