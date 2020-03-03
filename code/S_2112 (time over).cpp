#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string.h>
#include<queue>
#include<utility>

using namespace std;
int min_v = 10000;
int chk_r = 0;

int D, W, K;

bool solve(int(*arr)[20]);

void copy_arr(int(*arr)[20], int(*t_arr)[20])
{
	for (int i = 0; i < D; i++)
	{
		for (int j = 0; j < W; j++)
		{
			t_arr[i][j] = arr[i][j];
		}
	}
}

int revise(int(*arr)[20], int cnt, int start, int depth)
{
	int count = cnt;
	int a_arr[13][20] = { 0, };
	int tmp[20] = { 0, };
	copy_arr(arr, a_arr);

	for (int i = start; i < D; i++)
	{
		for (int j = 0; j < W; j++)
		{
			tmp[j] = a_arr[i][j];
			a_arr[i][j] = 0;
		}
		if (solve(a_arr))
		{
			if (count < min_v)
			{
				min_v = count;
			}
			chk_r = 1;
			return min_v;
		}
		if (count < depth)
		{
			revise(a_arr, count + 1, i + 1, depth);
		}
		for (int j = 0; j < W; j++)
		{
			a_arr[i][j] = tmp[j];
		}
		for (int j = 0; j < W; j++)
		{
			a_arr[i][j] = 1;
		}
		if (solve(a_arr))
		{
			if (count < min_v)
			{
				min_v = count;
			}
			chk_r = 1;
			return min_v;
		}
		if (count < depth)
		{
			revise(a_arr, count + 1, i + 1, depth);
		}
		for (int j = 0; j < W; j++)
		{
			a_arr[i][j] = tmp[j];
		}

	}
	return min_v;
}


bool solve(int(*arr)[20])
{
	int temp = 5;
	int cnt = 0;
	bool check = true;
	int rst[21] = { 0, };

	for (int j = 0; j < W; j++)
	{
		cnt = 0;
		for (int i = 0; i < D; i++)
		{
			if (i == 0)
				cnt++;
			else if (temp == arr[i][j])
			{
				cnt++;
			}
			else if (temp != arr[i][j])
			{
				cnt = 1;
			}
			temp = arr[i][j];

			if (K <= cnt)
			{
				rst[j] = 1;
				break;
			}
		}

	}
	for (int i = 0; i < W; i++)
	{
		if (rst[i] != 1)
			check = false;
	}
	return check;
}

int main()
{
	int T;
	int r = 0;
	int arr[13][20] = { 0, };
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		r = 0;
		min_v = 10000;
		scanf(" %d %d %d", &D, &W, &K);

		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
				scanf(" %d", &arr[i][j]);
		}

		if (solve(arr))
		{
			printf("#%d %d\n", t + 1, 0);
		}
		else
		{
			for (int k = 1; k <= D; k++)
			{
				r = revise(arr, 1, 0, k);
				if (chk_r == 1)
				{
					chk_r = 0;
					break;
				}
			}
			printf("#%d %d\n", t + 1, r);
		}
	}
}