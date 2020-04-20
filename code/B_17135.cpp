#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>

using namespace std;

int N,M,D;
int cnt;
int juk_num = 0;

void solution(int g1,int g2, int g3, int tarr[][16])
{
	int r1, r2, c1, c2;
	vector<pair<int, int>> juk;
	pair<int, int> temp_j=make_pair(0,0);
	int leng;

	int arr[16][16];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = tarr[i][j];
		}
	}
	
	temp_j = make_pair(1000, 1000);
	for (int k = 0; k < N; k++)
	{
		int sc = g1;
		int sr = N;
		temp_j = make_pair(1000, 1000);
		for (int d = 1; d <= D; d++)
		{
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc - (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
						break;
					}
				}
			}
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc + (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
					}
				}
			}
			if (temp_j.first != 1000)
			{
				juk.push_back(temp_j);
				break;
			}
		}

		sc = g2;
		sr = N;
		temp_j = make_pair(1000, 1000);
		for (int d = 1; d <= D; d++)
		{
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc - (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
						break;
					}
				}
			}
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc + (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
					}
				}
			}
			if (temp_j.first != 1000)
			{
				juk.push_back(temp_j);
				break;
			}
				
		}

		sc = g3;
		sr = N;
		temp_j = make_pair(1000, 1000);
		for (int d = 1; d <= D; d++)
		{
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc - (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
						break;
					}
				}
			}
			for (int i = 1; i <= d; i++)
			{
				int nr = (sr - i);
				int nc = sc + (d - i);
				if (nr < N && 0 <= nr && nc < M && 0 <= nc)
				{
					if (arr[nr][nc] == 1 && nc < temp_j.second)
					{
						temp_j = make_pair(nr, nc);
					}
				}
			}
			if (temp_j.first != 1000)
			{
				juk.push_back(temp_j);
				break;
			}
		}
		for (int i = 0; i < juk.size(); i++)
		{
			if (arr[juk[i].first][juk[i].second] == 1)
			{
				arr[juk[i].first][juk[i].second] = 0;
				cnt++;
			}
			if (juk_num == cnt)
				return;
		}
		juk.clear();

		for (int i = N - 1; 0 < i; i--)
		{
			for (int j = 0; j < M; j++)
			{
				if (0 <= i - 1)
				{
					arr[i][j] = arr[i - 1][j];
					arr[i-1][j] = 0;
				}
			}
		}
	}	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	int arr[16][16];
	
	cnt = 0;
	int result = 0;
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				juk_num++;
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		for (int j = i+1; j < M; j++)
		{
			for (int k = j+1; k < M; k++)
			{
				solution(i, j, k, arr);
				result = max(result, cnt);
				//cout << endl;
				if (result == juk_num)
				{
					cout << result << "\n";
					return 0;
				}
				cnt = 0;
			}
		}
	}
	cout << result << "\n";
	return 0;

}