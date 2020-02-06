#include<stdio.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<iostream>

using namespace std;

int T, M, A, C, P;
vector<int> move1(101, 0);
vector<int> move2(101, 0);
//0~M까지 이동경로

pair<int, int> user1;
pair<int, int> user2;
//user의 현재위치 (col, row)

int dr[5] = { 0,-1,0,1,0 };
int dc[5] = { 0,0,1,0,-1 };

struct battery {
	int col;
	int row;
	int cover;
	int power;
};

vector<battery> bat;

vector<vector<vector<int>>> arr;

int result;

int main()
{
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		result = 0;
		move1.clear();
		move2.clear();
		arr.clear();
		bat.clear();

		move1.assign(101, 0);
		move2.assign(101, 0);
		arr.assign(10, vector<vector<int>>(10, vector<int>(0)));
		bat.assign(8, {0,0,0,0});


		scanf(" %d %d", &M, &A);
		for (int i = 1; i <= M; i++)
		{
			scanf(" %d", &move1[i]);
		}
		for (int i = 1; i <= M; i++)
		{
			scanf(" %d", &move2[i]);
		}
		for (int i = 0; i < A; i++)
		{
			scanf(" %d %d %d %d", &bat[i].col, &bat[i].row, &bat[i].cover, &bat[i].power);

			int row_1 = bat[i].row-1 - bat[i].cover;
			int row_2 = bat[i].row-1 + bat[i].cover;
			int col_1 = bat[i].col-1 - bat[i].cover;
			int col_2 = bat[i].col-1 + bat[i].cover;

			for (int j = row_1; j <= row_2; j++)
			{
				for (int k = col_1; k <= col_2; k++)
				{
					if (j < 0 || 10 <= j || k < 0 || 10 <= k)
						continue;
					int temp = abs(bat[i].row-1 - j) + abs(bat[i].col-1 - k);
					if (temp <= bat[i].cover)
						arr[j][k].push_back(i);
				}
			}
		}


		for (int i = 0; i <= M; i++)
		{
			int tmp = 0;

			if (i == 0)
			{
				user1 = make_pair(0, 0);
				user2 = make_pair(9, 9);
			}
			else
			{
				user1.first += dc[move1[i]];
				user1.second += dr[move1[i]];
				user2.first += dc[move2[i]];
				user2.second += dr[move2[i]];
			}

			if (arr[user1.second][user1.first].empty() || arr[user2.second][user2.first].empty())
			{
				for (int b = 0; b < arr[user1.second][user1.first].size(); b++)
				{
					tmp = max(tmp, bat[arr[user1.second][user1.first][b]].power);
				}
				for (int b = 0; b < arr[user2.second][user2.first].size(); b++)
				{
					tmp = max(tmp, bat[arr[user2.second][user2.first][b]].power);
				}
			}
			else
			{
				for (int b = 0; b < arr[user1.second][user1.first].size(); b++)
				{
					for (int c = 0; c < arr[user2.second][user2.first].size(); c++)
					{
						int t1 = arr[user1.second][user1.first][b];
						int t2 = arr[user2.second][user2.first][c];

						if (t1 == t2)
						{
							tmp = max(tmp, bat[t1].power);
						}
						else
						{
							tmp = max(tmp, bat[t1].power + bat[t2].power);
						}
					}
				}
			}
			result += tmp;
		}

		printf("#%d %d\n", t + 1, result);
	}
}