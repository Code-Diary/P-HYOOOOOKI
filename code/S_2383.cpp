#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;

int N;

typedef struct stair {
	int stand;
	int wait;
	int dist;
	int x;
	int y;
};

typedef struct person {
	int x;
	int y;
	int st;
	int dist;
};


int arr[10][10] = { 0 };
vector<person> P;
vector<stair> S;
int f_t = 10000;
vector<int> p1;
vector<int> p2;

void init()
{
	for (int i = 0; i < 10; i++)
		memset(arr[i], 0, sizeof(int)*10);
	P.clear();
	S.clear();
	f_t = 10000;
}

bool cmp(const person & a, const person & b)
{
	if (a.dist < b.dist)
		return true;
	else if (a.dist == b.dist)
	{
		if (a.x < b.x) return true;
		else if (a.x == b.x)
		{
			if (a.y < b.y) return true;
			else if (a.y == b.y)
			{
				if (a.st < b.st) return true;
			}
		}
	}
	return false;
}

int sp_dist(int st, int p)
{
	int dist = abs(P[p].x- S[st].x) + abs(P[p].y- S[st].y);
	return dist;
}

int distance()
{
    int arrive_time[11];
    p1.clear();
    p2.clear();

	for (int i = 0; i < P.size(); i++)
	{
		if (P[i].st == 1)
			p1.push_back(i);
		else if(P[i].st == 2)
			p2.push_back(i);
	}

    int s1_time =0;
    int p1_size =(int)p1.size();
    if(p1_size)
    {
        for(int i=0;i<p1_size;i++)
            arrive_time[i] = sp_dist(1,p1[i])+1;
        sort(arrive_time,arrive_time+p1_size);
        for(int i=3;i<p1_size;i++)
            arrive_time[i] = max(arrive_time[i-3]+S[1].dist,arrive_time[i]);
        s1_time = arrive_time[p1_size-1]+S[1].dist;    
    }
    int s2_time =0;
    int p2_size = (int)p2.size();
    if(p2_size)
    {
        for(int i=0;i<p2_size;i++)
            arrive_time[i] = sp_dist(2,p2[i])+1;
        sort(arrive_time,arrive_time+p2_size);
        for(int i=3;i<p2_size;i++)
            arrive_time[i] = max(arrive_time[i-3]+S[2].dist,arrive_time[i]);
        s2_time = arrive_time[p2_size-1]+S[2].dist;    
    }

    int tmp_t = max(s1_time,s2_time);

    return tmp_t;
}

void solve(int size)
{
	if (size == 0)
	{
		int T;
		T = distance();
		
		f_t = min(f_t, T);

		return;
	}

	for (int i = 1; i <= 2; i++)
	{
		P[P.size() - size].st = i;
		solve(size - 1);
	}
}

int main()
{
	int T;
	scanf(" %d", &T);

	for (int t = 0; t < T; t++)
	{
		init();
		scanf(" %d", &N);
		S.push_back({ 0,0,0,0,0 });
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf(" %d", &arr[i][j]);
				if (arr[i][j] == 1)
					P.push_back({ i,j,0,0 });
				else if (1 < arr[i][j])
					S.push_back({0,0,arr[i][j],i,j});
			}
		}
		solve(P.size());

		printf("#%d %d\n", t + 1, f_t);
	}
}