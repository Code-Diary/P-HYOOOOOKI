#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

vector<vector<pair<int, int>>> gene(11);
vector<vector<int>> arr(101, vector<int>(101, 0));

void generation(int g, int d)
{
	gene[0].push_back(make_pair(0, 0));
	if (d == 0)
		gene[0].push_back(make_pair(0, 1));
	else if(d==1)
		gene[0].push_back(make_pair(-1, 0));
	else if (d == 2)
		gene[0].push_back(make_pair(0, -1));
	else if (d == 3)
		gene[0].push_back(make_pair(1, 0));

	for (int i = 0; i < g; i++)
	{
		vector<pair<int, int>> temp;
		for (int j = 0; j < gene[i].size(); j++)
		{
			temp.push_back(make_pair(gene[i][j].second, (-1)*gene[i][j].first));
		}
		int sx = gene[i].back().second - temp.back().second;
		int sy = gene[i].back().first - temp.back().first;

		gene[i + 1] = gene[i];
		for (int j = temp.size()-2; 0<=j; j--)
		{
			gene[i + 1].push_back(make_pair(temp[j].first + sy, temp[j].second + sx));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	int x, y, d, g;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x >> y >> d >> g;
		
		for (int j = 0; j < 11; j++)
		{
			gene[j].clear();
		}
		
		generation(g, d);

		for (int j = 0; j < gene[g].size(); j++)
		{
			//cout << gene[g][j].first << " " << gene[g][j].second << endl;
			if(y + gene[g][j].first < 101 && -1<y + gene[g][j].first&& x + gene[g][j].second < 101 && -1<x + gene[g][j].second)
				arr[y + gene[g][j].first][x + gene[g][j].second] = 1;
		}
	}

	int cnt = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1)
			{
				cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}