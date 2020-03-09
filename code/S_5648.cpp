#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int N;
int arr[4001][4001];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

typedef struct ele {
	int x;
	int y;
	int k; //energy
	int dir; //direction
	bool st; //state
};

vector<ele> element;

int total_e = 0;

void init()
{
	total_e = 0;
	element.clear();
}

bool check()
{
	for (int i = 0; i < element.size(); i++)
	{
		if (element[i].st == true)
			return true;
	}
	return false;
}

void solve()
{
	while (check() != false)
	{
		for (int i = 0; i < element.size(); i++)
		{
			if (element[i].st == false)
				continue;
			int t_x = element[i].x + dx[element[i].dir];
			int t_y = element[i].y + dy[element[i].dir];
			if (t_x <= 4000 && 0 <= t_x && t_y <= 4000 && 0 <= t_y)
			{
				arr[element[i].x][element[i].y] = 0;
				arr[t_x][t_y]++;
				element[i].x = t_x;
				element[i].y = t_y;
			}
			else
			{
				element[i].st = false;
				arr[element[i].x][element[i].y] = 0;
			}
			
				
		}

		for (int i = 0; i < element.size(); i++)
		{
			if (element[i].st == true && 2 <= arr[element[i].x][element[i].y])
			{
				for (int j = i + 1; j < element.size(); j++)
				{
					if (element[j].st == true && element[i].x == element[j].x && element[i].y == element[j].y)
					{
						total_e = total_e + element[j].k;
						element[j].st = false;
					}
				}
				total_e += element[i].k;
				element[i].st = false;
				arr[element[i].x][element[i].y] = 0;
			}
		}
	}

	
}



int main()
{
	int T;
	
	scanf(" %d", &T);

	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d", &N);
		for (int i = 0; i < N; i++)
		{
			int x,y,k,dir;
			scanf(" %d %d %d %d", &x, &y, &dir, &k);
			element.push_back({(x+1000)*2,(y+1000)*2,k,dir,true});
		}

		solve();

		printf("#%d %d\n", t + 1, total_e);
	}
}