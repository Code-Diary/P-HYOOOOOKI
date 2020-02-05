#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int N, M, R, C, L;
int result;
vector<vector<int>> arr;
vector<vector<int>> v_arr;
int pipe[7][4] = { {1,1,1,1},{0,1,0,1},{1,0,1,0},{0,1,1,0},{0,0,1,1},{1,0,0,1},{1,1,0,0} };
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int r_val[4] = { 2,3,0,1 };
int all_t = 0;

bool check(int v1, int v2)
{
	if (v1 < 0 || N <= v1 || v2 < 0 || M <= v2)
		return false;
	return true;
}

void bfs()
{
	int cnt = 0;
	queue<pair<int, int>> Q;
	Q.push(make_pair(R, C));

	int f_val = R;
	int s_val = C;

	while (!Q.empty())
	{
		if (L <= all_t)
			break;
		int q_size = Q.size();

		for (int i = 0; i < q_size; i++)
		{
			f_val = Q.front().first;
			s_val = Q.front().second;
			Q.pop();

			if (v_arr[f_val][s_val] == 0)
			{
				v_arr[f_val][s_val] = 1;
				cnt++;

				for (int j = 0; j < 4; j++)
				{
					if (pipe[arr[f_val][s_val] - 1][j])
					{
						if (check(f_val + dx[j], s_val + dy[j]) && (pipe[arr[f_val + dx[j]][s_val + dy[j]] - 1][r_val[j]]))
						{
							Q.push(make_pair(f_val + dx[j], s_val + dy[j]));
						}
					}
				}
			}

			
		}
		all_t++;	
	}

	result = cnt;

}

int main()
{
	int T;
	scanf(" %d", &T);
	
	for (int i = 0; i < T; i++)
	{
		arr.clear();
		v_arr.clear();
		all_t = 0;
		result = 0;
		scanf(" %d %d %d %d %d", &N, &M, &R, &C, &L);
		arr.assign(N, vector<int>(M, 0));
		v_arr.assign(N, vector<int>(M, 0));
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				scanf(" %d", &arr[j][k]);
			}
		}
		bfs();
		printf("#%d %d\n", i + 1, result);
	}

}