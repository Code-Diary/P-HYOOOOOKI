#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<deque>
#include<queue>
#include<string.h>

using namespace std;

int t,w, h;
int arr[1001][1001];
int visit[1001][1001];
queue<pair<int, int>> fire;
queue<pair<int, int >> human;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int solution()
{
;	int t_num = 1;


	while(!human.empty())
	{
		int f_size = fire.size();
		for (int i = 0; i < f_size; i++)
		{
			pair<int,int> t_fire = fire.front();
			fire.pop();

			for (int d = 0; d < 4; d++)
			{
				int nr = t_fire.first + dr[d];
				int nc = t_fire.second + dc[d];
				if (nr < h && 0 <= nr && nc < w && 0 <= nc)
				{
					if (arr[nr][nc] == 0)
					{
						arr[nr][nc] = 3;
						fire.push(make_pair(nr, nc));
					}
				}
			}
		}
		
		int h_size = human.size();
		for (int i = 0; i < h_size; i++)
		{
			pair<int, int> t_human = human.front();
			human.pop();
			if (t_human.first == h - 1 || t_human.first == 0 || t_human.second == w - 1 || t_human.second == 0)
			{
				return t_num;
			}
			
			for (int d = 0; d < 4; d++)
			{	
				int nr = t_human.first + dr[d];
				int nc = t_human.second + dc[d];
				if (nr < h && 0 <= nr && nc < w && 0 <= nc)
				{
					if (visit[nr][nc] == 0 && arr[nr][nc] != 1 && arr[nr][nc]!=3)
					{
						visit[nr][nc] = 1;
						human.push(make_pair(nr, nc));
					}
				}
			}
		}
		t_num++;
	}
	return 0;
}

int main()
{
	cin >> t;

	for (int t1 = 0; t1 < t; t1++)
	{
		queue<pair<int, int>> fire_t;
		queue<pair<int, int>> human_t;
		swap(human, human_t);
		swap(fire, fire_t);
		for (int i = 0; i < 1001; i++)
		{
			memset(visit[i], 0, sizeof(int) * 1001);
		}

		cin >> w >> h;
		char temp;
		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> temp;
				if (temp == '.')
					arr[i][j] = 0;
				else if (temp == '#')
					arr[i][j] = 1;
				else if (temp == '@')
				{
					arr[i][j] = 2;
					human.push(make_pair(i, j));
				}
				else if (temp == '*')
				{
					arr[i][j] = 3;
					fire.push(make_pair(i, j));
				}
			}
		}
		int rst = solution();
		if (rst == 0)
		{
			cout << "IMPOSSIBLE" << "\n";
		}
		else
		{
			cout << rst << "\n";
		}
	}
	
	return 0;
}