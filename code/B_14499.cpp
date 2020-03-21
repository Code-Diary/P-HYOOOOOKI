#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int N, M, x, y, K;
int arr[20][20];
vector<int> move;
pair<int, int> cube;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };
int top = 1;
int bottom = 6;
int cube_n[7] = {0,0,0,0,0,0,0};

bool check(int cx, int cy)
{
	if (cx < 0 || N <= cx || cy < 0 || M <= cy)
		return true;
	return false;
}

void moving(int d)
{
	int t[7];
	for (int i = 0; i < 7; i++)
		t[i] = cube_n[i];

	if (d == 1)
	{
		cube_n[1] = t[4];
		cube_n[2] = t[2];
		cube_n[3] = t[1];
		cube_n[4] = t[6];
		cube_n[5] = t[5];
		cube_n[6] = t[3];
	}
	else if (d == 2)
	{
		cube_n[1] = t[3];
		cube_n[2] = t[2];
		cube_n[3] = t[6];
		cube_n[4] = t[1];
		cube_n[5] = t[5];
		cube_n[6] = t[4];
	}
	else if (d == 3)
	{
		cube_n[1] = t[5];
		cube_n[2] = t[1];
		cube_n[3] = t[3];
		cube_n[4] = t[4];
		cube_n[5] = t[6];
		cube_n[6] = t[2];
	}
	else if (d == 4)
	{
		cube_n[1] = t[2];
		cube_n[2] = t[6];
		cube_n[3] = t[3];
		cube_n[4] = t[4];
		cube_n[5] = t[1];
		cube_n[6] = t[5];
	}

	
}

int main()
{
	cin >> N >> M >> x >> y >> K;
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;

		x = x + dx[temp];
		y = y + dy[temp];

		if (!check(x, y))
		{
			moving(temp);
			if (arr[x][y] == 0)
			{
				arr[x][y]= cube_n[6];
			}
			else
			{
				cube_n[6] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << cube_n[1] << endl;
		}
		else
		{
			x = x - dx[temp];
			y = y - dy[temp];
		}
	}
}