#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<stack>
#include<utility>
#include<vector>

using namespace std;

int N;
int arr[20][20] = { 0, };
int dx[4] = {1,1,-1,-1 };
int dy[4] = { -1,1,1,-1};
int check[101] = { 0 };
int sx, sy;
int ret = 0;

void solve(int s_x,int s_y,int count, int dir)
{
	if (dir > 3)
		return;

	int cnt = count;

	if (dir == 3 && sx == s_x && sy == s_y)
		ret = max(ret, cnt);

	if (check[arr[s_x][s_y]] == 0)
	{
		check[arr[s_x][s_y]] = 1;
		cnt++;
	}
	else
		return;

	int nx = s_x + dx[dir];
	int ny = s_y + dy[dir];

	if (0 <= nx && 0 <= ny && nx < N && ny < N)
	{
		solve(nx, ny, cnt, dir);
		solve(nx, ny, cnt, dir+1);
	}
	
	check[arr[s_x][s_y]] = 0;
	return;
}


int main()
{
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		scanf(" %d",&N);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %d", &arr[i][j]);
			}
		}
		ret = -1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				memset(check, 0, sizeof(int) * 101);
				sx = i;
				sy = j;
				solve(i, j, 0, 0);
			}
		}
		printf("#%d %d\n", t + 1, ret);
		
	}

}
