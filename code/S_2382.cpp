#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, K, M;


typedef struct bug
{
	int b;
	int d;
}Bug;

int di[5] = { 0,-1,1,0,0 };
int dj[5] = { 0,0,0,-1,1 };

vector<vector<Bug>> arr;
vector<vector<Bug>> t_arr;
vector<vector<Bug>> t2_arr;

void solve()
{
	t_arr.clear();
	t_arr.assign(N, vector<Bug>(N, { 0, 0 }));
	t2_arr.clear();
	t2_arr.assign(N, vector<Bug>(N, { 0, 0 }));


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j].b != 0)
			{
				int ti = i + di[arr[i][j].d];
				int tj = j + dj[arr[i][j].d];
				int tb = arr[i][j].b;
				int td = arr[i][j].d;
					
				if (t_arr[ti][tj].b == 0)
				{
					if (ti == 0 || ti == N-1 || tj == 0 || tj == N-1)
					{
						if (td % 2 == 0)
							t_arr[ti][tj] = { tb / 2,td - 1 };
						else
							t_arr[ti][tj] = { tb / 2,td + 1 };
					}
					else
					{
						t_arr[ti][tj] = { tb,td };
						t2_arr[ti][tj] = { tb,td };
					}
				}
				else
				{
					if (t2_arr[ti][tj].b < tb)
					{
						t_arr[ti][tj] = { tb + t_arr[ti][tj].b , td };
						t2_arr[ti][tj] = { tb,td };
					}
					else
					{
						t_arr[ti][tj] = { tb + t_arr[ti][tj].b , t_arr[ti][tj].d };
					}
				}
				
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = t_arr[i][j];
		}
	}
}

void print_arr()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("(%d,%d) ", arr[i][j].b,arr[i][j].d);
		}
		printf("\n");
	}
}

int main()
{
	int t1, t2, t3, t4;
	int T;
	scanf("%d",&T);
	for (int t = 0; t < T; t++)
	{
		arr.clear();
		scanf(" %d %d %d", &N, &M, &K);

		arr.assign(N, vector<bug>(N, {0, 0 }));

		for (int j = 0; j < K; j++)
		{
			scanf(" %d %d %d %d", &t1, &t2, &t3, &t4);
			arr[t1][t2] = { t3,t4 };
		}

		//print_arr();

		for (int j = 0; j < M; j++)
		{
			solve();
		}

		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j].b != 0)
				{
					sum += arr[i][j].b;
					//cout << "test" << endl;
				}
			
			}
		}

		printf("#%d %d\n", t + 1, sum);
	}
}