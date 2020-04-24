#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int n, m;
int r, c, d;
int arr[50][50];
int c_arr[50][50];
int cnt = 0;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void solution(int r1, int c1, int d1)
{
	if (c_arr[r1][c1] == 0)
	{
		c_arr[r1][c1] = 1;
		cnt++;
	}

	bool chk = false;
	int fd = d1;
	int nr;
	int nc;

	for (int i = 0; i < 4; i++)
	{
		if (d1 - 1 < 0)
		{
			d1 = 3;
		}
		else
		{
			d1 = d1 - 1;
		}

		nr = r1 + dr[d1];
		nc = c1 + dc[d1];
		if (nr < n && 0 <= nr && nc < m && 0 <= nc)
		{
			if (arr[nr][nc] == 0 && c_arr[nr][nc] == 0)
			{
				r1 = nr;
				c1 = nc;
				c_arr[nr][nc] = 1;
				cnt++;
				chk = true;
				break;
			}
		}
	}
	if (chk == true)
	{
		solution(r1, c1, d1);
	}
	else
	{
		int td = (fd + 2) % 4;
		if (arr[r1 + dr[td]][c1 + dc[td]] == 0)
		{
			r1 = r1 + dr[td];
			c1 = c1 + dc[td];
			solution(r1, c1, fd);
		}
		else
		{
			return;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m;
	cin >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	solution(r, c, d);

	cout << cnt << endl;
	return 0;
}