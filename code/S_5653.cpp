#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct cell
{
	int x;
	int y;
	int num;
	int live;
	int wait;
	bool check;
};

int N, M, K;
cell arr[660][660];
cell t_arr[660][660];

void init()
{
	N = 0;
	M = 0;
	K = 0;
	memcpy(arr, t_arr, sizeof(t_arr));
}

int solve()
{
	for (int k = 0; k < K; k++)
	{
		for (int i = 305 - k; i < 305 + N + k; i++)
		{
			for (int j = 305 - k; j < 305 + M + k; j++)
			{
				if (arr[i][j].num != 0 && arr[i][j].check == true && arr[i][j].live != 0)
				{
					if (0 < arr[i][j].wait)
					{
						arr[i][j].wait--;
					}
					else if (arr[i][j].wait == 0)
					{
						if (0 < arr[i][j].live)
						{
							for (int d = 0; d < 4; d++)
							{
								if (arr[i + dx[d]][j + dy[d]].num == 0)
								{
									arr[i + dx[d]][j + dy[d]] = { i + dx[d],j + dy[d],arr[i][j].num,arr[i][j].num,arr[i][j].num,false };
								}
								else
								{
									if (arr[i+dx[d]][j+dy[d]].check == false && arr[i + dx[d]][j + dy[d]].num < arr[i][j].num)
									{
										arr[i + dx[d]][j + dy[d]] = { i + dx[d],j + dy[d],arr[i][j].num,arr[i][j].num,arr[i][j].num,false };
									}
								}
							}
							arr[i][j].live--;
						}
					}
				}
			}
		}

		for (int i = 304 - k; i < 306 + N + k; i++)
		{
			for (int j = 304 - k; j < 306 + M + k; j++)
			{
				if (arr[i][j].check == false && arr[i][j].num !=0)
					arr[i][j].check = true;
			}
		}
			
	}
	int cnt = 0;
	for (int i = 0; i < 660; i++)
	{
		for (int j = 0; j < 660; j++)
		{
			if (arr[i][j].num != 0 &&arr[i][j].live != 0)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	int T;
	int rst;
	int temp;
	
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d %d %d", &N, &M, &K);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				scanf(" %d", &temp);
				arr[i + 305][j + 305] = { i + 305,j + 305,temp,temp,temp,true };
			}
		rst = solve();

		printf("#%d %d\n", t + 1, rst);
		
	}
}