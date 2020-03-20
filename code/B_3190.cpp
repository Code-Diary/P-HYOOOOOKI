#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

int N, K, L;
int arr[102][102];
queue<pair<int, int>> turn;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

typedef struct sna
{
	int x;
	int y;
	int dir;
};

vector<sna> snake;

bool check(int x, int y)
{
	if (x < 0 || x > N - 1 || y < 0 || y > N - 1)
	{
		return true;
	}
	else
		return false;
}

int solve()
{
	int n_x = 0;
	int n_y = 0;
	int d = 0;
	int o_d = 0;
	int cnt = 0;
	int temp1;
	int temp2;
	int temp3;
	int temp4;

	while (!check(n_x, n_y))
	{
		n_x = snake[0].x + dx[d];
		n_y = snake[0].y + dy[d];
		cnt++;

		for (int i = 0; i < snake.size(); i++)
		{
			if (snake[i].x == n_x && snake[i].y == n_y)
				return cnt;
		}

		if (arr[n_x][n_y] == 1)
		{
			snake.push_back({ 0,0,0 });

			temp1 = snake[1].x;
			temp2 = snake[1].y;
			snake[1].x = snake[0].x;
			snake[1].y = snake[0].y;
			snake[0].x = n_x;
			snake[0].y = n_y;

			for (int i = 1; i < snake.size() - 1; i++)
			{
				temp3 = snake[i + 1].x;
				temp4 = snake[i + 1].y;
				snake[i + 1].x = temp1;
				snake[i + 1].y = temp2;
				temp1 = temp3;
				temp2 = temp4;
			}
			arr[n_x][n_y] = 0;
		}
		else
		{
			temp1 = snake[0].x;
			temp2 = snake[0].y;
			snake[0].x = n_x;
			snake[0].y = n_y;

			for (int i = 0; i < snake.size() - 1; i++)
			{
				temp3 = snake[i + 1].x;
				temp4 = snake[i + 1].y;
				snake[i + 1].x = temp1;
				snake[i + 1].y = temp2;
				temp1 = temp3;
				temp2 = temp4;
			}

		}


		if (!turn.empty() && cnt == turn.front().first)
		{
			if (turn.front().second == 0)
			{
				if (d == 0)
					d = 3;
				else if (d == 1)
					d = 0;
				else if (d == 2)
					d = 1;
				else if (d == 3)
					d = 2;
			}
			else
			{
				if (d == 0)
					d = 1;
				else if (d == 1)
					d = 2;
				else if (d == 2)
					d = 3;
				else if (d == 3)
					d = 0;
			}
			turn.pop();
		}
	}
	return cnt;

}


int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++)
	{
		int x, y;
		scanf(" %d %d", &x, &y);
		arr[x - 1][y - 1] = 1;
	}
	scanf(" %d", &L);
	for (int i = 0; i < L; i++)
	{
		int x;
		char y;
		scanf(" %d %c", &x, &y);
		if (y == 'L')
			turn.push(make_pair(x, 0));
		else
			turn.push(make_pair(x, 1));
	}

	snake.push_back({ 0,0,0 });

	int result = solve();

	printf("%d\n", result);
}