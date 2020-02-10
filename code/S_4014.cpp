#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> arr;
int T, N, X;
int result = 0;

void check()
{
	int temp1, temp2;
	int count1, count2;
	int num=0;
	bool chk = true;
	bool mid_chk = false;

	
	for (int i = 0; i < N; i++)
	{
		chk = true;
		temp1 = arr[i][0];
		count1 = 1;
		mid_chk = false;
		for (int j = 1; j < N; j++)
		{	
			if (2 <= abs(temp1 - arr[i][j]))
			{
				chk = false;
				break;
			}
			
			if (temp1 == arr[i][j])
			{
				count1++;
				if (mid_chk == true && X <= count1)
				{
					mid_chk = false;
					count1 = 0;
				}
			}
			else if(temp1 != arr[i][j] && mid_chk == false)
			{
				if (temp1 < arr[i][j]) //앞으로 높은게 나옴
				{
					if (count1 < X)
					{
						chk = false;
						break;
					}
					count1 = 1;
				}
				else //앞으로 낮은게 나옴
				{
					count1 = 1;
					mid_chk = true;
				}
			}
			else if (temp1 != arr[i][j] && mid_chk == true)
			{
				chk = false;
				break;
			}
			temp1 = arr[i][j];
		}
		if (chk == true && mid_chk == false)
			num++;
	}

	for (int i = 0; i < N; i++)
	{
		chk = true;
		temp1 = arr[0][i];
		count1 = 1;
		mid_chk = false;
		for (int j = 1; j < N; j++)
		{
			if (2 <= abs(temp1 - arr[j][i]))
			{
				chk = false;
				break;
			}

			if (temp1 == arr[j][i])
			{
				count1++;
				if (mid_chk == true && X <= count1)
				{
					mid_chk = false;
					count1 = 0;
				}
			}
			else if (temp1 != arr[j][i] &&  mid_chk == false)
			{
				if (temp1 < arr[j][i]) //앞으로 높은게 나옴
				{
					if (count1 < X)
					{
						chk = false;
						break;
					}
					count1 = 1;
				}
				else //앞으로 낮은게 나옴
				{
					count1 = 1;
					mid_chk = true;
				}
			}
			else if (temp1 != arr[j][i] && mid_chk == true)
			{
				chk = false;
				break;
			}
			temp1 = arr[j][i];
		}
		if (chk == true && mid_chk == false)
			num++;
	}
	result = num;
}

int main()
{
	scanf(" %d", &T);
	for (int t = 0; t < T; t++)
	{
		arr.clear();
		scanf(" %d %d", &N,&X);
		
		arr.assign(N, vector<int>(N, 0));
		
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				scanf(" %d", &arr[i][j]);
		
		check();
		printf("#%d %d\n",t+1, result);
	}
}