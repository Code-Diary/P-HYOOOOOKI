#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

int N;
int arr[17][17];
int cnt;
int d_cnt = 0;

void dfs(int d,int r,int c)
{
	//cout << d_cnt++<<" " << d << " " << r << " " << c << " " << endl;
	if (r == N && c == N)
	{
		cnt++;
		return;
	}

	if (d == 0)
	{
		if (c + 1 <= N && arr[r][c+1] == 0)
		{
			dfs(0, r, c + 1);
		}
		if (c + 1 <= N && r + 1 <= N && arr[r + 1][c + 1] == 0 && arr[r][c + 1] == 0 && arr[r + 1][c] == 0)
		{
			dfs(1, r + 1, c + 1);
		}
		return;
	}
	else if(d == 1)
	{
		if (c + 1 <= N && arr[r][c + 1] == 0)
		{
			dfs(0, r, c + 1);
		}
		if (c + 1 <= N && r + 1 <= N && arr[r + 1][c + 1] == 0 && arr[r][c + 1] == 0 && arr[r + 1][c] == 0)
		{
			dfs(1, r + 1, c + 1);
		}
		if (r + 1 <= N && arr[r + 1][c] == 0)
		{
			dfs(2, r + 1, c);
		}
		return;
	}
	else if(d==2)
	{
		if (c + 1 <= N && r + 1 <= N && arr[r + 1][c + 1] == 0 && arr[r][c + 1] == 0 && arr[r + 1][c] == 0)
		{
			dfs(1, r + 1, c + 1);
		}
		if (r + 1 <= N && arr[r + 1][c] == 0)
		{
			dfs(2, r + 1, c );
		}
		return;
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	
	
	cin >> N;
	for (int i =1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	cnt = 0;

	if (arr[1][3] == 1)
	{
		cout << "0" << "\n";
		return 0;
	}

	dfs(0,1,2);

	cout << cnt << "\n";
	
	return 0;

}