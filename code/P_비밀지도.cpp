#include<algorithm>
#include<iostream>
#include <string>
#include <vector>


using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	vector<int> t_arr1(arr1);
	vector<int> t_arr2(arr2);
	vector<int> t_arr3(n, 0);

	for (int i = 0; i < n; i++)
	{
		t_arr3[i] = t_arr1[i] | t_arr2[i];
	}

	string temp="";

	for (int i = 0; i < n; i++)
	{
		temp = "";
		for (int j = 0; j < n; j++)
		{
			if (t_arr3[i] & 1 == 1)
			{
				temp.append("#");
			}
			else
			{
				temp.append(" ");
			}
			t_arr3[i] = t_arr3[i] >> 1;
		}
		reverse(temp.begin(), temp.end());
		answer.push_back(temp);
	}

	return answer;
}
