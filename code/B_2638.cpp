#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

using namespace std;

int n, m;
int arr[100][100];
vector<vector<int>> visit;
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };

int cheeze = 0;

void bfs(int r,int c)
{
	queue<pair<int, int>> q;

	q.push({r, c});
	visit[r][c] = 1;

	while (!q.empty())
	{
		int s_r = q.front().first;
		int s_c = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (s_r + dr[i] < 0 || n - 1 < s_r + dr[i] || s_c + dc[i] < 0 || m - 1 < s_c + dc[i])
				continue;

			int temp = arr[s_r + dr[i]][s_c + dc[i]];
			if (temp == 0 && visit[s_r + dr[i]][s_c + dc[i]] != 1)
			{
				q.push({ s_r + dr[i] ,s_c + dc[i] });
				visit[s_r + dr[i]][s_c + dc[i]]=1;
			}
		}
	}

	return;
}

void solution()
{
	vector<pair<int, int>> chk;
	for (int i = 1; i < n-1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if (arr[i][j] == 1)
			{
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					int nr = i + dr[d];
					int nc = j + dc[d];

					if (nr < 0 || n - 1 < nr || nc < 0 || m - 1 < nc)
						continue;

					if (arr[nr][nc] == 0 && visit[nr][nc]==1)
						cnt++;
				}
				if (2 <= cnt)
					chk.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < chk.size(); i++)
	{
		arr[chk[i].first][chk[i].second] = 0;
	}
	
	cheeze = cheeze - chk.size();
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;

	vector<vector<int>> init;
	init.assign(n, vector<int>(m, 0));

	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			if (temp == 1)
				cheeze += 1;
			arr[i][j] = temp;
		}
	}

	visit.assign(n, vector<int>(m, 0));

	int count = 0;

	while (1)
	{
		count++;
		bfs(0, 0);
		solution();
		if (cheeze == 0)
			break;
		visit = init;
	}

	cout << count << "\n";
	
	return 0;
}