#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int arr[1001][1001];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

bool check(int x, int y)
{
	if (x < 0 || N <= x || y < 0 || M <= y)
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}
	int p_i = 0;
	int p_j = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 && check(i-dx[1],i-dy[1]))
			{
				arr[i][j] = arr[i][j] + arr[i-dx[1]][j-dy[1]];
			}
			else if (j == 0 && check(i-dx[0],j-dy[0]))
			{
				arr[i][j] = arr[i][j] + arr[i - dx[0]][j - dy[0]];
			}
			else
			{
				int t=0;
				for (int k = 0; k < 3; k++)
				{
					if(check(i-dx[k],j-dy[k]))
						t = max(t, arr[i - dx[k]][j - dy[k]]);
				}
				arr[i][j] += t;
			}
		}
	}
	
	cout << arr[N - 1][M - 1] << "\n";
	return 0;
}