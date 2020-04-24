#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>

using namespace std;
int n, m;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
bool rst=false;
vector<vector<char>> arr;
int fi;
int fj;
int max_cnt;
bool chk;

void solution(int i,int j, vector<vector<bool>> t_visit,char val,int l,int d1)
{	
	if (rst)
		return;

	
	if (max_cnt < l)
		return;
	vector<vector<bool>> visit = t_visit;
	visit[i][j] = true;

	if(d1==-1)
		for (int d = 0; d < 4; d++)
		{
			int nr = i + dr[d];
			int nc = j + dc[d];
			if (nr < n && nc < m && 0 <= nr && 0 <= nc)
			{
				if (!visit[nr][nc] && arr[nr][nc] == val)
				{
					solution(nr, nc, visit, val, l + 1, d);
				}
			}
		}
	else
	{
		for (int d = 0; d < 4; d++)
		{
			if (d != (d1 + 2) % 4)
			{
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr < n && nc < m && 0 <= nr && 0 <= nc)
				{
					if (nr == fi && nc == fj)
					{
						rst = true;
						return;
					}
					if (!visit[nr][nc] && arr[nr][nc] == val)
					{
						solution(nr, nc, visit, val, l + 1, d);
					}
				}
			}
		}
	}
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	
	//while (1)
	//{
		cin >> n >> m;
		max_cnt = n * m;
		arr.assign(n, vector<char>(m));
		vector<vector<bool>> visit(n, vector<bool>(m, false));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		}
		rst = false;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				fi = i;
				fj = j;
				solution(i, j, visit, arr[i][j], 0, -1);
				if (rst)
				{
					cout << "Yes" << "\n";
					return 0;
				//	break;
				}
			}
			//if (rst)
		//		break;
		}

		if (rst == true)
			cout << "Yes" << "\n";
		else
			cout << "No" << "\n";
	//}
	
	return 0;
}