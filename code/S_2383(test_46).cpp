#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string.h>

using namespace std;


int arr[10][10] = { 0, };
int N;
int max_v = 0;
int s1, s2;

vector<pair<int, int>> P;
vector<pair<int, int>> S;

typedef struct team
{
	int x;
	int y;
	int sd;
	int s;
};

vector<team> t1;
vector<team> t2;

vector<team> wait1;
vector<team> wait2;
vector<team> fin1;
vector<team> fin2;

int check[10][10] = { 0, };


void init()
{
	for (int i = 0; i < 10; i++)
	{
		memset(arr[i], 0, sizeof(int) * 10);
		memset(check[i], 0, sizeof(int) * 10);
	}
	P.clear();
	S.clear();
	max_v = 0;
	t1.clear();
	t2.clear();
	wait1.clear();
	wait2.clear();
	fin1.clear();
	fin2.clear();
}

bool cmp(const team & a, const team & b)
{
	if (a.sd < b.sd)
		return true;
	else if (a.sd == b.sd)
	{
		if (a.x < b.x) return true;
		else if (a.x == b.x)
		{
			if (a.y < b.y) return true;
			else if (a.y == b.y)
			{
				if (a.s < b.s) return true;
			}
		}
	}
	return false;
}

void solve()
{
	int t = 0;
	int t_1 = 0;
	int t_2 = 0;
	int cnt = 0;

	for (int i = 0; i < t1.size(); i++)
	{
		if (check[t1[i].x][t1[i].y] == 0)
		{
			check[t1[i].x][t1[i].y] = 1;
			if (t1[i].s == s1)
			{
				int temp = abs(t1[i].x - S[1].first) + abs(t1[i].y - S[1].second) + 1 + s2;
				int temp2 = abs(t1[i].x - S[1].first) + abs(t1[i].y - S[1].second) + 1;
				if (wait1.size() < 3)
				{
					if (wait2.size() < 3)
					{
						if (temp < t1[i].sd + 1 + s1)
						{
							wait2.push_back({t1[i].x,t1[i].y,temp,s2});
							continue;
						}
					}
					else if (wait2.size() == 3)
					{
						if (temp2 <= wait2[t_2].sd)
						{
							if (wait2[t_2].sd + s2 < t1[i].sd + 1 + s1)
							{
								wait2[t_2++] = { t1[i].x,t1[i].y,wait2[t_2].sd + s2,s2 };
								if (t_2 == 3)
									t_2 = t_2 % 3;
								continue;
							}
						}
						else
						{
							if (temp2 + s2 < t1[i].sd + 1 + s1)
							{
								wait2[t_2++] = { t1[i].x,t1[i].y,temp2 + s2,s2 };
								if (t_2 == 3)
									t_2 = t_2 % 3;
								continue;
							}
						}
					}
					wait1.push_back({ t1[i].x,t1[i].y,t1[i].sd + 1 + s1,s1 });
				}
				else if (wait1.size() == 3)
				{
					if (t_1 == 3)
						t_1 = t_1 % 3;
					if (t1[i].sd + 1 <= wait1[t_1].sd)
					{
						if (wait2.size() < 3)
						{
							if (temp < wait1[t_1].sd + s1)
							{
								wait2.push_back({ t1[i].x,t1[i].y,temp,s2 });
								continue;
							}
						}
						else if (wait2.size() == 3)
						{
							if (temp2 <= wait2[t_2].sd)
							{
								if (wait2[t_2].sd + s2 < wait1[t_1].sd + s1)
								{
									wait2[t_2++] = { t1[i].x,t1[i].y,wait2[t_2].sd + s2,s2 };
									if (t_2 == 3)
										t_2 = t_2 % 3;
									continue;
								}
							}
							else
							{
								if (temp2 + s2 < wait1[t_1].sd + s1)
								{
									wait2[t_2++] = { t1[i].x,t1[i].y,temp2 + s2,s2 };
									if (t_2 == 3)
										t_2 = t_2 % 3;
									continue;
								}
							}
						}
						wait1[t_1] = { t1[i].x,t1[i].y,wait1[t_1].sd + s1,s1 };
					}
					else
					{
						if (wait2.size() < 3)
						{
							if (temp < t1[i].sd + 1 + s1)
							{
								wait2.push_back({ t1[i].x,t1[i].y,temp,s2 });
								continue;
							}
						}
						else if (wait2.size() == 3)
						{
							if (temp2 <= wait2[t_2].sd)
							{
								if (wait2[t_2].sd + s2 < t1[i].sd + 1 + s1)
								{
									wait2[t_2++] = { t1[i].x,t1[i].y,wait2[t_2].sd + s2,s2 };
									if (t_2 == 3)
										t_2 = t_2 % 3;
									continue;
								}
							}
							else
							{
								if (temp2 + s2 < t1[i].sd + 1 + s1)
								{
									wait2[t_2++] = { t1[i].x,t1[i].y,temp2 + s2,s2 };
									if (t_2 == 3)
										t_2 = t_2 % 3;
									continue;
								}
							}
						}
						wait1[t_1] = { t1[i].x,t1[i].y,t1[i].sd + s1 + 1,s1 };
					}
					t_1++;
				}
			}
			else
			{
				int temp = abs(t1[i].x - S[0].first) + abs(t1[i].y - S[0].second) + 1 + s1;
				int temp2 = abs(t1[i].x - S[0].first) + abs(t1[i].y - S[0].second) + 1;
				if (wait2.size() < 3)
				{
					if (wait1.size() < 3)
					{
						if (temp < t1[i].sd + 1 + s2)
						{
							wait1.push_back({ t1[i].x,t1[i].y,temp,s1 });
							continue;
						}
					}
					else if(wait1.size() == 3)
					{ 
						if (temp2 <= wait1[t_1].sd)
						{
							if (wait1[t_1].sd + s1 < t1[i].sd + 1 + s2)
							{
								wait1[t_1++] = { t1[i].x,t1[i].y,wait1[t_1].sd + s1,s1 };
								if (t_1 == 3)
									t_1 = t_1 % 3;
								continue;
							}
						}
						else
						{
							if (temp2 + s1 < t1[i].sd + 1 + s2)
							{
								wait1[t_1++] = { t1[i].x,t1[i].y,temp2 + s1,s1 };
								if (t_1 == 3)
									t_1 = t_1 % 3;
								continue;
							}
						}
					}
					wait2.push_back({ t1[i].x,t1[i].y,t1[i].sd + 1 + s2,s2 });
				}
				else if (wait2.size() == 3)
				{
					if (t_2 == 3)
						t_2 = t_2 % 3;

					if (t1[i].sd + 1 <= wait2[t_2].sd)
					{
						if (wait1.size() < 3)
						{
							if (temp < wait2[t_2].sd + s2)
							{
								wait1.push_back({ t1[i].x,t1[i].y,temp,s1 });
								continue;
							}
						}
						else if (wait1.size() == 3)
						{
							if (temp2 <= wait1[t_1].sd)
							{
								if (wait1[t_1].sd + s1 < wait2[t_2].sd + s2)
								{
									wait1[t_1++] = { t1[i].x,t1[i].y,wait1[t_1].sd + s1,s1 };
									if (t_1 == 3)
										t_1 = t_1 % 3;
									continue;
								}
							}
							else
							{
								if (temp2 + s1 < wait2[t_2].sd + s2)
								{
									wait1[t_1++] = { t1[i].x,t1[i].y,temp2 + s1,s1 };
									if (t_1 == 3)
										t_1 = t_1 % 3;
									continue;
								}
							}
						}

						wait2[t_2] = { t1[i].x,t1[i].y,wait2[t_2].sd + s2,s2 };
					}
					else
					{
						if (wait1.size() < 3)
						{
							if (temp < t1[i].sd + 1 + s2)
							{
								wait1.push_back({ t1[i].x,t1[i].y,temp,s1 });
								continue;
							}
						}
						else if (wait1.size() == 3)
						{
							if (temp2 <= wait1[t_1].sd)
							{
								if (wait1[t_1].sd + s1 < t1[i].sd + 1 + s2)
								{
									wait1[t_1++] = { t1[i].x,t1[i].y,wait1[t_1].sd + s1,s1 };
									if (t_1 == 3)
										t_1 = t_1 % 3;
									continue;
								}
							}
							else
							{
								if (temp2 + s1 < t1[i].sd + 1 + s2)
								{
									wait1[t_1++] = { t1[i].x,t1[i].y,temp2 + s1,s1 };
									if (t_1 == 3)
										t_1 = t_1 % 3;
									continue;
								}
							}
						}
						wait2[t_2] = { t1[i].x,t1[i].y,t1[i].sd + s2 + 1,s2 };
					}
						
					t_2++;
				}
			}
		}
	}

	int max_1 = 0;
	int max_2 = 0;
	for (int i = 0; i < wait1.size(); i++)
	{
		max_1 = max(max_1, wait1[i].sd);
	}
	for (int i = 0; i < wait2.size(); i++)
	{
		max_2 = max(max_2, wait2[i].sd);
	}

	max_v = max(max_1, max_2);
}


int main()
{
	int T;
	scanf(" %d", &T);

	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d", &N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %d", &arr[i][j]);
				if (arr[i][j] == 1)
					P.push_back(make_pair(i, j));
				else if (1 < arr[i][j])
					S.push_back(make_pair(i, j));
			}
		}
		s1 = arr[S[0].first][S[0].second];
		s2 = arr[S[1].first][S[1].second];
		for (int i = 0; i < P.size(); i++)
		{
			int sd1 = abs(P[i].first - S[0].first) + abs(P[i].second - S[0].second);
			int sd2 = abs(P[i].first - S[1].first) + abs(P[i].second - S[1].second);

			t1.push_back({ P[i].first,P[i].second,sd1,s1 });
			t1.push_back({ P[i].first,P[i].second,sd2,s2 });
		}
		

		sort(t1.begin(), t1.end(), cmp);

		solve();

		printf("#%d %d\n", t + 1, max_v);
	}
	return 0;
}