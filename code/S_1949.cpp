#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

vector<vector<int>> arr;
int T, N, K;
int max_num = 0;
int result = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void search(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push(make_pair(x, y));
	int count = 0;

	while (!Q.empty())
	{
		int qsize = Q.size();
		for (int l = 0; l < qsize; l++)
		{
			int temp_x = Q.front().first;
			int temp_y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				if (((temp_x + dx[i]) >= 0 && (temp_y + dy[i]) >= 0) && ((temp_x + dx[i]) < N && (temp_y + dy[i]) < N))
				{
					if (arr[temp_x + dx[i]][temp_y + dy[i]] < arr[temp_x][temp_y])
					{
						Q.push(make_pair(temp_x + dx[i], temp_y + dy[i]));
					}
				}
			}
		}
		count++;
	}
	
	if (result < count)
		result = count;

}


int main()
{
	scanf(" %d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf(" %d %d", &N, &K);
		arr.clear();
		max_num = 0;
		result = 0;
		arr.assign(N,vector<int>(N,0));

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf(" %d", &arr[j][k]);
				if (arr[j][k] > max_num)
				{
					max_num = arr[j][k];
				}
			}
		}
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if (arr[j][k] < max_num) continue;
				
				for (int m = 0; m < N; m++)
				{
					for (int n = 0; n < N; n++)
					{
						if (m == j && n == k) continue;
						
						for (int c = 0; c <= K; c++)
						{
							if ((arr[m][n] - c) < 0)
								break;
							int tmp_val = arr[m][n];
							arr[m][n] = arr[m][n] - c;
							search(j, k);
							arr[m][n] = tmp_val;	
						}
					}
				}
			}
		}
		printf("#%d %d\n", i + 1, result);
	}
}