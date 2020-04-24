#include<algorithm>
#include<iostream>
#include<utility>
#include<vector>
#include<deque>

using namespace std;

typedef struct fish {
	int r;
	int c;
	int s;
	int d;
	int z;
};

int x, y, m;

vector<fish> shark;
deque<int> arr[101][101];
int cnt = 0;

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

void solution(int loc)
{
	//shark fishing
	for (int i = 0; i < x; i++)
	{
		if (arr[i][loc].size() == 1)
		{
			int tr = shark[arr[i][loc][0]].r;
			int tc = shark[arr[i][loc][0]].c;
			int tz = shark[arr[i][loc][0]].z;
			cnt += tz;

			shark[arr[i][loc][0]] = { -1,-1,0,0,0 };
			arr[i][loc].clear();

			break;
		}
	}

	//shark move
	for (int i = 0; i < m; i++)
	{
		if (shark[i].r == -1)
			continue;

		int tr = shark[i].r;
		int tc = shark[i].c;
		int ts = shark[i].s;
		int td = shark[i].d;
		int tz = shark[i].z;

		arr[tr][tc].pop_front();
		
		int move_cnt = ts;
		int move;

		while (move_cnt)
		{
			if (td == 1)
			{
				move=min(tr, move_cnt);
				tr = tr - move;
				if(tr == 0)
					td = 2;
				move_cnt -= move;
				
			}
			else if (td == 2)
			{
				move = min(x - tr - 1, move_cnt);
				tr = tr + move;
				if(tr == x-1)
					td = 1;
				move_cnt -= move;
			}
			else if (td == 3)
			{
				move = min(y-1-tc,move_cnt);
				tc = tc + move;
				if (tc == y - 1)
					td = 4;
				move_cnt -= move;
			}
			else if (td == 4)
			{
				move = min(tc, move_cnt);
				tc = tc - move;
				if(tc == 0)
					td = 3;
				move_cnt -= move;	
			}
		}

		shark[i] = { tr,tc,ts,td,tz };
		arr[tr][tc].push_back(i);
	}

	for (int t = 0; t < m; t++)
	{
		if (shark[t].r == -1)
			continue;
		
		int i = shark[t].r;
		int j = shark[t].c;
		int ts = arr[i][j].size();

		if (1 < ts)
		{
			int max_z = shark[arr[i][j][0]].z;
			int temp = 0;
			int max_n = arr[i][j][0];
			for (int k = 1; k < ts; k++)
			{
				temp = max_z;
				max_z = max(shark[arr[i][j][k]].z, max_z);
				if (max_z != temp)
				{
					shark[max_n] = { -1,-1,0,0,0 };
					max_n = arr[i][j][k];
				}
				else
				{
					shark[arr[i][j][k]] = { -1,-1,0,0,0 };
				}
			}
			arr[i][j].clear();
			arr[i][j].push_back(max_n);
		}
	}


}

int main()
{

	cin >> x >> y >> m;

	if (m == 0)
	{
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < m; i++)
	{
		int t1, t2, t3, t4, t5;
		cin >> t1 >> t2 >> t3 >> t4 >> t5;

		shark.push_back({ t1 - 1,t2 - 1,t3,t4,t5 });
		arr[t1 - 1][t2 - 1].push_back(i);
	}

	for (int i = 0; i < y; i++)
		solution(i);

	cout << cnt << "\n";
	return 0;
}