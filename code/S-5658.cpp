#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<deque>
#include<string>

using namespace std;

int T;
int N, K;
deque<char> arr;
vector<string> arr_s;

/*
deque를 이용하여 배열을 상대적으로 쉽게 돌렸음!!
*/

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		
		scanf("%d %d", &N, &K);
		arr.resize(N,'0');
		arr_s.resize(0, "");
		for (int j = 0; j < N; j++)
		{
			scanf(" %1c",&arr[j]);
		}
		int length = N / 4;
		
		for (int n = 0; n < length; n++)
		{
			for (int j = 0; j < 4; j++)
			{
				string temp = "";
				for (int k = 0; k < length; k++)
				{
					temp += arr[k + (j*length)];
				}
				if (find(arr_s.begin(), arr_s.end(), temp) == arr_s.end())
				{
					arr_s.push_back(temp);
				}
			}
			char temp = arr.front();
			arr.pop_front();
			arr.push_back(temp);
		}
		sort(arr_s.begin(), arr_s.end());
		
		string temp = arr_s[arr_s.size() - K];
		long long result = 0;
		int count=0;
		for (int j = length-1; 0 <= j; j--)
		{
			if (48 <= temp[j] && temp[j] <= 57)
				result += (temp[j] - 48)*pow(16, count++);
			else
				result += (temp[j] - 55)*pow(16, count++);
		}
		printf("#%d %lld\n", i + 1, result);
	}
}