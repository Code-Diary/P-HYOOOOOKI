#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string.h>

using namespace std;

int arr[10][10];
int N, M;
pair<int, int> ball[2];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int min_v = 10000;

int solve(int cnt,pair<int,int> *t_arr,int d)
{
	int count = cnt;

	if (10 < count)
	{
		return 20000;
	}
		

	int dir = d;
	pair<int, int> b[2];
	b[0] = t_arr[0];
	b[1] = t_arr[1];
	int chk = 0;

	if (cnt == 0 && dir == 5)
	{
		for (int i = 0; i < 4; i++)
		{
			solve(count+1, b, i);
		}
	}
	else
	{
		int nx0 = b[0].first + dx[dir];
		int ny0 = b[0].second + dy[dir];
		int nx1 = b[1].first + dx[dir];
		int ny1 = b[1].second + dy[dir];

		while (arr[nx0][ny0] != 9 && (nx0 != b[1].first || ny0 != b[1].second))
		{
			if (arr[nx0][ny0] == 5)
			{
				chk = 1;
				break;
			}
			b[0].first = nx0;
			b[0].second = ny0;
			nx0 = b[0].first + dx[dir];
			ny0 = b[0].second + dy[dir];
		}
		while (arr[nx1][ny1] != 9 && (chk == 1 ||(nx1 != b[0].first || ny1 != b[0].second)))
		{
			if (arr[nx1][ny1] == 5)
			{
				return count;
			}
			b[1].first = nx1;
			b[1].second = ny1;
			nx1 = b[1].first + dx[dir];
			ny1 = b[1].second + dy[dir];
		}
		if (chk == 1)
		{
			chk = 0;
			min_v = min(min_v, count);
			return count;
		}
		while (arr[nx0][ny0] != 9 && (nx0 != b[1].first || ny0 != b[1].second))
		{
			if (arr[nx0][ny0] == 5)
			{
				min_v = min(min_v, count);
				return count;
			}
			b[0].first = nx0;
			b[0].second = ny0;
			nx0 = b[0].first + dx[dir];
			ny0 = b[0].second + dy[dir];
		}
		if (dir == 0)
		{
			solve(count + 1, b, 1);
			solve(count + 1, b, 3);
		}
		else if (dir == 1)
		{
			solve(count + 1, b, 0);
			solve(count + 1, b, 2);
		}
		else if (dir == 2)
		{
			solve(count + 1, b, 1);
			solve(count + 1, b, 3);
		}
		else if (dir == 3)
		{
			solve(count + 1, b, 0);
			solve(count + 1, b, 2);
		}
	}
	
	return count;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char temp;
			scanf(" %c", &temp);
			if (temp == '#')
				arr[i][j] = 9;
			else if (temp == '.')
				arr[i][j] = 0;
			else if (temp == 'O')
				arr[i][j] = 5;
			else if (temp == 'R')
			{
				arr[i][j] = 0;
				ball[0] = make_pair(i, j);
			}
			else if (temp == 'B')
			{
				arr[i][j] = 0;
				ball[1] = make_pair(i, j);
			}
		}
	}

	int rst = solve(0, ball, 5);

	if (rst == 20000 || min_v == 10000)
		printf("-1\n");
	else
		printf("%d\n", min_v);
}