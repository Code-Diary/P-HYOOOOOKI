#include<stdio.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

bool check(int m,int n, int x,int y)
{
	if (m <= x || x < 0 || n <= y || y < 0)
		return false;
	return true;
}

int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	vector<vector<pair<int, int>>> t_map(m, vector<pair<int, int>>(n, make_pair(0, 0)));



	for (int i = 1; i < m; i++)
	{
		if (city_map[i][0] != 1)
			t_map[i][0].second = 1;
		else
			break;
	}
	for (int j = 1; j < n; j++)
	{
		if (city_map[0][j] != 1)
			t_map[0][j].first = 1;
		else
			break;
	}

	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (city_map[i][j] == 0 || city_map[i][j] == 2)
			{
				if (check(m, n, i, j - 1))
					if (city_map[i][j - 1] == 0)
						t_map[i][j].first = (t_map[i][j - 1].first + t_map[i][j - 1].second) % 20170805;
					else if (city_map[i][j - 1] == 2)
						t_map[i][j].first = t_map[i][j - 1].first % 20170805;

				if (check(m, n, i-1, j))
					if (city_map[i-1][j] == 0)
						t_map[i][j].second = (t_map[i-1][j].first + t_map[i-1][j].second) % 20170805;
					else if (city_map[i-1][j] == 2)
						t_map[i][j].second = t_map[i-1][j].second % 20170805;
			}
		}
	}
	answer = (t_map[m - 1][n - 1].first + t_map[m - 1][n - 1].second)% 20170805;

	return answer;
}
