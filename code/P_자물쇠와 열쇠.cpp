#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<utility>

using namespace std;

int M, N;
vector<pair<int, int>> lock_h;
bool answer = false;
vector<vector<int>> r_key1;
vector<vector<int>> r_key2;
vector<vector<int>> r_key3;
vector<vector<int>> r_key4;

vector<vector<int>> rotate(vector<vector<int>> key, vector<vector<int>> r_key)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			r_key[j][M - i - 1] = key[i][j];
		}
	}
	return r_key;
}

bool solution2(vector<vector<int>> r_key, vector<vector<int>> lock)
{
	vector<pair<int, int>> key_l;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (r_key[i][j] == 1)
				key_l.push_back(make_pair(i, j));
		}
	}

	int t = key_l.size();
	int l = lock_h.size();
	int dx = 0;
	int dy = 0;

	if (t < l)
	{
		answer = false;
		return answer;
	}

	int cnt = 0;

	for (int i = 0; i < t; i++)
	{
		dx = lock_h[0].first - key_l[i].first;
		dy = lock_h[0].second - key_l[i].second;		
		for (int j = 0; j < t; j++)
		{
			int tx = key_l[j].first + dx;
			int ty = key_l[j].second + dy;
			if (0 <= tx && tx < N && ty < N && 0 <= ty)
			{
				if (lock[tx][ty] == 1)
				{
					break;
				}
				else
				{
					cnt++;
				}
			}			
		}

		if (cnt == l)
			return true;
		cnt = 0;
	}

	return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {

	M = key.size();
	N = lock.size();

	lock_h.clear();
	answer = false;
	r_key1.clear();
	r_key2.clear();
	r_key3.clear();
	r_key4.clear();

	r_key1.assign(M, vector<int>(M, 0));
	r_key2.assign(M, vector<int>(M, 0));
	r_key3.assign(M, vector<int>(M, 0));
	r_key4.assign(M, vector<int>(M, 0));
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (lock[i][j] == 0)
			{
				lock_h.push_back(make_pair(i, j));
			}
		}
	}

	if (lock_h.size() == 0)
		return true;

	r_key1 = rotate(key, r_key1);
	answer = solution2(r_key1, lock);
	if (answer == true)
		return true;

	r_key2 = rotate(r_key1, r_key2);
	answer = solution2(r_key2, lock);
	if (answer == true)
		return answer;

	r_key3 = rotate(r_key2, r_key3);
	answer = solution2(r_key3, lock);
	if (answer == true)
		return answer;

	r_key4 = rotate(r_key3, r_key4);
	answer = solution2(r_key4, lock);
	if (answer == true)
		return answer;

	return answer;
}